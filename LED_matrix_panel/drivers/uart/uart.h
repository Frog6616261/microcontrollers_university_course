#include "../../mcu/C8051F360.h"
#include "../../mcu/compiler.h"

#ifndef TIMER_H
#define TIMER_H

void uart_init(void);
void uart_send_char(char c);
char uart_read_char(void);

struct uart{
    void (*init)(void);
    void (*send_char)(char c);
    char (*read_char)(void);
};

extern struct uart UART;

struct uart UART = {
    .init = uart_init,
    .send_char = uart_send_char,
    .read_char = uart_read_char
};


#endif