//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <c8051F360.h> 
#include <compiler_defs.h>              
#include <alpabet.h>   

//-----------------------------------------------------------------------------
// Global CONSTANTS
//-----------------------------------------------------------------------------

#define SYSCLK 3062500                 // Approximate SYSCLK frequency in Hz

sbit CLK = P2^7;
sbit CLR = P1^7;
sbit TTT = P2^0;

struct WordPart {
    int* data;     // указатель на массив буквы
    int size;      // размер этой буквы
};

struct WordPart word_parts[] = {
    {font_M, sizeof(font_M) / sizeof(font_M[0])},  
    {font_A, sizeof(font_A) / sizeof(font_A[0])},  
    {font_M, sizeof(font_M) / sizeof(font_M[0])}, 
    {font_A, sizeof(font_A) / sizeof(font_A[0])}   
};

int cursor = 0;
int parts_count = 4;
int total_length = 0;
 
//-----------------------------------------------------------------------------
// Function PROTOTYPES
//-----------------------------------------------------------------------------

void PORT_Init (void);
void Init_Device(void); 
int get_word_value(int index);
int get_word_length(void);


//-----------------------------------------------------------------------------
// MAIN Routine
//-----------------------------------------------------------------------------
void main (void) 
{
   int k;
   PCA0MD &= ~0x40;                    // WDTE = 0 (clear watchdog timer
                                       // enable)
   PORT_Init ();
   Init_Device();

   P2 = 0x00;
   CLR = 0;

   total_length = get_word_length();
   cursor = 0; 

   while (1) {}                         // Spin forever
}

//-----------------------------------------------------------------------------
// PORT_Init
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// Configure the Crossbar and GPIO ports
//
void PORT_Init (void)
{
   unsigned char SFRPAGE_save = SFRPAGE; // Save the current SFRPAGE

   SFRPAGE = CONFIG_PAGE;              // Switch to the necessary SFRPAGE

   XBR1    = 0x40;                     // Enable crossbar and weak pull-ups
   
   SFRPAGE = SFRPAGE_save;             // Restore the SFRPAGE
}

void Timer0_ISR(void) interrupt 1 
{
   CLK = 0;
   CLK = 1;

   P2 = get_word_value(cursor);
   cursor++;

   if(cursor >= total_length) {
     cursor = 0;
   } 

   TL0       = 0x66; 
   TH0       = 0xff; 
}

void Timer_Init()
{
    TCON      = 0x10;
    TMOD      = 0x01;
    CKCON     = 0x02;
    TL0       = 0xff; 
    TH0       = 0xf6; 
}

void Interrupts_Init()
{
    SFRPAGE   = CONFIG_PAGE;
    IE        = 0x82;
}


// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Timer_Init();
    Interrupts_Init();
}

int get_word_value(int index) {
    int current_index = index;
    
    for(int part = 0; part < parts_count; part++) {
        if(current_index < word_parts[part].size) {
            return word_parts[part].data[current_index];
        }
        current_index -= word_parts[part].size;
    }
    return 0;
}

int get_word_length() {
    int total = 0;
    for(int part = 0; part < parts_count; part++) {
        total += word_parts[part].size;
    }
    return total;
}

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------