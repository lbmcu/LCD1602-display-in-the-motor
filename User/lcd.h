#ifndef _LCD_H
#define _LCD_H

#include <reg52.h>
#include "delay.h"


//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

sbit E = P2 ^ 7;		//1602使能引脚
sbit RW = P2 ^ 6;		//1602读写引脚
sbit RS = P2 ^ 5;		//1602数据/命令选择引脚

bit Busy(void);		//读状态函数，读出函数是否处在忙状态
void wcmd(uchar del);			//命令函数
void wdata(uchar del);		//写数据函数
void L1602_init(void);		//初始化
//void L1602_char(uchar hang,uchar lie,char sign);		//写行列单字符
void L1602_string(uchar hang,uchar lie,uchar *p);			//写行列字符串
void LCD_display(uchar *p,uchar *q);		//最终成像函数


#endif