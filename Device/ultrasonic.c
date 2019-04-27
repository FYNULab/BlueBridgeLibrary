#include "common.h"
//TX引脚发送40KHz方波信号驱动超声波发送探头
uint16_t DIStance;
void send_wave(void)
{
	unsigned char i = 8;  //发送8个脉冲
	
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
 /** 200毫秒更新一次数据 */
		if(MIS_ULT)
        {
            
            /** 关闭定时器0中断:计算超声波发送到返回的时间 */
 			ET0 = 0;
            send_wave();  //发送方波信号
            TR1 = 1;  //启动计时
			while((RX == 1) && (TF1 == 0));  //等待收到脉冲
			TR1 = 0;  //关闭计时

			//发生溢出
			if(TF1 == 1)
			{
				TF1 = 0;
				DIStance = 9999;  //无返回
			}
			else
			{
				/**  计算时间  */
				t = TH1;
				t <<= 8;
				t |= TL1;
				DIStance = (unsigned int)(t*0.018);  //计算距离				
			}
			TH1 = 0;
			TL1 = 0;
        }
		MIS_ULT = 0;
	    ET0 = 1;  
                 
}

