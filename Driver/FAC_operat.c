#include "common.h"

bit	RELAY_F=0;
bit	BUZZER_F=0;
uint8_t PREVIOUS_FAC;

void FAC_CLS(void)
{
	SELECT_CLS;
	OPERAT(0x00);
	PREVIOUS_FAC=0x00;
	SELECT_FAC;
	SELECT_CLS;
	OPERAT(0xff);
}

void Operat_FAC(uint8_t state)
{
	uint8_t ch;
	ch=PREVIOUS_FAC ^ state;

	SELECT_CLS;
	OPERAT(ch);
	PREVIOUS_FAC=ch;
	SELECT_FAC;

	SELECT_CLS;
	OPERAT(0xff);	
}
void FACAction_Manager(uint8_t OBJECT,uint8_t DATA,uint8_t ACT_line,bit UPorDOWN,bit flag)
{
 if(UPorDOWN==UP)
 {
	if((DATA>ACT_line)&&(flag==0))
	{
		Operat_FAC(OBJECT);
		switch(OBJECT)
		{
			case RELAY_:  RELAY_F=1; break;
			case BUZZER_: BUZZER_F=1; break;
			default: break;
		}
	}
	else if((DATA>ACT_line)&&(flag==1));
	else if((DATA<=ACT_line)&&(flag==1))
	{
		Operat_FAC(OBJECT);
		switch(OBJECT)
		{
			case RELAY_:  RELAY_F=0; break;
			case BUZZER_: BUZZER_F=0; break;
			default: break;
		}
	}
	else;
  }
  else if(UPorDOWN==DOWN)
  {
	if((DATA<ACT_line)&&(flag==0))
	{
		Operat_FAC(OBJECT);
		switch(OBJECT)
		{
			case RELAY_:  RELAY_F=1; break;
			case BUZZER_: BUZZER_F=1; break;
			default: break;
		}
	}
	else if((DATA<ACT_line)&&(flag==1));
	else if((DATA>=ACT_line)&&(flag==1))
	{
		Operat_FAC(OBJECT);
		switch(OBJECT)
		{
			case RELAY_:  RELAY_F=0; break;
			case BUZZER_: BUZZER_F=0; break;
			default: break;
		}
	}
	else;
  }
}