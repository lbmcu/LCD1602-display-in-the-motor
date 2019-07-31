#include "motor.h"

unsigned char code F_Rotation[]={0x08,0x18,0x10,0x30,0x20,0x60,0x40,0x48,0x00};    //顺时针转
unsigned char code B_Rotation[]={0x48,0x40,0x60,0x20,0x30,0x10,0x18,0x08,0x00};    //逆时针转

int forward(uchar speed)		//控制正转
{
    uchar i;
//	uint k = 0;
//	for(k=0;k<64;k++)
//	{
    for(i = 0; i < 8; i++)
    {
        P1 = F_Rotation[i];		//顺时针转动
        Delay(speed);					//改变转速
    }
//		switch(speed)
//		{
//			case'1':
//				L1602_string(2, 1, "Mo Spd: Fast");
//			case'3':
//				L1602_string(2, 1, "Mo Spd: Norm");
//			case'5':
//				L1602_string(2, 1, "Mo Spd: Slow");
//		}
//	}
		return speed;
}


int back(uchar speed)		//控制反转
{
    uchar i;
//	uint k = 0;
//	for(k=0;k<64;k++)
//			{
    for(i = 0; i < 8; i++)
    {
        P1 = B_Rotation[i];	 //逆时针转动
        Delay(speed);							//改变转速
    }
//		switch(speed)
//					{
//						case'1':
//							    L1602_init();
//							L1602_string(2, 1, "Mo Spd: Fast");
//						case'2':
//							    L1602_init();
//							L1602_string(2, 1, "Mo Spd: Norm");
//						case'3':
//							    L1602_init();
//							L1602_string(2, 1, "Mo Spd: Slow");
//					}
			return speed;
//			}
}