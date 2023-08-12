#ifndef _SAVE_PERAM_H
#define _SAVE_PERAM_H
#include "Config.h"
#define ADDRESS_EEPROM 0x08
typedef struct
{
	uint16_t param_0;
	uint16_t timer_work;
	uint16_t distance;
	uint16_t foto_res;
	uint16_t param_4;
	uint16_t param_5;
	uint16_t param_6;
	uint16_t param_7;	
}PARAM_EEPR;

#endif //_SAVE_PERAM_H