/*
  程序说明: 单总线驱动程序
  软件环境: Keil uVision 4.10 
  硬件环境: CT107单片机综合实训平台
  日    期: 2011-8-9
*/

#include "common.h"

#define uchar unsigned char
#define uint unsigned int

uint8_t TEMperature;
//单总线延时函数
void Delay_OneWire(unsigned int t)
{
	unsigned char i;
	while(t--)
	{
	_nop_();
	i = 11;
	while (--i);
	}
}

//DS18B20芯片初始化
bit Init_DS18B20(void)
{
	bit initflag = 0;
	DQ = 1;
	Delay_OneWire(12);
	DQ = 0;
	Delay_OneWire(80); 
	DQ = 1;
	Delay_OneWire(10); 
	initflag = DQ;    
	Delay_OneWire(5);
  
	return initflag;
}

//通过单总线向DS18B20写一个字节
void Write_DS18B20(unsigned char dat)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		DQ = 0;
		DQ = dat&0x01;
		Delay_OneWire(5);
		DQ = 1;
		dat >>= 1;
	}
	Delay_OneWire(5);
}

//从DS18B20读取一个字节
unsigned char Read_DS18B20(void)
{
	unsigned char i;
	unsigned char dat;
  
	for(i=0;i<8;i++)
	{
		DQ = 0;
		dat >>= 1;
		DQ = 1;
		if(DQ)
		{
			dat |= 0x80;
		}	    
		Delay_OneWire(5);
	}
	return dat;
}

float read_temperature_f()
{
	uint temp;
	float temperature;
	uchar low,high;

	ET0 = 0;
	Init_DS18B20();
	Write_DS18B20(0xcc);
	Write_DS18B20(0x44);
	Delay_OneWire(200);

	Init_DS18B20();
	Write_DS18B20(0xcc);
	Write_DS18B20(0xbe);

	low=Read_DS18B20();
	high=Read_DS18B20();
	ET0 = 1;
//	temp=(high<<4)|(low>>4);
//	return temp;
	temp=high;
	temp<<=8;
	temp|=low;
	temperature = temp*0.0625;
 	return temperature;		
}

void READ_18B20(void)
{
 if(MIS_TEMP&&READ_temp_E) 
	{
		TEMperature=(uint8_t)(read_temperature_f());
		CLS_MIS(MIS_TEMP);
	}
}