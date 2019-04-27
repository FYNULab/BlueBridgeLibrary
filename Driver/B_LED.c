#include "common.h"
uint8_t LED_State=0xff;
uint16_t Flashing_Cycle;
uint8_t LED_S;
bit LED_ENABLE=0;
bit ROLL_CRL=0;

void LED_CLS(void)
{
		OPERAT(0xff);	
		SELECT_LED; 
		SELECT_CLS;	
}
void LED_ACTION(void)
{
	if(MIS_LED&&LED_ENABLE) 
	{					
		OPERAT(LED_State);	
		SELECT_LED; 
		SELECT_CLS;
	
		CLS_MIS(MIS_LED);
	}		
}

void LED_STA_CHANGE(uint8_t State)
{
	if(MIS_LED_STA) 
	{					
		LED_State^=(1<<State);
	
		CLS_MIS(MIS_LED_STA);
		if(ROLL_CRL)
			{
				LED_S++;
				if(LED_S>=8)
				LED_S=0;
			}
	}	

}


