#include "gd32f30x.h"
#include "systick.h"

void systick_config(void);
void PORT_INIT(void);
void SysTick_Handler(void);
void TIMER_INIT(void); // maybe we donnot need this
void Timer0IC_Init(void);
void Interrupt_Timer0IC_Init(void);


typedef uint32_t BOOL;
#define TRUE 0x01
#define FALSE 0x00

void PORT_INIT(void)
{
	rcu_periph_clock_enable(RCU_GPIOA); //sinchronise //Enable clock for GPIOA
	rcu_periph_clock_enable(RCU_GPIOB);	//sinchronise //Enable clock for GPIOB
	
	gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_10MHZ, GPIO_PIN_10); //tempreture
	gpio_init(GPIOB, GPIO_MODE_OUT_OD, GPIO_OSPEED_10MHZ, GPIO_PIN_11); //FAN
	gpio_init(GPIOB, GPIO_MODE_OUT_OD, GPIO_OSPEED_10MHZ, GPIO_PIN_10); //FAN_SPEED
	gpio_init(GPIOB, GPIO_MODE_OUT_OD, GPIO_OSPEED_10MHZ, GPIO_PIN_12); //LAMP3
	gpio_init(GPIOA, GPIO_MODE_OUT_OD, GPIO_OSPEED_10MHZ, GPIO_PIN_11); //LAMP2
	gpio_init(GPIOA, GPIO_MODE_OUT_OD, GPIO_OSPEED_10MHZ, GPIO_PIN_12); //LAMP1

	gpio_bit_set(GPIOA, GPIO_PIN_12);
	gpio_bit_set(GPIOB, GPIO_PIN_12);
	gpio_bit_set(GPIOA, GPIO_PIN_11);
	gpio_bit_set(GPIOB, GPIO_PIN_11);	
}

void TIMER0_INIT(void)
{
	timer_parameter_struct timer_initpara;

	timer_initpara.prescaler = 71; //F_clk / (prescaler + 1) => 72 MHz / (71 + 1) = 1 MHz
	timer_initpara.alignedmode = TIMER_COUNTER_EDGE;
	timer_initpara.counterdirection = TIMER_COUNTER_UP;
	timer_initpara.period = 0xFFFF;
	timer_initpara.clockdivision = TIMER_CKDIV_DIV1;
	timer_initpara.repetitioncounter = 0; 
	
	timer_auto_reload_shadow_enable(TIMER0); // if we change ARR -> new ARR start after end last period of work
	timer_init(TIMER0, &timer_initpara);	
}


static timer_ic_parameter_struct timer0_ch2_paraminit = {
	TIMER_IC_POLARITY_RISING,
	TIMER_IC_SELECTION_DIRECTTI,
	TIMER_IC_PSC_DIV1,
	0
	};

void Set_Timer0IC_icpolarity_rising(void)
{
	timer0_ch2_paraminit.icpolarity = TIMER_IC_POLARITY_RISING;
}

void Set_Timer0IC_icpolarity_falling(void)
{
	timer0_ch2_paraminit.icpolarity = TIMER_IC_POLARITY_FALLING;
}

void Timer0IC_Init(void){
	rcu_periph_clock_enable(RCU_TIMER0); //
	timer_input_capture_config(TIMER0, TIMER_CH_2,  &timer0_ch2_paraminit);
	Set_Timer0IC_icpolarity_falling();	
}




volatile uint32_t last = 0;
volatile uint32_t diff_up = 0;
volatile uint32_t diff_down = 0;
volatile uint32_t time_interrupt;
volatile uint32_t is_up;

volatile float cur_temperature;
volatile BOOL is_rising_flag = TRUE;
volatile BOOL is_exist_up_data = FALSE;
volatile BOOL is_exist_down_data = FALSE;

// update temperature
void TIMER0_Channel_IRQHandler(void)
{
	time_interrupt = timer_channel_capture_value_register_read(TIMER0, TIMER_CH_2);
	is_up = gpio_input_bit_get(GPIOA, GPIO_PIN_10);

	
	if(is_up == RESET)
	{
		diff_up = time_interrupt - last;
		last = time_interrupt;
		is_exist_up_data = TRUE;
		Set_Timer0IC_icpolarity_rising();

		//gpio_bit_set(GPIOA, GPIO_PIN_11);
	}
	
	if(is_up == SET)
	{
		diff_down = time_interrupt - last;
		last = time_interrupt;
		is_exist_down_data = TRUE;
		Set_Timer0IC_icpolarity_falling();
		
		//gpio_bit_reset(GPIOA, GPIO_PIN_11);
	}

	
	if (is_exist_up_data && is_exist_down_data)
	{
		cur_temperature = 235.0f - (400.0f * (float)diff_up)/ (float)diff_down;
		
		is_exist_up_data = FALSE;
		is_exist_down_data = FALSE;
	}
	
	timer_interrupt_flag_clear(TIMER0, TIMER_INT_FLAG_CH2);
}




int main(void)
{
// System Configuration	AHB Clock 120 MHz	
		SystemInit();
	
// APB1, APB2 Clock Setup
		rcu_apb1_clock_config(RCU_APB1_CKAHB_DIV4); // APB1 Clock 120MHz/4 = 30 MHz	
		rcu_apb2_clock_config(RCU_APB2_CKAHB_DIV4); // APB2 Clock 120MHz/4 = 30 MHz			
	
//	  NVIC Configuration: 4 bits for priority, 0 bits for subpriority	
		nvic_priority_group_set(NVIC_PRIGROUP_PRE4_SUB0);	
	
		systick_config();
	
		PORT_INIT();
	
		TIMER0_INIT();
		timer_enable(TIMER0);

		Timer0IC_Init();
		timer_interrupt_enable(TIMER0, TIMER_INT_CH2);
		
		//set priority on timperature controller
		nvic_irq_enable(TIMER0_Channel_IRQn, 1, 0); //Timer 0 main_prior = 1, subprior = 0


		while (1) 
		{
			
			////delay_1ms(10000);//ms
			//gpio_bit_set(GPIOB, GPIO_PIN_11); //of (stop)
			////delay_1ms(10000);//ms
			////gpio_bit_reset(GPIOB, GPIO_PIN_11); //on
			//
			//delay_1ms(10000);//ms
			//gpio_bit_set(GPIOA, GPIO_PIN_12);
			//gpio_bit_set(GPIOB, GPIO_PIN_12);
			//gpio_bit_set(GPIOA, GPIO_PIN_11);
			//delay_1ms(10000);//ms
			//gpio_bit_reset(GPIOA, GPIO_PIN_12);
			//gpio_bit_reset(GPIOB, GPIO_PIN_12);
			//gpio_bit_reset(GPIOA, GPIO_PIN_11);
		}
		
}

void SysTick_Handler(void)
{
	delay_decrement();
}



