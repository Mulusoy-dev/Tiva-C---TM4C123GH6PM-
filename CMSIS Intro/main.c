#include "TM4C123.h"                    // Device header
                 


#define RED (1U<<1)
#define BLUE (1U<<2)
#define GREEN (1U<<3)
#define WHITE (RED | BLUE | GREEN)

void delay(int time);


int main(){
	
	
	SYSCTL->RCGCGPIO=0x20U;
	GPIOF->DIR=WHITE;
	GPIOF->DEN=WHITE;
	GPIOF->DATA=GREEN;
	
	while(1){
		GPIOF->DATA|=BLUE;
		delay(1000000);
		GPIOF->DATA&=(~BLUE);
		delay(500000);
	
		}
}
void delay(int time){
	int volatile delay;
	delay=0;
		
			while(delay < time){
				++delay;
			}
}










