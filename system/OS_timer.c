#include "common.h"

bit MIS_DISPLAY=0;
bit MIS_ADC=0;
bit MIS_TEMP=0;
bit MIS_ULT=0;
bit MIS_KEY=0;
bit MIS_LED=0;
bit MIS_LED_STA=0;


void Timer0Init_500us(void)		//0.5����@11.0592MHz
{
	AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0x66;		//??????
	TH0 = 0xEA;		//??????
	TH1 = 0;
	TL1 = 0;
	TF0 = 0;		//���TF0��־
	TF1 = 0;
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;
	EA = 1;
}

