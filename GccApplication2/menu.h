#ifndef _MENU_H
#define _MENU_H
#include "Config.h"
#define DELAY_START 3000
#define  STR_0 "1 point"
#define  STR_1 "2 point"
#define  STR_2 "3 point"
#define  STR_3 "4 point"
#define  STR_4 "5 point"
#define  STR_5 "6 point"
#define  STR_6 "7 point"
#define  STR_7 "8 point"
void set_ptr_str (uint8_t num_str);
void set_menu(uint8_t str);
void start_menu(void);
void set_value(uint8_t str, int16_t val);
#endif //_MENU_H