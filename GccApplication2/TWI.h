#ifndef __TWI_H__
#define __TWI_H__
#include "Config.h"
#define F_SCL 800000UL
#define MY_ADDRESS 

#define TW_MT_DATA_ASK 0x28 // ¬едущий передал данные и ведомый подтвердил прием
#define TW_MR_DATA_ASK 0x50 // ¬едущий прин€л данные и передал подтверждение
#define TW_MR_DATA_NASK 0x58 // ¬едущий передал данные и ведомый подтвердил прием 


void ini_TWI(void);
void TWI_StartCondition(void);
void TWI_StopCondition(void);
void TWI_SendByte(uint8_t data);
void TWI_Send_address(uint8_t address);
#endif //__TWI_H__