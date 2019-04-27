#ifndef _B_LED_H_
#define _B_LED_H_

#define LTH_1	  0xa0
#define LTH_2	  0xc0
#define LTL_1	  0x0a
#define LTL_2	  0x0c
extern uint8_t LED_State;
extern uint16_t Flashing_Cycle;
extern uint8_t LED_S;
extern bit LED_ENABLE;
extern bit ROLL_CRL;

extern void LED_CLS(void);
extern void LED_ACTION(void);
extern void LED_STA_CHANGE(uint8_t State);

#endif