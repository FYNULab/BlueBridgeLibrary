#include "common.h"

void USER_INIT(void)
{
	DIS_ROM_Init();//��������ʼ��
	FAC_CLS();//�����豸��ʼ�� 
	LED_CLS();//LEDģ���ʼ��

	LED_ENABLE=0;//LEDʹ��λ  1���� 0�ر�
	ROLL_CRL=0;//��ˮ�ƹ��ܿ���
	LED_S=0;//LED��ʼ����λ��
	Flashing_Cycle=0;//��˸���  ��λms

	set_1302(23,12,50);//DS1302ʱ���趨������ ʱ �� ��

	init_pcf8591(POTENT_Rb2);//ADC8591��ʼ��  ��ǰѡ��RB2�ɵ�����
	
  	Timer0Init_500us();//��ʱ���ж�����
	
  	PartDis_Manage(TIME_PART,"  -  -  ");//��������ʽ�趨
	PartDis_Manage(TEMP_PART,"  ------");
	PartDis_Manage(SET_PART,"-    -  ");
	PartDis_Manage(ADC_PART,"--      ");
}

void KEYBOARD(void)
{
	//�������ܹ���  ��������Ϊ ������ţ����ܣ�����1������2(��)		
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
   		REED_INPUT_KEY();//��ȡ����
		READ_18B20();//��ȡ18b20
		READ_DS1302();//��ȡ1302
		READ_ADC();//��ȡAD
//		READ_ULTR();//��ȡ���������룬ʹ��ʱ�����������ʱ��
		//�����豸���ܹ���  ��������Ϊ �豸���ƣ������ֵ����ֵ����ֵ���ϻ����´������������ñ�־λ
		FACAction_Manager(RELAY_,adc_value,150,UP,RELAY_F);
//
		KEYBOARD();

		//������ʾ���ܹ���  ��������Ϊ ����������ʾ����������λ���������ײ�����λ�� 
		DataDis_Manage(TIME_PART,_HOUR,2,0);
		DataDis_Manage(TIME_PART,_MINUTE,2,3);
		DataDis_Manage(TIME_PART,_SECOND,2,6);
		DataDis_Manage(ADC_PART,adc_value,3,3);
			
		DataDis_Manage(SET_PART,keybuf[0],1,1);
		DataDis_Manage(SET_PART,keybuf[1],1,2);
		DataDis_Manage(SET_PART,keybuf[2],1,6);			   
		DataDis_Manage(SET_PART,keybuf[3],1,7);
		
		DataDis_Manage(TEMP_PART,TEMperature,2,0);
		SMGFlash_Manage(TIME_PART);//����ܺ����˸   ����Ϊ ����ҳ		
		

		LED_STA_CHANGE(LED_S);//LED״̬ˢ��
		OS_Display();//ϵͳ��ʾˢ��
		LED_ACTION();//LED����ˢ��
}