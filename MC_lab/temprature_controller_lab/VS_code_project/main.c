#include "gd32f30x.h"
#include "systick.c"

void systick_config ( void );
void PORT_INIT ( void );
void SysTick_Handler ( void ) ;
void TIMER_INIT ( void ) ;
void Timer0IC_Init ( void );
void Interrupt_Timer0IC_Init ( void );


 /* -- --------------- Константы ----------------- */
typedef uint32_t BOOL ;
#define TRUE 0x01

#define FALSE 0x00

 /* Протокольные коды (1 байт) */
 static const uint8_t REQ_INIT = 0x11 ;
 static const uint8_t REP_BOAR_OK = 0x12 ;
 static const uint8_t REQUEST_MODE = 0x14 ;
 static const uint8_t SET_MODE = 0x15 ;
 static const uint8_t TOOGLE_FAN = 0x16 ;
 static const uint8_t TOOGLE_HEATER = 0x17 ;

 /* -- --------------- Системные переменные ----------------- */
 volatile float temperature = 30.0f;
 volatile BOOL fan_is_on = FALSE;
 volatile BOOL heater_is_on = FALSE;
 volatile BOOL thermostat_is_on = TRUE;
 volatile uint8_t limit_hi_temp = 30; /* произвольные стартовые значения */
 volatile uint8_t limit_low_temp = 20;

 volatile static timer_ic_parameter_struct timer0_ch2_paraminit = {
    TIMER_IC_POLARITY_RISING ,
    TIMER_IC_SELECTION_DIRECTTI ,
    TIMER_IC_PSC_DIV1 ,
    1
 };

 void PORT_INIT ( void )
 {
    rcu_periph_clock_enable ( RCU_GPIOA ); // sinchronise // Enable clock for GPIOA
    rcu_periph_clock_enable ( RCU_GPIOB ); // sinchronise // Enable clock for GPIOB

    gpio_init ( GPIOA , GPIO_MODE_IN_FLOATING , GPIO_OSPEED_10MHZ , GPIO_PIN_10 );// tempreture
    gpio_init ( GPIOB , GPIO_MODE_OUT_OD , GPIO_OSPEED_10MHZ , GPIO_PIN_11 ); // FAN
    gpio_init ( GPIOB , GPIO_MODE_OUT_OD , GPIO_OSPEED_10MHZ , GPIO_PIN_10 ); // FAN_SPEED
    gpio_init ( GPIOB , GPIO_MODE_OUT_OD , GPIO_OSPEED_10MHZ , GPIO_PIN_12 ); // LAMP3
    gpio_init ( GPIOA , GPIO_MODE_OUT_OD , GPIO_OSPEED_10MHZ , GPIO_PIN_11 ); // LAMP2
    gpio_init ( GPIOA , GPIO_MODE_OUT_OD , GPIO_OSPEED_10MHZ , GPIO_PIN_12 ); // LAMP1

    gpio_bit_set ( GPIOA , GPIO_PIN_12 );
    gpio_bit_set ( GPIOB , GPIO_PIN_12 );
    gpio_bit_set ( GPIOA , GPIO_PIN_11 );
    gpio_bit_set ( GPIOB , GPIO_PIN_11 );
}

void TIMER0_INIT ( void )
{
    timer_parameter_struct timer_initpara ;

    rcu_periph_clock_enable (RCU_TIMER0) ; // sinchronise // Enable clock for GPIOA

    timer_initpara . prescaler = 71; // F_clk / ( prescaler + 1) = > 72 MHz / (71+ 1) = 1 MHz
    timer_initpara . alignedmode = TIMER_COUNTER_EDGE ;
    timer_initpara . counterdirection = TIMER_COUNTER_UP ;
    timer_initpara . period = 0xFFFF ;
    timer_initpara . clockdivision = TIMER_CKDIV_DIV1 ;
    timer_initpara . repetitioncounter = 0;

    timer_auto_reload_shadow_enable ( TIMER0 ); // if we change ARR -> new ARRrt after end last period of work
    timer_init (TIMER0 , &timer_initpara );
}

