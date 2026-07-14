#include "C8051F360.h"
#include "compiler.h"

#ifndef SYSTEM_PARAMS_H
#define SYSTEM_PARAMS_H


#define SYSCLK 24000000UL                 // Approximate SYSCLK frequency in Hz. The band of freq = 0 ... 50 MHz
#define P_OUT_IN_SKIP_PAGE 0x0F  
#define XBR_PAGE 0x0F
#define TIMER_DIVIDER_NUMB 12U        
#define UART_BAUD_RATE 9600U
#define TIMER1_INTERRUPT_FREQUENCY 340U

#endif

