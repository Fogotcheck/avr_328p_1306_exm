/*
 * GccApplication2.c
 *
 * Created: 11.11.2022 11:50:37
 * Author : win10
 */ 

#include "Config.h"
volatile uint32_t main_timer;
uint8_t buff[SIZE_BUF];
volatile CIRC_BUFFER buffer;
PARAM_EEPR param;
VAL_ADC val;

int main(void)
{
	cli();
	usart_init(USART0_UBRR);
	init_timer_0();
	ini_buffer(buff,SIZE_BUF);
	ini_TWI();
	ini_ADC_isr();
	ini_interrupt();
	sei();
	uint32_t timer_led=main_timer;
	uint32_t timer_buf=main_timer;
	uint32_t timer_fres=main_timer;
    DDRB|=(1<<5);
	ini_oled();
	eeprom_read_block((void*)&param,(int*)ADDRESS_EEPROM,sizeof(PARAM_EEPR));
	//param.distance=200;
	//param.timer_work=10;
	//eeprom_update_block((void*)&param,(int*)ADDRESS_EEPROM,sizeof(PARAM_EEPR));	
	start_menu();
	//set_value(3,param.foto_res);
	uint8_t num=0;
    while (1) 
    {
		if (main_timer-timer_led>=500)
		{
			togle_led();
			num++;	
			timer_led=main_timer;
		}
		if (main_timer-timer_buf>=5000)
		{
			clean_buf();
			timer_buf=main_timer;
		}
		if (main_timer-timer_fres>=1000)
		{
			printf("val_fun=%d\n",val.val);
			timer_fres=main_timer;
		}
		num=num>7?0:num;
		set_menu(num);		
		set_ptr_str(num);
		set_value(num,val.val);
		screen_update();
    }
}

ISR(TIMER0_COMPA_vect)
{
	main_timer++;
}
ISR(USART_RX_vect)
{
	push_byte(UDR0);
	return;
}
ISR(ADC_vect)
{
	val.lo_ADC=ADCL;
	val.hi_ADC=ADCH;
	return_ADC_isr(&val);		
}
ISR(INT0_vect)
{
	printf("HI\n");	
}