void Timer0IC_Init ( void ){
    rcu_periph_clock_enable ( RCU_TIMER0 ) ; //
    timer_input_capture_config ( TIMER0 ,TIMER_CH_2 , &timer0_ch2_paraminit );
    set_timer0IC_icpolarity (TIMER_IC_POLARITY_FALLING) ;
}

void USART1_init ( void )
{
    rcu_periph_clock_enable ( RCU_GPIOA );
    rcu_periph_clock_enable ( RCU_USART1 ) ;
    gpio_init ( GPIOA , GPIO_MODE_AF_PP , GPIO_OSPEED_50MHZ , GPIO_PIN_2 ) ;
    gpio_init ( GPIOA , GPIO_MODE_IN_FLOATING , GPIO_OSPEED_50MHZ , GPIO_PIN_3 );

    // USART configure
    usart_deinit ( USART1 ) ;
    usart_baudrate_set ( USART1 , 9600U) ;
    usart_parity_config ( USART1 , USART_PM_NONE );
    usart_word_length_set ( USART1 , USART_WL_8BIT );
    usart_stop_bit_set ( USART1 , USART_STB_1BIT );
    usart_receive_config ( USART1 , USART_RECEIVE_ENABLE ) ;
    usart_transmit_config ( USART1 , USART_TRANSMIT_ENABLE );
}

void set_timer0IC_icpolarity ( uint16_t polarity )
{
    timer0_ch2_paraminit.icpolarity = polarity ;
    timer_input_capture_config ( TIMER0 , TIMER_CH_2 , &timer0_ch2_paraminit );
}

volatile uint32_t diff_up = 0;
volatile uint32_t diff_down = 0;
volatile uint32_t time_interrupt ;
volatile BOOL is_exist_up_data = FALSE ;
volatile BOOL is_exist_down_data = FALSE ;
volatile BOOL is_rising_interrupt = FALSE ;

void TIMER0_Channel_IRQHandler ( void )
{
    time_interrupt = ( timer_channel_capture_value_register_read ( TIMER0 , TIMER_CH_2 )) ;

    if( is_rising_interrupt )
    {
        diff_down = time_interrupt ;
        set_timer0IC_icpolarity ( TIMER_IC_POLARITY_FALLING );
        timer_counter_value_config ( TIMER0 , 0) ;
        is_rising_interrupt = FALSE ;
        is_exist_down_data = TRUE ;

    } else {
        diff_up = time_interrupt ;
        set_timer0IC_icpolarity ( TIMER_IC_POLARITY_RISING ) ;
        timer_counter_value_config ( TIMER0 , 0) ;
        is_rising_interrupt = TRUE ;
        is_exist_up_data = TRUE ;
    }

    if ( is_exist_up_data && is_exist_down_data )
    {
        if ( diff_down != 0) {
            temperature = 235.0 - (400.0 * ( double ) diff_up )/ ( double ) diff_down ;
            update_termostat () ;
        }
        is_exist_up_data = FALSE ;
        is_exist_down_data = FALSE ;
    }
    timer_interrupt_flag_clear ( TIMER0 , TIMER_INT_FLAG_CH2 );
}

void update_termostat () {

    if ( temperature > limit_hi_temp ) {
        fan_on() ;
        heater_off() ;

    } else if ( temperature < limit_low_temp ) {
        fan_off() ;
        heater_on() ;
    }
}

void usart1_transmit ( uint16_t symbol )
{
    while ( RESET == usart_flag_get( USART1 , USART_FLAG_TBE )) {} // while buffer not empty
    usart_data_transmit ( USART1 , symbol );
}

uint16_t usart1_receive ( void )
{
    while ( RESET == usart_flag_get ( USART1 , USART_FLAG_RBNE ) ) {} // while iner exist not read data
    return usart_data_receive ( USART1 ) ;
}

void heater_on ( void )
{
    gpio_bit_reset ( GPIOA , GPIO_PIN_12 );
    gpio_bit_reset ( GPIOB , GPIO_PIN_12 );
    gpio_bit_reset ( GPIOA , GPIO_PIN_11 );
    heater_is_on = TRUE ;
}

