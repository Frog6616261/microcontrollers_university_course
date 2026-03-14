#include "../../mcu/C8051F360.h"
#include "../../mcu/compiler.h"

#ifndef TIMER_H
#define TIMER_H
void Timers_Init()
{
    TCON      = 0x50;
    TMOD      = 0x11;
    CKCON     = 0x02;

    TL0       = 0xff; 
    TH0       = 0xf6; 
}


void Interrupts_Init()
{
    IE        = 0x8A;
}

#endif