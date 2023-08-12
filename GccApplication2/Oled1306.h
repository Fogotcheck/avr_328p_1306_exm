#ifndef __OLED1306_H
#define __OLED1306_H
#include <avr/pgmspace.h>
#include "Config.h"
#include "TWI.h"
#include <stdlib.h>

#define ADDRESS 0x3c

#define NEXT_DATA 0b01000000 //data
#define NEXT_BYTE_DATA 0b11000000 //data byte
#define NEXT_COMMAND 0b10000000 //command

#define PAGE_128_64 8
#define COLUM_128_64 128

#define PAGE_128_32 4
#define COLUM_128_64 128


void ini_oled(void);
void clear_oled(void);
void oled_write(uint8_t mode, uint8_t data);
void screen_update(void);
void print_char_5x8(uint8_t column, uint8_t string, uint8_t sign);
void print_string_5x8(uint8_t column, uint8_t string, char *str);
#endif //__OLED1306_H