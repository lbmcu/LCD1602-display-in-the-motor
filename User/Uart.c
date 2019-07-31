#include "Uart.h"

/**
		开启串口定时器，且设置波特率为9600
**/
void UartInit()		//9600bps@11.0592MHz
{
    SCON = 0x50; // SCON: 模式1, 8-bit UART, 使能接收
    TMOD |= 0x20;
    TH1 = 0xfd; //波特率9600 初值
    TL1 = 0xfd;
    TR1 = 1;
    EA = 1; //打开总中断
    ES = 1; //打开串口中断
}