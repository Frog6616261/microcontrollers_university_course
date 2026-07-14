#include "C8051F360.h"
#include "compiler.h"
#include "system_params.h"

#include "alpabet.h"   
#include "word_funcs.h"   
#include "word_part.h" 

#include "timer.h"  
#include "uart.h"  



#define CLK P2_7    //__sbit __at (P2_7) CLK;
#define CLR P1_7    //__sbit __at (P1_7) CLR;
#define TTT P2_0    //__sbit __at (P2_0) TTT;   

int g_delta_pos = 0;
int g_cursor = 0;
int g_parts_count = 9;
unsigned int g_cur_time_for_word = 0;
unsigned int g_delta_time_for_word = 100;
int g_word_size = 0;


struct WordPart __code word_parts[] = {  
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



 

void PORT_Init (void);
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
	}                         

}


void PORT_Init (void)
{
    // P1.7 - Unassigned, Push-Pull, Digital
    // P2.0 - Unassigned, Push-Pull, Digital
    // P2.1 - Unassigned, Push-Pull, Digital
    // P2.2 - Unassigned, Push-Pull, Digital
    // P2.3 - Unassigned, Push-Pull, Digital
    // P2.4 - Unassigned, Push-Pull, Digital
    // P2.5 - Unassigned, Push-Pull, Digital
    // P2.6 - Unassigned, Push-Pull, Digital
    // P2.7 - Unassigned, Push-Pull, Digital

    unsigned char SFRPAGE_save = SFRPAGE; 
    SFRPAGE = P_OUT_IN_SKIP_PAGE;
    
    P1MDOUT |= 0xFE; // P1.7 init
    P2MDOUT |= 0xFF; // P2.0-P2.6 init, P2.7 init

    // P0SKIP |= 0xC0; //uart?
    // P1SKIP |= 0x7F; //uart?
    SFRPAGE = SFRPAGE_save;

    SFRPAGE_save = SFRPAGE; 
    SFRPAGE = XBR_PAGE;
    XBR1 |= 0x40; // enable priority matrix
    SFRPAGE = SFRPAGE_save; 
}


void Timer_ISR(void) __interrupt(3) // interrupt timer 1
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


void Init_Device(void)
{
    uart_init();
    Timers_Init();
    Interrupts_Init();     
}

