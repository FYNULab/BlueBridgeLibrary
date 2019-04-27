#include "common.h"

bit MIS_DISPLAY=0;
bit MIS_ADC=0;
bit MIS_TEMP=0;
bit MIS_ULT=0;
bit MIS_KEY=0;
bit MIS_LED=0;
bit MIS_LED_STA=0;


void Timer0Init_500us(void)		//0.5毫秒@11.0592MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x66;		//??????
	TH0 = 0xEA;		//??????
	TH1 = 0;
	TL1 = 0;
	TF0 = 0;		//清除TF0标志
	TF1 = 0;
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
	EA = 1;
}

