#ifndef _DELAY_H
#define _DELAY_H

#include <intrins.h>

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

void Delay(uint i);
void Delay_1ms(uint i);
void Delay2();
void delay1(uchar i);
void delay3();


#endif