#ifndef __BUFFER_H
#define __BUFFER_H

#include "Config.h"
typedef struct
{
	uint8_t *head;
	uint8_t *tail;
	uint8_t *data;
	uint16_t size;	
}CIRC_BUFFER;


void ini_buffer(uint8_t *buf, uint16_t len);
void push_byte(uint8_t data);
void clean_buf(void);
#endif //__BUFFER_H