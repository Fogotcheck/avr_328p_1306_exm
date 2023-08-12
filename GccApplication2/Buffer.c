#include "Buffer.h"
extern volatile CIRC_BUFFER buffer;
void ini_buffer(uint8_t *buf, uint16_t len)
{
	buffer.head=&buf[0];
	buffer.data=&buf[0];
	buffer.tail=&buf[len-1];
	buffer.size=0;
	//printf("head=%p\ndata=%p\ntail=%p\n",buffer.head,buffer.data,buffer.tail);
}
void push_byte(uint8_t data)
{
	buffer.data=buffer.data>=buffer.tail?buffer.head:buffer.data;
 	*buffer.data=data;
 	buffer.data++;
 	buffer.size++;
}
void clean_buf(void)
{
	if (buffer.size==0)
	{
		return;
	}
	usart0_transmit_data(buffer.head,buffer.size);
	buffer.size=0;
	buffer.data=buffer.head;
}
