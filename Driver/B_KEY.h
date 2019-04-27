#ifndef _B_KEY_H_
#define _B_KEY_H_

#define KEY P3
#define NO_KEY  0xff  //无按键按下
#define KEY_STATE0  0   //判断按键按下
#define KEY_STATE1  1  //确认按键按下
#define KEY_STATE2  2  //释放

#define LED_CONT	0x01
#define SMG_PART	0xc1
#define PART_SWC	0xca
#define MA_INPUT	0xa0
#define DATA_ADD	0x90
#define DATA_SUB    0x9c

extern uint8_t KEY_VAL;
extern uint8_t KEY_CONCLUDE;
extern uint8_t keybuf[8];
extern uint8_t keycom;
extern bit input_f;
extern uint8_t Key_Scan(void);
extern void REED_INPUT_KEY(void);
extern void KEYFunc_Manager(uint8_t KEY_NUM,uint8_t FUNC_TYPE,uint8_t DATA,uint8_t FUNC_ARGU);


#endif