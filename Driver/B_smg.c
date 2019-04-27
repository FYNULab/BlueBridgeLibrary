#include "common.h"
//{0,1,2,3,4,5,6,7,8,9,-,space,.}
code unsigned char SMG_TAB[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xbf,0xff,0x7f};
uint8_t PART_ROM[4][8];
uint8_t SMG_LAST_PART=0;
uint8_t dspbuf[8]={_SPACE_,_SPACE_,_SPACE_,_SPACE_,_SPACE_,_SPACE_,_SPACE_,_SPACE_};  //œ‘ æª∫≥Â«¯
uint8_t dspcom=0;

bit READ_temp_E=0;
bit READ_time_E=0;
bit READ_ADC_E=0;
bit SET_DATA_E=0;


void DIS_ROM_Init(void)
{
	uint8_t i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
			PART_ROM[i][j]=_SPACE_;
	}
}

void OS_Display(void)
{ 
  if(MIS_DISPLAY) 
	{		
		SELECT_SMG_D;
		OPERAT(SMG_TAB[_SPACE_]);
		SELECT_CLS;

		OPERAT(1<<dspcom);	
		SELECT_SMG_W; 
		SELECT_CLS;
	
		OPERAT(SMG_TAB[dspbuf[dspcom]]);	
		SELECT_SMG_D; 
		SELECT_CLS;
	
    if(++dspcom == 8)
		{
        dspcom = 0;
    	}
		CLS_MIS(MIS_DISPLAY);
	}		
}


void PartDis_Manage(uint8_t PART_NUM,uchar ch[])
{
	uint8_t j=0;
  while (ch[j]!='\0')
  {
   if(ch[j]==' ')
	 {
		 PART_ROM[PART_NUM][j]=_SPACE_;
	 }
	if(ch[j]=='-')
	 {
		 PART_ROM[PART_NUM][j]=_LINE_;
	 }	 
  	j++;
  }

}
void SMGFlash_Manage(uint8_t PART_NUM)
{
	uint8_t j;
   if(_SECOND%2)
  {
     for(j=0;j<8;j++)
	 {
	 	if(PART_ROM[PART_NUM][j]==_LINE_)
  	 	{
			PART_ROM[PART_NUM][j]=_SPACE_;
		}
	 }
  }
  else
  {
  	for(j=0;j<8;j++)
	 {
	 	if(PART_ROM[PART_NUM][j]==_SPACE_)
  	 	{
			PART_ROM[PART_NUM][j]=_LINE_;
		}
	 }
  }
}

void DataDis_Manage(uint8_t PART_NUM,uint16_t DATA,uint8_t DIG,uint8_t location)
{
	uint8_t i=0,digit;
	uint8_t tran[5];
	

	tran[0]=DATA/10000;
	tran[1]=(DATA%10000)/1000;
	tran[2]=(DATA%1000)/100;
	tran[3]=(DATA%100)/10;
	tran[4]=DATA%10;
	
	if(DIG==SELF_MOTION)
	{
		while(tran[i++]==0);
		digit=6-i;
	}
	else
	{
		digit=DIG;
	}
	
		for(i=5-digit;i<5;i++)
		  PART_ROM[PART_NUM][location++]=tran[i];
	
}


void Switch_DISPart(uint8_t PART_NUM)
{
	uint8_t i;
	for(i=0;i<8;i++)
	{
		dspbuf[i]=PART_ROM[PART_NUM][i];
	}
	switch(PART_NUM)
	{
		case TIME_PART:		 
		 	READ_temp_E=0;
 			READ_time_E=1;
 			READ_ADC_E=0;
			SET_DATA_E=0;
			break;
		case TEMP_PART:
			READ_temp_E=1;
 			READ_time_E=0;
 			READ_ADC_E=0;
			SET_DATA_E=0;		 
			break;
		case ADC_PART:	
			READ_temp_E=0;
 			READ_time_E=0;
 			READ_ADC_E=1;
			SET_DATA_E=0;	 
			break;
		case SET_PART:
			READ_temp_E=0;
 			READ_time_E=0;
 			READ_ADC_E=0;
			SET_DATA_E=1;		 
			break;
		default:
			READ_temp_E=0;
 			READ_time_E=0;
 			READ_ADC_E=0;
			SET_DATA_E=0;		 
			break;
	}
}
