//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "c8051F360.h"
#include "compiler_defs.h"
#include "alpabet.h"

//-----------------------------------------------------------------------------
// Global CONSTANTS
//-----------------------------------------------------------------------------
#define SYSCLK 3062500

sbit CLK = P2^7;
sbit CLR = P1^7;
sbit TTT = P2^0;


unsigned char max_letters = 10;
unsigned char word [10];
int delta_pos = 0;
unsigned char cursor = 0;
unsigned char letter_count = 0;
unsigned char shift_timer = 0;
unsigned char font_size_char = 8;
unsigned char terminal_size = 48;
bit running_line_mode = 0;
char command ;



void PORT_Init ( void ) ;
void Port_IO_Init () ;
void Init_Device ( void ) ;
void UART_Init_ ( void ) ;
unsigned char get_word_value(int index ) ;
void add_letter ( char letter_start_idx ) ;
void delete_last_letter ( void ) ;
void clear_word ( void ) ;
unsigned char get_letter_start_idx ( char c ) ;
void uart_send_char ( char c ) ;
char uart_read_char ( void ) ;
void define_type_of_mode ( void ) ;
void run_as_line ( char c ) ;
void run_as_terminal ( char c ) ;


// -- - - - - - - - - - -- - -- - - -- - -- - - -- - - -- - -- - - -- - -- - - -- - -- - - -- - -- - - -- - -- - - -- - -- - - -- - -- -
// MAIN Routine
// -- - - - - - - - - - -- - -- - - -- - -- - - -- - - -- - -- - - -- - -- - - -- - -- - - -- - -- - - -- - -- - - -- - -- - - -- - -- -
void main ( void )
{
    PCA0MD &= ~0x40; // WDTE = 0 ( clear watchdog timer
    // enable )
    PORT_Init();
    Init_Device();
    P2 = 0x00;
    CLR = 0;
    cursor = 0;

    define_type_of_mode () ;

    while (1) {
        char c = uart_read_char () ;
        if ( running_line_mode == 1) {
            run_as_line ( c ) ;
        } else {
            run_as_terminal ( c ) ;
        }
    } // Spin forever
}


// Configure the Crossbar and GPIO ports
void PORT_Init ( void )
 {
    unsigned char SFRPAGE_save = SFRPAGE ; // Save the current SFRPAGE

    SFRPAGE = CONFIG_PAGE ; // Switch to the necessary SFRPAGE

    XBR1 = 0x40 ; // Enable crossbar and weak pull - ups
    XBR0 = 0x01 ;
    SFRPAGE = SFRPAGE_save ; // Restore the SFRPAGE
}

// -- - - - - - - - - - -- - -- - - -- - -- - - -- - -- - - -- - -- - - -- - -- - - -- - - -- - -- - - -- - -- - - -- - -- - - -- - -- -
// Global variables for Timer0 ISR
// -- - - - - - - - - - -- - -- - - -- - -- - - -- - -- - - -- - -- - - -- - -- - - -- - - -- - -- - - -- - -- - - -- - -- - - -- - -- -
unsigned char max_width ;
unsigned char idx ;
unsigned char col ;


// Timer0 interrupt service routine for display scanning
void Timer0_ISR ( void ) interrupt 1
{
    idx = cursor - delta_pos ;
    col = get_word_value ( cursor - delta_pos ) ;
    P2 = ~ col ;
    CLK = 0;
    CLK = 1;
    /* ~~~~~ ~~~~~~~ */
    cursor ++;
    if ( cursor > 48) {
        cursor = 0;

        if ( running_line_mode == 1) {
            
            if (++ shift_timer == 10) {
                shift_timer = 0;
                delta_pos ++;
                max_width = ( letter_count * font_size_char < terminal_size ) ?
                terminal_size : letter_count * 8;

                if ( delta_pos == max_width ) {
                    delta_pos = 0;
                }
            }
        }
    }

    TL0 = 0xfc ;
    TH0 = 0xff ;
}


// Initialize timers 0 and 1
void Timer_Init ()
{
    TCON = 0x10 ;
    TMOD = 0x01 ;
    CKCON = 0x02 ;
    TL0 = 0xff ;
    TH0 = 0xf6 ;
    TCON |= 0x40 ;
    TMOD |= 0x20 ;
    CKCON |= 0x08 ;
    TH1 = 0x60 ;
}


