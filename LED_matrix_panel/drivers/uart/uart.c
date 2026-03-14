#include "uart.h"


void uart_init(void){
    PCA0MD &= ~0x40;   // отключить watchdog

    // UART0: 8 бит, прием разрешен
    SCON0 = 0x10;      // REN0 = 1, mode 1

    // Таймер 1: 8-бит авто-перезагрузка
    TMOD &= ~0xF0;
    TMOD |=  0x20;     // Timer1 mode 2

    // Для 24.5 МГц и 9600 бод из таблицы:
    // SYSCLK/12, TH1 = 0x96
    CKCON &= ~0x0B;    // Timer1 тактируется от SYSCLK/12
    TH1 = 0x96;
    TL1 = 0x96;

    TR1 = 1;           // запустить Timer1
    TI0 = 1;           // передатчик готов
};

void uart_send_char(char c){
    while (TI0 == 0);
    TI0 = 0;
    SBUF0 = c;
};

char uart_read_char(void){
    while (RI0 == 0);
    RI0 = 0;
    return SBUF0;
};


