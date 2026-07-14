#include "C8051F360.h"
#include "compiler.h"
#include "system_params.h"

void Timers_Init(void)
{    
    // set source for tacting T0 and T1. sysclk/divider for timer0 and timer1
    switch (TIMER_DIVIDER_NUMB){
        case 4:
            CKCON |= 0x01;
            CKCON &= ~(0x02);
            break;

        case 8:
            CKCON |= 0x03;
            break;

        case 12:
            CKCON &= ~(0x03);
            break;

        case 48:
            CKCON |= 0x02;
            CKCON &= ~(0x01);
            break;

        default:
            CKCON &= ~(0x03);            
    }

    // set 16x timer1
    TMOD |= 0x10;
    TMOD &= ~(0x20); 

    // set frequency for interrupts and frequency of timer
    unsigned int start_timer_1 = 0xffffffff;

    if (( ((SYSCLK/TIMER_DIVIDER_NUMB)/65536) < TIMER1_INTERRUPT_FREQUENCY ) && ( TIMER1_INTERRUPT_FREQUENCY < (SYSCLK/TIMER_DIVIDER_NUMB) )){
        start_timer_1 = 65536 - (SYSCLK/TIMER_DIVIDER_NUMB)/TIMER1_INTERRUPT_FREQUENCY;
    }

    TL0       = start_timer_1; 
    TH0       = (start_timer_1 >> 8); 

    // set overflow flag
    TF1 = 0;

    TR1 = 1; //start timer1
}


void Interrupts_Init(void)
{
    ET1 = 1;
    EA  = 1;
}