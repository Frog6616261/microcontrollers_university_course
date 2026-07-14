// Includes

#include <c8051F360.h>                  // SFR declarations
#include <domofon.h> 


// 16-bit SFR Definitions for 'F36x

sfr16 TMR2RL = 0xCA;                   // Timer2 reload value
sfr16 TMR2 = 0xCC;                     // Timer2 counter


#define SYSCLK 3062500

// Global value

unsigned int delay_counter = 0;
unsigned char len_line = 16; // in symbols
unsigned char input_type = 0;

unsigned char input_len_psw = 0;
unsigned char max_len_psw = 16;


sbit R1 = P2^7;
sbit R2 = P2^6;
sbit R3 = P2^5;
sbit R4 = P2^4;

sbit C1 = P2^3;
sbit C2 = P2^2;
sbit C3 = P2^1;
sbit C4 = P2^0;

sbit RS = P1^5;
sbit R_W = P1^6;
sbit E = P1^7;

unsigned char input_psw[16];

unsigned char incorrect_password[] = {'P', 'S', 'W', ' ', 'I', 'S', ' ',
                                      'I', 'N', 'C', 'O', 'R', 'E', 'C', 'T'};
unsigned char correct_password[] = {'P', 'S', 'W', ' ', 'I', 'S', ' ',
                                    'C', 'O', 'R', 'E', 'C', 'T'};
unsigned char input_password[] = {'I', 'N', 'P', 'U', 'T', ' ', 'P', 'S',
                                  'W'};

char command;


// Function PROTOTYPES

void PORT_Init(void);
void Timer2_Init(int counts);
void Timer2_ISR(void);
void Display_Init(void);
void UART_Init(void);
void Timer_Init();

void delay(unsigned int time);

void send_command_to_display(unsigned char command);
void send_char_to_display(unsigned char symbol);
void send_word_to_display_first_line(unsigned char* word, char len);
void send_word_to_display_second_line(unsigned char* word, char len);

unsigned char read_keyboard(void);
unsigned char get_value_from_key_board(void);

void uart_send_char(char c);
char uart_read_char(void);

void write_input_psw(void);


// MAIN Routine

void main(void)
{
    unsigned char res = 0;
    unsigned char i = 0;
    PCA0MD &= ~0x40;                    // WDTE = 0 (clear watchdog timer
                                        // enable)
    PORT_Init();
    Timer_Init();
    UART_Init();
    Timer2_Init(SYSCLK / 12 / 1000);    // Init Timer2 to generate interrupts
                                        // at a 1000 Hz rate.

    // UART_Init();

    EA = 1;                             // Enable global interrupts

    Display_Init();


    SFRPAGE = LEGACY_PAGE;              // Page to sit in for now

    send_command_to_display(0x01);

    while (1) {
        // input psw
        write_input_psw();

        // check len psw
        uart_send_char(input_len_psw);
        res = uart_read_char();

        if (res == 0xaa) {
            send_command_to_display(0x01);
            send_word_to_display_first_line(
                incorrect_password,
                sizeof(incorrect_password) / sizeof(incorrect_password[0])
            );
            delay(5000);
        } else {
            if (res == 0x55) {
                for (i = 0; i < input_len_psw; i++) {
                    uart_send_char(input_psw[i]);
                    res = uart_read_char();
                    if (res == 0xaa) {
                        send_command_to_display(0x01);
                        send_word_to_display_first_line(
                            incorrect_password,
                            sizeof(incorrect_password) / sizeof(incorrect_password[0])
                        );
                        delay(3000);
                        break;
                    }
                }

                if (i == input_len_psw) { // get to end {
                    send_command_to_display(0x01);
                    send_word_to_display_first_line(
                        correct_password,
                        sizeof(correct_password) / sizeof(incorrect_password[0])
                    );
                    delay(3000);
                }
            }
        }
    }                                   // Spin forever
}


// PORT_Init

void PORT_Init(void)
{
    unsigned char SFRPAGE_save = SFRPAGE; // Save the current SFRPAGE

    SFRPAGE = CONFIG_PAGE;               // Switch to the necessary SFRPAGE

    XBR0 = 0x01;
    XBR1 = 0x40;                         // Enable crossbar and weak pull-ups

    SFRPAGE = SFRPAGE_save;              // Restore the SFRPAGE
}


// Timer2_Init

void Timer2_Init(int counts)
{
    unsigned char SFRPAGE_save = SFRPAGE; // Save the current SFRPAGE

    SFRPAGE = CONFIG_PAGE;               // Switch to the necessary SFRPAGE

    TMR2CN = 0x00;                       // Stop Timer2; Clear TF2;
                                         // Use SYSCLK/12 as timebase
    TMR2RL = -counts;                    // Init reload values
    TMR2 = 0xFFFF;                       // Set to reload immediately

    ET2 = 1;                             // Enable Timer2 interrupts

    TR2 = 1;                             // Start Timer2

    SFRPAGE = SFRPAGE_save;              // Restore the SFRPAGE
}

