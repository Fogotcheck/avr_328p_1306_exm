#ifndef __ADC_H
#define __ADC_H
#include "Config.h"

typedef struct 
{
	uint8_t hi_ADC;
	uint8_t lo_ADC;
	uint16_t val;	
}VAL_ADC;



void ini_ADC_hand(void);
uint16_t return_ADC_hand(void);
void ini_ADC_isr();
void return_ADC_isr(VAL_ADC *val);
#endif //__ADC_H