// Initialize UART
void UART_Init ( void )
{
    SCON0 = 0x10 ;
}


// Initialize interrupts
void Interrupts_Init ()
{
    SFRPAGE = CONFIG_PAGE ;
    IE = 0x82 ;
}

// Initialization function for device ,
// Call Init_Device () from your main program
void Init_Device ( void )
{
    Timer_Init () ;
    Interrupts_Init () ;
    UART_Init () ;
}


// Read char with uart
char uart_read_char ( void ) {
    while ( RI0 == 0) {}; // ~~~~ ~~~~~~~~ ~~~~~~~
    command = SBUF0 ;
    RI0 = 0;
    return command ; // ~~~~~~~~~~ ~~~~~~~~ ~~~~~~~
}

  
// Send chat with uart
void uart_send_char ( char c ) {
    SBUF0 = c ; // ~~~~~~~~ ~~~~~~
    while ( TI0 == 0) {}; // ~~~~~~~~ ~~~~~ ~~~~~~~
    TI0 = 0; // ~~~~~~ ~~~~~~~~~~ ~~~~~~~~~ ~~~~~~
}


// Correlates char and alphabet . h . Return start index in massive cyrillic_fonts
unsigned char get_letter_start_idx ( char c ) {
    if ( c >= FIRST_LETTER && c <= LAST_LETTER ) {
        unsigned char index = c - FIRST_LETTER ;

        if ( index < 31) {
            return index * 8;
        }
    } else {
        return 0xFF ;
    }
}


// Defines behavior in terminal mode
void run_as_terminal ( char c ) {
    unsigned char start_index ;

    if ( c == CTRL_C ) {
        clear_word () ;
        return ;
    }

    if ( c == BACKSPACE ) {
        delete_last_letter () ;
        return ;
    }

    if (( letter_count + 1) * font_size_char < terminal_size ) {
    start_index = get_letter_start_idx ( c ) ;

        if ( start_index != 0xFF ) {
            add_letter ( start_index ) ;
        }
    }
}


// Defines behavior in running line mode
void run_as_line ( char c ) {
    unsigned char new_letters [10];
    unsigned char count = 0;
    unsigned char i = 0;
    unsigned char start_index_letter ;

    if ( c == CTRL_C || letter_count == 0) {
        clear_word () ;

        while (1) {

        if ( c == ENTER ) {
            break ;
            }
        else {
            if ( count < max_letters ) {
                start_index_letter = get_letter_start_idx ( c ) ;

                if ( start_index_letter != 0xFF ) {
                    new_letters [ count ] = start_index_letter ;
                    count ++;
                }
            } else {
                break ;
            }
        }
            c = uart_read_char () ;
        }

        for ( i = 0; i < count ; i ++) {
            add_letter ( new_letters [ i ]) ;
        }
    }
}

void define_type_of_mode ( void ) {
    while (1) {
        char c = uart_read_char () ;
        if ( c == CTRL_Q ) {
            running_line_mode = 1;
            break ;
        }
        if ( c == CTRL_W ) {
            running_line_mode = 0;
            break ;
        }
    }
}


// WORD PART FUNCTION

// Returns the value of the column with the idx number in word
unsigned char get_word_value ( int index ) {
    int max_width = ( letter_count * 8 < 48) ? 48: letter_count * 8;
    int letter_idx ;
    int column_idx ;

    if ( index < 0) {
        index = max_width + index ;
    }
    letter_idx = index / font_size_char ;
    column_idx = index % font_size_char ;

    if ( letter_idx < letter_count ) {
        return cyrillic_fonts [ word [ letter_idx ] * font_size_char + column_idx ];
    }
    return 0;
}


// Add new letter to word_parts
void add_letter(char letter_start_idx ) {
    if ( letter_count < max_letters ) {
        word [ letter_count ++] = letter_start_idx / font_size_char ;
    }
}


// Delete last letter from word_parts
void delete_last_letter () {
    if ( letter_count > 0) {
        letter_count --;
    }
}


// Clear all word_parts
void clear_word () {
    letter_count = 0;
}    