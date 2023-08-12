#include "ADC.h"

void ini_ADC_hand(void)
{
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); //�������� ��� �������� 128 125���
	ADMUX|=(0<<REFS1)|(1<<REFS0);	//�������� ������� ���������� ������� external capacitor at AREF
}
uint16_t return_ADC_hand(void)
{
	ADCSRA|=(1<<ADSC);
	while((ADCSRA&(1<<ADSC)));	
	return ADC;
}
void ini_ADC_isr()
{
	DDRC&=~(1<<0);
	PORTC&=~(1<<0);
	ADCSRA|=(1<<ADEN)							//������������� ���
			|(1<<ADSC)							//������ ��������������
			|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)	//�������� 128 125���
			|(1<<ADIE)							//��������� ���������� �� ���
			|(1<<ADATE);
	ADMUX|=(0<<REFS1)|(1<<REFS0);		//�������� ������� ���������� ������� ADC0(PC0)
}
void return_ADC_isr(VAL_ADC *data)
{
	data->val=(data->hi_ADC<<8)+data->lo_ADC;
}
