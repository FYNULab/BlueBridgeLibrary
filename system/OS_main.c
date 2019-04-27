/*************************************************************************
$
$ Project:Blue Bridge Cup Program Framework.
$ Developed by Electronic Innovation Lab Team Assassin.
$ B_OS 0.93 EarlyAccess.
$ FYNC Electronic Innovation Lab all rights reserved.
$									                         2017_12_17
*************************************************************************/
#include "common.h"

uint8_t	count=0;
uint8_t	ict=0;

void main()
{
  USER_INIT();//用户自定义初始化		
  while(1)
  {	
  	APP();//用户自定义系统功能	
  }
}


/**************************************************************************

**************************************************************************/

void Timer0_isr(void) interrupt 1
{
	
	 count++;
	WHEN_COUNT_T(1)//count每走1 即每500ms，以下类推
	{
	   MIS_DISPLAY=1;//显示刷新任务就绪装载，以下类推
	}
	WHEN_COUNT_T(7)
	{
	   MIS_KEY=1;
	}
	WHEN_COUNT_T(8)
	{
		ict++;
	   MIS_LED=1;
	   WHEN_ICT_T((Flashing_Cycle/4))
	   {
			MIS_LED_STA=1;
	   }
	   WHEN_ICT_T(100)
		{
			MIS_ULT=1;
		}
	   WHEN_ICT_T(250)
		{
			MIS_TEMP=1;
		}
	 	if(ict>250)
  		ict=0;
	}
	WHEN_COUNT_T(40)
	{
	   MIS_ADC=1;
	}
	 if(count>54)
  	count=0;
}

/******************************************************
$
$Project end.
$Copyright @T_ASN
$
******************************************************/