#include "menu.h"
//const uint8_t PROGMEM screen[] = {};

void set_ptr_str (uint8_t num_str)
{
	for (uint8_t i=0;i<8;i++)
	{
		print_string_5x8(0,i,"   ");
	}
	switch(num_str)
	{
		case 0:
		{
			print_string_5x8(0,0,"->>");
			break;
		}
		case 1:
		{
			print_string_5x8(0,1,"->>");
			break;
		}
		case 2:
		{
			print_string_5x8(0,2,"->>");
			break;
		}
		case 3:
		{
			print_string_5x8(0,3,"->>");
			break;
		}
		case 4:
		{
			print_string_5x8(0,4,"->>");
			break;
		}
		case 5:
		{
			print_string_5x8(0,5,"->>");
			break;
		}
		case 6:
		{
			print_string_5x8(0,6,"->>");
			break;
		}
		case 7:
		{
			print_string_5x8(0,7,"->>");
			break;
		}
		default:
		{
			clear_oled();
			return;
		}
	}
}
void set_menu(uint8_t str)
{
	switch(str)
	{
		case 0:
		{
			print_string_5x8(25,0,STR_0);
			break;
		}
		case 1:
		{
			print_string_5x8(25,1,STR_1);
			break;
		}
		case 2:
		{
			print_string_5x8(25,2,STR_2);
			break;
		}
		case 3:
		{
			print_string_5x8(25,3,STR_3);
			break;
		}
		case 4:
		{
			print_string_5x8(25,4,STR_4);
			break;
		}
		case 5:
		{
			print_string_5x8(25,5,STR_5);
			break;
		}
		case 6:
		{
			print_string_5x8(25,6,STR_6);
			break;
		}
		case 7:
		{
			print_string_5x8(25,7,STR_7);
			break;
		}
		default:
		{
			clear_oled();
			return;
		}
	}
}
void start_menu(void)
{
	oled_write(0,0x21); // Установка столбца
	oled_write(0,0);    // Начальный адрес
	oled_write(0,127);  // Конечный адрес

	oled_write(0,0x22); // Установка строки
	oled_write(0,0);    // Начальный адрес
	oled_write(0,7);    // Конечный адрес
	
	TWI_StartCondition();
	TWI_Send_address(ADDRESS);
	TWI_SendByte(NEXT_DATA);
	uint16_t i=0;
	for (i=0;i<72;i++)
	{
		TWI_SendByte(0xff);
	}
	TWI_StopCondition();
	_delay_ms(DELAY_START);
	clear_oled();
	for(uint8_t i=0;i<8;i++)
	{
		set_menu(i);	
		set_value(i,0);	
	}
	screen_update();
}
void set_value(uint8_t str, int16_t val)
{
	char buffer[8]={0};
	itoa(val,buffer,10);
	print_string_5x8(100,str,"    ");
	switch(str)
	{
		case 0:
		{
			print_string_5x8(100,0,buffer);
			break;		
		}
		case 1:
		{
			print_string_5x8(100,1,buffer);
			break;
		}
		case 2:
		{
			print_string_5x8(100,2,buffer);
			break;
		}
		case 3:
		{
			print_string_5x8(100,3,buffer);
			break;
		}
		case 4:
		{
			print_string_5x8(100,4,buffer);
			break;
		}
		case 5:
		{
			print_string_5x8(100,5,buffer);
			break;
		}
		case 6:
		{
			print_string_5x8(100,6,buffer);
			break;
		}
		case 7:
		{
			print_string_5x8(100,7,buffer);
			break;
		}
		default:
		{
			clear_oled();
			return;
		}
	}
}