/**
		实现蓝牙发送数据控制电机电机正转和反转 以及 改变转速
		发送	0	实现顺时针正转
					1	实现逆时针反转
					2	实现转速为慢速
					3	实现转速为中速
					4	实现转速为快速
		运用的LCD1602作为显示
					E = P2 ^ 7;		//1602使能引脚
					RW = P2 ^ 6;		//1602读写引脚
					RS = P2 ^ 5;		//1602数据/命令选择引脚
		如有不同在lcd.h中修改引脚参数
		**重要：
				因为用的ULN2003芯片，所以对应的引脚
					IN1	--	P1^6
					IN2	--	P1^5
					IN3	--	P1^4
					IN4	--	P1^3
					OUT1	--	橙色线
					OUT2	--	黄色线
					OUT3	--	粉色线
					OUT4	--	蓝色线
				剩下红色接VCC，建议LCD1602和步进电机以及单片机都分开供电
		
**/
#include "123.h"

main()
{
		L1602_init();
    Delay(100);
    UartInit();
    while(1)
    {
       if(flag == 0)
        {
					led = 0;
					
					forward(speed);
					
					if(speed == 1)
					{
					 LCD_display("Mo Dir: Goto","Mo Spd: Fast ^_^");
					}
					
					else if(speed == 3)
					{
					 LCD_display("Mo Dir: Goto","Mo Spd: Norl ^_^");
					}
					
					else if(speed == 5)
					{
					 LCD_display("Mo Dir: Goto","Mo Spd: Slow ^_^");
					}
//					switch(speed)		//switch无法实现不知道为什么，知道的大佬求解释
//					{
//				case'1':
//					LCD_display("Mo Dir: Goto","Mo Spd: Fast ^_^");
//				case'2':
//					LCD_display("Mo Dir: Goto","Mo Spd: Norl ^_^");
//				case'3':
//					LCD_display("Mo Dir: Goto","Mo Spd: Slow ^_^");
//					}
        }


       if(flag == 1)
        {
          led = 1;
					back(speed);
					if(speed == 1)
					{
					 LCD_display("Mo Dir: Back","Mo Spd: Fast ^_^");
					}
					else if(speed == 3)
					{
					 LCD_display("Mo Dir: Back","Mo Spd: Norl ^_^");
					}
					else if(speed == 5)
					{
					 LCD_display("Mo Dir: Back","Mo Spd: Slow ^_^");
					}
//				switch(speed)
//					{
//				case'1':
//					LCD_display("Mo Dir: Back","Mo Spd: Fast ^_^");
//				break;
//				case'2':
//					LCD_display("Mo Dir: Back","Mo Spd: Norl ^_^");
//				break;
//				case'3':
//					LCD_display("Mo Dir: Back","Mo Spd: Slow ^_^");
//				break;
//					}
        }

    }
}

void Usart() interrupt 4
{
    uchar n; //定义临时变量
//	led = 1;
    if(RI) //判断是接收中断产生
    {
        RI = 0; //标志位清零
        n = SBUF; //读入缓冲区的值
        switch(n)
        {
        case'0':		//控制正转
          flag = 0;
         break;
				
        case'1':		//控制反转
          flag = 1;
         break;
				
				case'2':		//控制速度为慢
					speed = 5;
				break;
				
				case'3':		//控制速度为中等
					speed = 3;
				break;
				
				case'4':		//控制速度为快
					speed = 1;
				break;
				
        }
        TI = 1;
        SBUF = n; //把接收到的值再发回
    }
    if(TI) //如果是发送标志位，清零
        TI = 0;
}