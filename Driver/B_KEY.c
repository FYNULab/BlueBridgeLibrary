#include "common.h"
uint8_t KEY_VAL;
uint8_t	KEY_CONCLUDE;
uint8_t keybuf[8]={0,0,0,0,0,0,0,0};
uint8_t keycom=0;
bit input_f=0;
uint8_t Key_Scan(void)
{
	
    static uint8_t key_state=KEY_STATE0;
    uint8_t key_value=0,key_temp;
    uint8_t key1,key2;
	if(MIS_KEY) 
	{
    P30=0;
    P31=0;
    P32=0;
    P33=0;
    P34=1;
    P35=1;
    P42=1;
    P44=1;
    if(P44==0)	key1=0x70;
    if(P42==0)	key1=0xb0;
    if(P35==0)	key1=0xd0;
    if(P34==0)	key1=0xe0;
    if((P34==1)&&(P35==1)&&(P42==1)&&(P44==1))	key1=0xf0;

    P30=1;
    P31=1;
    P32=1;
    P33=1;
    P34=0;
    P35=0;
    P42=0;
    P44=0;
    if(P30==0)	key2=0x0e;
    if(P31==0)	key2=0x0d;
    if(P32==0)	key2=0x0b;
    if(P33==0)	key2=0x07;
    if((P30==1)&&(P31==1)&&(P32==1)&&(P33==1))	key2=0x0f;
    key_temp=key1|key2;

    switch(key_state)
    {
    case KEY_STATE0:
        if(key_temp!=NO_KEY)
        {
            key_state=KEY_STATE1;
        }
        break;

    case KEY_STATE1:
        if(key_temp==NO_KEY)
        {
            key_state=KEY_STATE0;
        }
        else
        {
            switch(key_temp)
            {
            case 0x77:
                key_value=4;
                break;
            case 0x7b:
                key_value=5;
                break;
            case 0x7d:
                key_value=6;
                break;
            case 0x7e:
                key_value=7;
                break;

            case 0xb7:
                key_value=8;
                break;
            case 0xbb:
                key_value=9;
                break;
            case 0xbd:
                key_value=10;
                break;
            case 0xbe:
                key_value=11;
                break;

            case 0xd7:
                key_value=12;
                break;
            case 0xdb:
                key_value=13;
                break;
            case 0xdd:
                key_value=14;
                break;
            case 0xde:
                key_value=15;
                break;

            case 0xe7:
                key_value=16;
                break;
            case 0xeb:
                key_value=17;
                break;
            case 0xed:
                key_value=18;
                break;
            case 0xee:
                key_value=19;
                break;
            }
            key_state=KEY_STATE2;
        }
        break;

    case KEY_STATE2:
        if(key_temp==NO_KEY)
        {
            key_state=KEY_STATE0;
        }
        break;
    }
	}
	CLS_MIS(MIS_KEY);
    return key_value;
	
}

void REED_INPUT_KEY(void)
{
	KEY_VAL=Key_Scan();
   //if(KEY_VAL!=0)
	//	KEY_CONCLUDE=KEY_VAL;
}

void KEYFunc_Manager(uint8_t KEY_NUM,uint8_t FUNC_TYPE,uint8_t DATA,uint8_t FUNC_ARGU)
{
    if(KEY_VAL==KEY_NUM)
	{
	  switch(FUNC_TYPE)
	  {
	  	case SMG_PART:
			Switch_DISPart(FUNC_ARGU);
			SMG_LAST_PART=FUNC_ARGU;
			break;



	 	case PART_SWC:
	  		if(SMG_LAST_PART==FUNC_ARGU)
			{
		 		Switch_DISPart(DATA);
		 		SMG_LAST_PART=DATA;
			}
			else if(SMG_LAST_PART==DATA)
			{
		 		Switch_DISPart(FUNC_ARGU);
				SMG_LAST_PART=FUNC_ARGU;
			}
			else
		 		SMG_LAST_PART=FUNC_ARGU;
			break;



	  	case MA_INPUT:
			if((input_f==0)&&SET_DATA_E)
			{
				keybuf[keycom]=FUNC_ARGU;
				input_f=1;
				if(++keycom == Input_com)
				{
        			keycom = 0;
    			}
			}
			break;
	  }
	}
	else 
		Switch_DISPart(SMG_LAST_PART);
		input_f=0;		
}