void heater_off ( void )
{
    gpio_bit_set ( GPIOA , GPIO_PIN_12 );
    gpio_bit_set ( GPIOB , GPIO_PIN_12 );
    gpio_bit_set ( GPIOA , GPIO_PIN_11 );
    heater_is_on = FALSE ;
}

void fan_on ( void )
{
    gpio_bit_reset ( GPIOB , GPIO_PIN_11 );
    fan_is_on = TRUE ;
}

void fan_off ( void )
{
    gpio_bit_set ( GPIOB , GPIO_PIN_11 );
    fan_is_on = FALSE ;
}

int main ( void )
{
    // System Configuration AHB Clock 120 MHz
    SystemInit () ;
    // APB1 , APB2 Clock Setup
    rcu_apb1_clock_config ( RCU_APB1_CKAHB_DIV4 ) ; // APB1 Clock 120 MHz /4 =  Hz
    rcu_apb2_clock_config ( RCU_APB2_CKAHB_DIV4 ) ; // APB2 Clock 120 MHz /4 =  Hz
    // NVIC Configuration : 4 bits for priority , 0 bits for subpriority
    nvic_priority_group_set ( NVIC_PRIGROUP_PRE4_SUB0 );
    systick_config () ;

    PORT_INIT () ;
    TIMER0_INIT () ;
    timer_enable ( TIMER0 );
    Timer0IC_Init () ;
    timer_interrupt_enable ( TIMER0 , TIMER_INT_CH2 ) ;
    USART1_init () ;
    usart_enable ( USART1 );

    // set priority on timperature controller
    nvic_irq_enable(TIMER0_Channel_IRQn , 1 , 0) ; // Timer 0 main_prior = 1,    subprior = 0

    while (1)
    {
        uint16_t input = usart1_receive();

        switch ( input ) {
            case REQ_INIT :
                if ( thermostat_is_on == TRUE ) {
                    usart1_transmit ( REP_BOAR_OK );
                }
                break ;

            case REQUEST_MODE :
                /*
                Последовательно отправляем
                температуру
                включен ли режим термостата (0 x00 не включен, 0 x01 включен)
                */
                uint8_t mode_buf [6];
                mode_buf [0] = ( uint8_t ) temperature ; /* Текущая температура целая( часть) */
                mode_buf [1] = thermostat_is_on ? 0x01 : 0x00 ; /*Термостат включён? */
                mode_buf [2] = limit_hi_temp ; /*Верхняя граница */
                mode_buf [3] = limit_low_temp ; /*Нижняя граница */
                mode_buf [4] = fan_is_on ? 0x01 : 0x00 ; /*Вентилятор */
                mode_buf [5] = heater_is_on ? 0x01 : 0x00 ; /*Нагреватель */

                for ( uint8_t i = 0; i < sizeof ( mode_buf ); ++ i)
                    usart1_transmit ( mode_buf [i ]) ;
                break ;

            case SET_MODE :
                /*
                Принимаем байт с номером устанавливаемого режима
                байт режима терсмостата (0 x00 выключить термостат, включить
                термостат 0 x01 )

                байт задание верхней границы температуры
                байт задание нижней границы
                */
                uint8_t mode_flag = usart1_receive () ; /* 0x00 –отключить, 0x01 – включить */
                uint8_t hi_limit = usart1_receive () ; /* верхняя граница */
                uint8_t lo_limit = usart1_receive () ; /* нижняя граница */
                thermostat_is_on = ( mode_flag == 0x01 ) ? TRUE : FALSE ;
                limit_hi_temp = hi_limit ;
                limit_low_temp = lo_limit ;
                break ;

            case TOOGLE_FAN :
                /*
                271 Если вентилятор был включен, то он должен отключится, если не
                работал, то должен включится
                */
                if ( fan_is_on == TRUE )
                    fan_off () ;
                else
                    fan_on();

                break ;

            case TOOGLE_HEATER :
                /*
                Если нагреватель был включен, то он должен отключится, если не
                работал, то должен включится
                */
                if ( heater_is_on == TRUE )
                    heater_off () ;
                else
                    heater_on () ;
                    
                break ;

            default :
                break ;
        }
    }
}


