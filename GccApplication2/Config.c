#include "Config.h"
static FILE USART_stream = FDEV_SETUP_STREAM(usart0_printf, NULL, _FDEV_SETUP_WRITE);

void togle_led(void)
{
	PORTB ^= (1 << PINB5);
}
void usart_init(uint32_t ubrr)
{
	
	// Set baud rate
	UBRR0H = (uint8_t)(ubrr >> 8);
	UBRR0L = (uint8_t)ubrr;
	
	UCSR0A = (1 << U2X0);

	// Enable receiver and transmitter
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	// Set frame format: 8 data, 1 stop bit
	UCSR0C = (3 << UCSZ00);
	
	// Enable rx interrupt
	UCSR0B |= (1 << RXCIE0);\
	stdout = &USART_stream;
	
}


int usart0_printf(char byte, FILE *stream)
{
	if (byte == '\n')
	usart0_printf('\r', stream);
	// Wait for empty transmit buffer
	while (!(UCSR0A & (1 << UDRE0)));
	// Put data into buffer, sends the data
	UDR0 = byte;
	return 0;
}
void usart0_transmit_byte(uint8_t data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	// Put data into buffer, sends the data
	UDR0 = data;
	return;
}

void usart0_transmit_data(uint8_t *data, uint16_t data_len)
{
	while(data_len)
	{
		usart0_transmit_byte(*data++);
		data_len--;
	}
	return;
}
void init_timer_0(void)
{
	TCCR0B = 0;
	TCCR0A = 0;
	TCCR0A |= (1 << WGM01);
	TIMSK0 |= (1 << OCIE0A);
	OCR0A = SET_TIMER_0A_MS;
	TCCR0B |= (1 << CS00);
	TCCR0B |= (1 << CS01);
}
void ini_interrupt(void)
{
	DDRD&=~(1<<2);			//настроим PD2 INT0 на вход
	PORTD|=(1<<2);			//притянем ножку пина к питанию
	EICRA|=(1<<ISC00);		//настроим прерывания Any logical change on INT1 generates an interrupt request
	EIMSK|=(1<<INT0);		//разрешим прерывания INT0
}