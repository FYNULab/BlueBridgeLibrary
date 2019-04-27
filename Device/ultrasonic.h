#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_


#define somenop {_nop_();_nop_();_nop_();_nop_();_nop_();\
                 _nop_();_nop_();_nop_();_nop_(); _nop_();}

sbit TX = P1^0;  //发射引脚
sbit RX = P1^1;  //接收引脚

extern uint16_t DIStance;

void send_wave(void);
void READ_ULTR(void);


#endif