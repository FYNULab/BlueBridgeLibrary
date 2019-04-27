#ifndef _B_SMG_H_
#define _B_SMG_H_

#define _SPACE_  11
#define _POINT_  12
#define _LINE_   10
#define SELF_MOTION   0xFC

#define TIME_PART 0
#define TEMP_PART 1
#define ADC_PART  2
#define SET_PART  3

code unsigned char SMG_TAB[];
extern uint8_t dspbuf[8];
extern uint8_t PART_ROM[4][8];
extern uint8_t dspcom;
extern uint8_t SMG_LAST_PART;

extern bit READ_temp_E;
extern bit READ_time_E;
extern bit READ_ADC_E;
extern bit SET_DATA_E;



extern void OS_Display(void);
extern void DIS_ROM_Init(void);
extern void PartDis_Manage(uint8_t PART_NUM,uchar ch[]);
extern void Switch_DISPart(uint8_t PART_NUM);
extern void DataDis_Manage(uint8_t PART_NUM,uint16_t DATA,uint8_t DIG,uint8_t location);
extern void SMGFlash_Manage(uint8_t PART_NUM);


#endif
