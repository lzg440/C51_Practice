#include <ioAT89C52.h>

#define PWM (P2_bit.P2_1)
#define SWI (P2_bit.P2_2)
#define Dir (P2_bit.P2_3)
#define beep (P2_bit.P2_4)

#define UP (P3_bit.P3_3)
#define RIGHT (P3_bit.P3_4)
#define START (P3_bit.P3_5)
#define LEFT (P3_bit.P3_6)
#define DOWN (P3_bit.P3_7)

typedef unsigned int u16;
typedef unsigned char u8;

u8 Command='-';

u16 low = 60;
u16 high = 70;
u16 pwm = 55;
u16 offset = 0;

void delay(u16 i);		
void CtrlInit();

void main()
 { 
	CtrlInit();

	while(1){
		beep = 1;
		
		if(!START){
			beep = 0;
			Command = '4';
			while(!START);
		}
		if(!SWI){
			if(!UP){
				beep = 0;
				Command = '9';
				while(!UP);
			}
			else if(!DOWN){
				beep = 0;
				Command = '5';
				while(!DOWN);
			}
			else if(!LEFT){
				beep = 0;
				Command = '0';
				while(!LEFT);
			}
			else if(!RIGHT){
				beep = 0;
				Command = '3';
				while(!RIGHT);
			}
		}

		switch(Command){
			case '4':
				SWI = !SWI;
				if(SWI){
				}
				else{
					Dir = 0;
					pwm = low;
				}
				break;
			case '9':
				if(!Dir){
					pwm = high;
				}
				else{
					//pwm = 1000-high-offset;
					//pwm = high;
					pwm = high;
				}
				break;
			case '5':
				if(!Dir){
					pwm = low;
				}
				else{
					//pwm = 1000-low-offset;
					//pwm = low;
					pwm = low;
				}
				break;
			case '0':
				Dir = 0;
				pwm = low;
				break;
			case '3':
				Dir = 1;
				//pwm = 1000-low-offset;
				//pwm = low;
				pwm = low;
				break;
			default:
				break;
		}

		Command = '-';

		if(!SWI){
			// Dir和DIR电位相反
			// DIR和PWM电位相同时为无效状态
			if(!Dir){  // PWM=1 invalid(at this time DIR=1)
				/*PWM = 0;
				delay(pwm);
				PWM = 1;
				delay(500-pwm);*/
				PWM = Dir;
				delay(500);
			}
			else{  // PWM=0 invalid(at this time DIR=0)
				/*PWM = 1;
				delay(pwm);
				PWM = 0;
				delay(500-pwm);*/
				PWM = Dir;
				delay(500);
			}
		}
		else{
			PWM = !Dir;  // 保持在无效状态
			delay(500);
		}
	}
 }

 
 
 void delay(u16 i){
	 while(i--);
 }
 
 void CtrlInit(){
	UP = 1;
	DOWN = 1;
	LEFT = 1;
	RIGHT = 1;
	START = 1;
	 
	SWI = 1;
	Dir = 0;
 }
 
 