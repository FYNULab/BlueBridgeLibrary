#ifndef _573CH_H_
#define _573CH_H_

#define SELECT_LED   P2=((P2&0x1f)|0x80) 
#define SELECT_SMG_D P2=((P2&0x1f)|0xE0)
#define SELECT_SMG_W P2=((P2&0x1f)|0xC0)
#define SELECT_FAC   P2=((P2&0x1f)|0xA0)
#define SELECT_CLS   P2&=0x1f;
#define OPERAT(x)    P0=(x)  
#define BUZZER_  	 0x40
#define RELAY_  	 0x10
#define MOTOR_  	 0x20
#define UP  	     1
#define DOWN  	     0

extern uint8_t PREVIOUS_FAC;
extern void Operat_FAC(uint8_t state);
extern void FAC_CLS(void);
extern void FACAction_Manager(uint8_t OBJECT,uint8_t DATA,uint8_t ACT_line,bit UPorDOWN,bit flag);

#endif
