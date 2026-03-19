#include "C8051F360.h"
#include "compiler.h"

#ifndef UART_H
#define UART_H

void uart_init(void);
void uart_send_char(char c);
char uart_read_char(void);

#endif