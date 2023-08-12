#ifndef __CONFIG_H
#define __CONFIG_H

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <inttypes.h>
#include <avr/eeprom.h>

#include "Buffer.h"
#include "TWI.h"
#include "Oled1306.h"
#include "menu.h"
#include "ADC.h"
#include "HC_SR04.h"
#include "save_param.h"


#define USART0_BAUD 115200
#define USART0_UBRR ((F_CPU / 8 / USART0_BAUD) - 1)
#define SET_TIMER_0A_MS 249
#define SIZE_BUF 256
void togle_led(void);
void usart_init(uint32_t ubrr);
int usart0_printf(char byte, FILE *stream);
void usart0_transmit_byte(uint8_t data);
void usart0_transmit_data(uint8_t *data, uint16_t data_len);
void init_timer_0(void);
void ini_interrupt(void);
#endif //__CONFIG_H