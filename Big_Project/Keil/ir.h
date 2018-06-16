#ifndef __IR_H_
#define __IR_H_
/**********************************
包含头文件
**********************************/
#include<reg52.h>

/**********************************
重定义关键词
**********************************/
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/**********************************
PIN口定义
**********************************/
sbit IRIN=P3^2;

/**********************************
函数声明
**********************************/
/*延时函数，i=1时，大约延时10us*/
void delay(uint i);
/*读取红外数值的中断函数*/
//void ReadIr() interrupt 0 ;
/*初始化红外线接收*/		
void IrInit();						  

#endif