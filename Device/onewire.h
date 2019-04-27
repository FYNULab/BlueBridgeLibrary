#ifndef _ONEWIRE_H
#define _ONEWIRE_H

#include "STC15F2K60S2.h"

#define OW_SKIP_ROM 0xcc
#define DS18B20_CONVERT 0x44
#define DS18B20_READ 0xbe

//IC���Ŷ���
sbit DQ = P1^4;

extern uint8_t TEMperature;

//��������
void Delay_OneWire(unsigned int t);
void Write_DS18B20(unsigned char dat);
bit Init_DS18B20(void);
unsigned char Read_DS18B20(void);
float read_temperature_f(void);
extern void READ_18B20(void);

#endif