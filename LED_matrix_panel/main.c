#include "mcu/C8051F360.h"
#include "mcu/compiler.h"

#include "include/alpabet.h"   
#include "include/word_funcs.h"   
#include "include/word_part.h" 

#include "drivers/timer/timer.h"  
#include "drivers/uart/uart.h"  


#define SYSCLK 3062500                 // Approximate SYSCLK frequency in Hz


#define CLK P2_7    //__sbit __at (P2_7) CLK;
#define CLR P1_7    //__sbit __at (P1_7) CLR;
#define TTT P2_0    //__sbit __at (P2_0) TTT;   





struct word_part word_parts[] = {  
	{font_M, sizeof(font_M) / sizeof(font_M[0])}, 
	{font_I, sizeof(font_I) / sizeof(font_I[0])},
	{font_C, sizeof(font_C) / sizeof(font_C[0])},
	{font_H, sizeof(font_H) / sizeof(font_H[0])},
	{font_E, sizeof(font_E) / sizeof(font_E[0])},
	{font_L, sizeof(font_L) / sizeof(font_L[0])},
	{font_L, sizeof(font_L) / sizeof(font_L[0])},
	{font_E, sizeof(font_E) / sizeof(font_E[0])},
	{font_space, sizeof(font_space) / sizeof(font_space[0])},
};

int g_delta_pos = 0;
int g_cursor = 0;
int g_parts_count = 9;
unsigned int g_cur_time_for_word = 0;
unsigned int g_delta_time_for_word = 100;
int g_word_size = 0;
 

void PORT_Init (void);
void Timer_Init(void);
void Init_Device(void); 


void main (void) 
{
    

	PCA0MD &= ~0x40;                    // WDTE = 0 (clear watchdog timer
	                                   // enable)
	PORT_Init ();
	Init_Device();

	P2 = 0x00;
	CLR = 0;
	g_cursor = 0;

	g_word_size = get_word_length(g_parts_count, word_parts);

	if (g_word_size < 47) {
		g_word_size = 47; 
	}

	while (1) {
	}                         // Spin forever

}


void PORT_Init (void)
{
   unsigned char SFRPAGE_save = SFRPAGE; // Save the current SFRPAGE

   unsigned char SFRPAGE_for_XBR1 = 0x0F; // see datasheet sfrpage table for registers

   SFRPAGE = SFRPAGE_for_XBR1;              // Switch to the necessary SFRPAGE

   XBR1    = 0x40;                     // Enable crossbar and weak pull-ups
   
   SFRPAGE = SFRPAGE_save;             // Restore the SFRPAGE
}


void Timer_ISR(void) //interrupt 1
{
    P2 = ~(get_word_value((g_cursor-g_delta_pos), g_word_size, g_parts_count, word_parts));


    CLK = 0;
    CLK = 1;

    if (g_cursor < 48) {
        g_cursor++; 
    } else {
        g_cursor = 0; 
    }


    if (g_cur_time_for_word == g_delta_time_for_word)
        g_cur_time_for_word = 0;
        g_delta_pos++;

        if (g_delta_pos == g_word_size){
            g_delta_pos = 0;
        }

        TL1       = 0x00; 
        TH1       = 0xC0;
  
    g_cur_time_for_word++;

    TL0       = 0xee; 
    TH0       = 0xff; 
}


// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Timers_Init();
    Interrupts_Init();     
}