void Timer_Init()
{
    TCON = 0x40;
    TMOD = 0x20;
    CKCON = 0x08;
    TH1 = 0x60;
}


// UART_Init

void UART_Init(void)
{
    SCON0 = 0x10;
}


// Display_Init

void Display_Init(void)
{
    delay(15);
    send_command_to_display(0x30); // 0011 0000
    delay(5);
    send_command_to_display(0x30); // 0011 0000
    delay(1);
    send_command_to_display(0x30); // 0011 0000
    delay(1);
    send_command_to_display(0x38); // 0011 1000
    delay(1);
    send_command_to_display(0x08); // 0000 1000
    delay(1);
    send_command_to_display(0x01); // 0000 0001
    delay(1);
    send_command_to_display(0x06); // 0000 0110
    delay(1);
    send_command_to_display(0x0e); // 0000 1110
    delay(1);
    send_command_to_display(0x18); // 0001 1000
}


// Timer2_ISR

void Timer2_ISR(void) interrupt 5
{
    TF2H = 0;

    if (delay_counter != 0) {
        delay_counter--;
    } // Clear Timer2 interrupt flag
}


// delay

void delay(unsigned int time)
{
    delay_counter = time;
    while (delay_counter != 0) {
    }
}


// send_command_to_display()

void send_command_to_display(unsigned char command)
{
    E = 0;
    RS = 0;
    R_W = 0;
    P2 = command;
    delay(1);
    E = 1;
    delay(1);
    E = 0;
    delay(1);
}


// send_char_to_display()

void send_char_to_display(unsigned char symbol)
{
    E = 0;
    RS = 1;
    R_W = 0;
    P2 = symbol;
    delay(1);
    E = 1;
    delay(1);
    E = 0;
    delay(1);
}


// send_command_to_display()

void send_word_to_display_first_line(unsigned char* word, char len)
{
    int i = 0;

    if (len > len_line) len = len_line;

    send_command_to_display(0x80);

    for (i = 0; i < len; i++) {
        send_char_to_display(word[i]);
    }
}

void send_word_to_display_second_line(unsigned char* word, char len)
{
    int i = 0;

    if (len > len_line) len = len_line;

    send_command_to_display(0xc0);

    for (i = 0; i < len; i++) {
        send_char_to_display(word[i]);
    }
}


// uart_read_char

char uart_read_char(void)
{
    while (RI0 == 0) {};
    command = SBUF0;
    RI0 = 0;
    return command;
}


// uart_send_char

void uart_send_char(char c)
{
    SBUF0 = c;
    while (TI0 == 0) {};
    TI0 = 0;
}


// read_keyboard

unsigned char get_value_from_key_board(void)
{
    P2 = 0xff;
    delay(10); // time to charge

    R1 = 0;
    if (C1 == 0) {
        return first_tab[input_type];
    }
    if (C2 == 0) {
        return second_tab[input_type];
    }
    if (C3 == 0) {
        return third_tab[input_type];
    }
    if (C4 == 0) {
        input_type = 0;
        return ' ';
    }
    R1 = 1;

    R2 = 0;
    if (C1 == 0) {
        return fourth_tab[input_type];
    }
    if (C2 == 0) {
        return fifth_tab[input_type];
    }
    if (C3 == 0) {
        return sixth_tab[input_type];
    }
    if (C4 == 0) {
        input_type = 1;
        return ' ';
    }
    R2 = 1;

    R3 = 0;
    if (C1 == 0) {
        return seventh_tab[input_type];
    }
    if (C2 == 0) {
        return eigth_tab[input_type];
    }
    if (C3 == 0) {
        return ninth_tab[input_type];
    }
    if (C4 == 0) {
        input_type = 2;
        return ' ';
    }
    R3 = 1;

    R4 = 0;
    if (C1 == 0) {
        return '*';
    }
    if (C2 == 0) {
        return zeroth_tab[input_type];
    }
    if (C3 == 0) {
        return '#';
    }
    if (C4 == 0) {
        input_type = 3;
        return ' ';
    }
    R4 = 1;
    return ' ';
}

unsigned char read_keyboard(void)
{
    unsigned char res = get_value_from_key_board();
    while ((P2 & 0x0F) != 0x0F) {}; // Wait for the buttons to be underpressed
    return res;
}

void write_input_psw(void)
{
    unsigned char res = ' ';
    unsigned char i = 0;

    send_command_to_display(0x01);

    send_word_to_display_first_line(
        input_password,
        sizeof(input_password) / sizeof(input_password[0])
    );

    send_command_to_display(0xc0);

    while (res != '*') {
        res = ' ';
        while (res == ' ') {
            res = read_keyboard();
        }
        if (res != '*') {
            send_char_to_display(res);
            input_psw[i] = res;
            i++;
        }
    }
    input_len_psw = i;
}


// End Of File