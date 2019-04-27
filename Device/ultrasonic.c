#include "common.h"
//TX���ŷ���40KHz�����ź���������������̽ͷ
uint16_t DIStance;
void send_wave(void)
{
	unsigned char i = 8;  //����8������
	
	do
	{
		TX = 1;
		somenop;
		TX = 0;
		somenop;
	}
	while(i--);
}

void READ_ULTR(void)
{
	uint16_t t = 0;
 /** 200�������һ������ */
		if(MIS_ULT)
        {
            
            /** �رն�ʱ��0�ж�:���㳬�������͵����ص�ʱ�� */
 			ET0 = 0;
            send_wave();  //���ͷ����ź�
            TR1 = 1;  //������ʱ
			while((RX == 1) && (TF1 == 0));  //�ȴ��յ�����
			TR1 = 0;  //�رռ�ʱ

			//�������
			if(TF1 == 1)
			{
				TF1 = 0;
				DIStance = 9999;  //�޷���
			}
			else
			{
				/**  ����ʱ��  */
				t = TH1;
				t <<= 8;
				t |= TL1;
				DIStance = (unsigned int)(t*0.018);  //�������				
			}
			TH1 = 0;
			TL1 = 0;
        }
		MIS_ULT = 0;
	    ET0 = 1;  
                 
}

