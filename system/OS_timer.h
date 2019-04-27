/*************************************************************************
$
$ Project:Blue bridge cup program framework.
$ Developed by Electronic Innovation Lab Team Assassin.
$ B_OS 0.9 EarlyAccess.
$ FYNC Electronic Innovation Lab all rights reserved.
$									                         2017_12_04
*************************************************************************/
#ifndef _OS_TIMER_H_
#define _OS_TIMER_H_

#define SET_MIS(x)   x=1
#define CLS_MIS(x)   x=0

#define WHEN_COUNT_T(x)  if((count%x)==0)
#define WHEN_ICT_T(x)    if((ict%x)==0)

extern bit MIS_DISPLAY;
extern bit MIS_ADC;
extern bit MIS_TEMP;
extern bit MIS_ULT;
extern bit MIS_KEY;
extern bit MIS_LED;
extern bit MIS_LED_STA;

extern void Timer0Init_500us(void);


#endif
