#ifndef _123_H 
#define _123_H

#include <reg52.h>
#include <intrins.h>
#include "lcd.h"
#include "delay.h"
#include "motor.h"
#include "Uart.h"
//#define	speed_a	1


//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

sbit led = P3 ^ 7;
//sbit led1 = P3 ^ 7;
bit flag;
static speed = 1;

void panduan();

#endif