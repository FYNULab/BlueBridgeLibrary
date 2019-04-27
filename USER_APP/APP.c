#include "common.h"

void USER_INIT(void)
{
	DIS_ROM_Init();//缓存区初始化
	FAC_CLS();//附加设备初始化 
	LED_CLS();//LED模块初始化

	LED_ENABLE=0;//LED使能位  1开启 0关闭
	ROLL_CRL=0;//流水灯功能开关
	LED_S=0;//LED初始动作位置
	Flashing_Cycle=0;//闪烁间隔  单位ms

	set_1302(23,12,50);//DS1302时间设定，依次 时 分 秒

	init_pcf8591(POTENT_Rb2);//ADC8591初始化  当前选择RB2可调电阻
	
  	Timer0Init_500us();//定时器中断设置
	
  	PartDis_Manage(TIME_PART,"  -  -  ");//缓存区格式设定
	PartDis_Manage(TEMP_PART,"  ------");
	PartDis_Manage(SET_PART,"-    -  ");
	PartDis_Manage(ADC_PART,"--      ");
}

void KEYBOARD(void)
{
	//按键功能管理  变量依次为 按键编号，功能，操作1，操作2(主)		
	KEYFunc_Manager(4,PART_SWC,TEMP_PART,TIME_PART);
	KEYFunc_Manager(5,PART_SWC,SET_PART,ADC_PART);
	KEYFunc_Manager(11,MA_INPUT,0,1);
	KEYFunc_Manager(15,MA_INPUT,0,2);
	KEYFunc_Manager(19,MA_INPUT,0,3);
	KEYFunc_Manager(10,MA_INPUT,0,4);
	KEYFunc_Manager(14,MA_INPUT,0,5);
	KEYFunc_Manager(18,MA_INPUT,0,6);
	KEYFunc_Manager(9,MA_INPUT,0,7);
	KEYFunc_Manager(13,MA_INPUT,0,8);
	KEYFunc_Manager(17,MA_INPUT,0,9);
	KEYFunc_Manager(12,MA_INPUT,0,0);

}

void APP(void)
{
   		REED_INPUT_KEY();//读取按键
		READ_18B20();//读取18b20
		READ_DS1302();//读取1302
		READ_ADC();//读取AD
//		READ_ULTR();//读取超声波距离，使用时会少许干扰主时序
		//附加设备功能管理  变量依次为 设备名称，检测数值，阀值，阀值以上或以下触发动作，所用标志位
		FACAction_Manager(RELAY_,adc_value,150,UP,RELAY_F);
//
		KEYBOARD();

		//数据显示功能管理  变量依次为 缓存区域，显示变量，数据位数，数据首部所在位置 
		DataDis_Manage(TIME_PART,_HOUR,2,0);
		DataDis_Manage(TIME_PART,_MINUTE,2,3);
		DataDis_Manage(TIME_PART,_SECOND,2,6);
		DataDis_Manage(ADC_PART,adc_value,3,3);
			
		DataDis_Manage(SET_PART,keybuf[0],1,1);
		DataDis_Manage(SET_PART,keybuf[1],1,2);
		DataDis_Manage(SET_PART,keybuf[2],1,6);			   
		DataDis_Manage(SET_PART,keybuf[3],1,7);
		
		DataDis_Manage(TEMP_PART,TEMperature,2,0);
		SMGFlash_Manage(TIME_PART);//数码管横杠闪烁   变量为 功能页		
		

		LED_STA_CHANGE(LED_S);//LED状态刷新
		OS_Display();//系统显示刷新
		LED_ACTION();//LED动作刷新
}