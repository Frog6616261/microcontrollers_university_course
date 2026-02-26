//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <c8051F360.h> 
#include <compiler_defs.h>              

//-----------------------------------------------------------------------------
// Global CONSTANTS
//-----------------------------------------------------------------------------

#define SYSCLK 3062500                 // Approximate SYSCLK frequency in Hz

sbit CLK = P2^7;
sbit CLR = P1^7;
sbit TTT = P2^0;

//-----------------------------------------------------------------------------
// Function PROTOTYPES
//-----------------------------------------------------------------------------

void PORT_Init (void);
void Init_Device(void); 


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

   P2 = 0x55;
   CLR = 0;

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
   TH0       = 0xff; 
   TL0       = 0xaa; 
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

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------