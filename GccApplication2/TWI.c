#include "TWI.h"
extern uint32_t main_timer;

void ini_TWI(void)
{
	TWAR = 0x08;
	TWSR=(0<<TWPS1)|(0<<TWPS0);
	TWBR=((F_CPU/F_SCL)-16)/2;
}

void TWI_StartCondition(void)
{
	
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));	
}

void TWI_StopCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void TWI_SendByte(uint8_t data)
{
	TWDR = data;//запишем байт в регистр данных
	TWCR = (1<<TWINT)|(1<<TWEN);//включим передачу байта
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != TW_MT_DATA_ASK)
	{
		 return;
	}
}
void TWI_Send_address(uint8_t address)
{
	address<<=1;
	TWI_SendByte(address);
}