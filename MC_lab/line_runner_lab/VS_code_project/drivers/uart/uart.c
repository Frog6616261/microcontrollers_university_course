#include "C8051F360.h"
#include "compiler.h"
#include "system_params.h"

#include "uart.h"


void uart_init(void){

    unsigned char SFRPAGE_save = SFRPAGE;
    unsigned int T1CLK = SYSCLK / TIMER_DIVIDER_NUMB;
    unsigned char TH1_value;
    TH1_value = (unsigned char)(256 - T1CLK / (2 * UART_BAUD_RATE));

    PCA0MD &= ~0x40;   // disable watchdog;

    SFRPAGE = P_OUT_IN_SKIP_PAGE;    
    P0MDOUT |= 0x10; // TX=P0.4 -> pp
    P0MDOUT &= ~(0x20); // RX=P0.5 -> od

    SFRPAGE = XBR_PAGE;
    XBR0 |= 0x01; // enable uart to TX0 and RX0 connect with 
    XBR1 |= 0x40; // enable matrix
    SFRPAGE = SFRPAGE_save;

    SCON0 = 0x10;      // access to receive databy uart
    SCON0 &= ~(0x80);    // si_mode = 0, 8x 

    // set timer1, regim 2 (for uart)
    TMOD &= ~0xF0;
    TMOD |= 0x20;  

    CKCON &= ~0x03;    // Timer1 тактируется от SYSCLK/12

    TH1 =  TH1_value;   // set TH1 register
    TL1 = TH1;

    TR1 = 1;    // start Timer1
    TI0 = 1;    // transmitter is redy
    RI0 = 0;    // receiver is ready, set it by mc
}

void uart_send_char(char c){
    unsigned int timeout_timer = 10000;

    while (TI0 == 0){
        if (timeout_timer == 0){
            return;
        }

        timeout_timer--;
    };

    SBUF0 = c;
    TI0 = 0;
}

char uart_read_char(void){
    unsigned int timeout_timer = 10000;

    while (RI0 == 0){
        if (timeout_timer == 0){
            return 0;
        }

        timeout_timer--;
    };

    RI0 = 0;

    return SBUF0;
}


