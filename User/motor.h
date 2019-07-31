#ifndef _MOTOR_H
#define _MOTOR_H

#include <reg52.h>
#include "delay.h"

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

int back(uchar speed);			//控制正转
int forward(uchar speed);		//控制反转

#endif