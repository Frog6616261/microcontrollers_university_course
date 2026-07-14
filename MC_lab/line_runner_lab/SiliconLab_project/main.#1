//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <c8051F360.h>
#include <compiler_defs.h>
#include <alpabet.h>

//-----------------------------------------------------------------------------
// Global CONSTANTS
//-----------------------------------------------------------------------------
#define SYSCLK 3062500

sbit CLK = P2^7;
sbit CLR = P1^7;
sbit TTT = P2^0;

struct WordPart 
{
    unsigned char code *word_data;
    unsigned int size;
};


struct WordPart word_parts[] = {
    { font_M, sizeof(font_M) / sizeof(font_M[0]) },
    { font_A, sizeof(font_A) / sizeof(font_A[0]) },
    { font_M, sizeof(font_M) / sizeof(font_M[0]) },
    { font_A, sizeof(font_A) / sizeof(font_A[0]) }
};

unsigned int cursor = 0;
unsigned int parts_count = 4;
unsigned int total_length = 0;

//-----------------------------------------------------------------------------
// Function PROTOTYPES
//-----------------------------------------------------------------------------
void PORT_Init(void);
void Init_Device(void);
void Timer_Init(void);
void Interrupts_Init(void);

unsigned char get_word_value(unsigned int index);
unsigned int get_word_length(void);

//-----------------------------------------------------------------------------
// MAIN Routine
//-----------------------------------------------------------------------------
void main(void)
{
    PCA0MD &= ~0x40;
    PORT_Init();
    Init_Device();

    P2 = 0x00;
    CLR = 0;

    total_length = get_word_length();
    cursor = 0;

    while (1) {
    }
}

//-----------------------------------------------------------------------------
// PORT_Init
//-----------------------------------------------------------------------------
void PORT_Init(void)
{
    unsigned char SFRPAGE_save = SFRPAGE;

    SFRPAGE = CONFIG_PAGE;
    XBR1 = 0x40;
    SFRPAGE = SFRPAGE_save;
}

void Timer0_ISR(void) interrupt 1
{
    CLK = 0;
    CLK = 1;

    P2 = get_word_value(cursor);
    cursor++;

    if (cursor >= total_length) {
        cursor = 0;
    }

    TL0 = 0x66;
    TH0 = 0xFF;
}

void Timer_Init(void)
{
    TCON = 0x10;
    TMOD = 0x01;
    CKCON = 0x02;
    TL0 = 0xFF;
    TH0 = 0xF6;
}

void Interrupts_Init(void)
{
    SFRPAGE = CONFIG_PAGE;
    IE = 0x82;
}

void Init_Device(void)
{
    Timer_Init();
    Interrupts_Init();
}

unsigned char get_word_value(unsigned int index)
{
    unsigned int current_index;
    unsigned int part;

    current_index = index;

    for (part = 0; part < parts_count; part++) {
        if (current_index < word_parts[part].size) {
            return word_parts[part].word_data[current_index];
        }
        current_index -= word_parts[part].size;
    }

    return 0;
}

unsigned int get_word_length(void)
{
    unsigned int total;
    unsigned int part;

    total = 0;

    for (part = 0; part < parts_count; part++) {
        total += word_parts[part].size;
    }

    return total;
}