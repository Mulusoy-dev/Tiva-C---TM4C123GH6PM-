#include "TM4C123.h"			// Device header


#define RED (1U<<1)
#define BLUE (1U<<2)
#define GREEN (1U<<3)

#define SW1 (1U<<4)
#define SW2 (1U<<0)
#define SW1_ 0x01
#define SW2_ 0x10 


#define KEY 0x4C4F434B

uint32_t SW_INPUT();
void LED_ON(uint32_t LED);
void delay(int time);	
	

int main(){
	
	uint32_t sw_state;
	SYSCTL->RCGCGPIO |= (1U<<5);
	GPIOF->LOCK = KEY;
	GPIOF->CR = 0xFF;
	GPIOF->DIR |= (BLUE | GREEN | RED);
	GPIOF->PUR |= (SW1 | SW2);
	GPIOF->DEN |= (RED | BLUE | GREEN | SW1 | SW2);
	
	while(1){
		sw_state=SW_INPUT();
		
		switch(sw_state){
		
			case	SW1_:
			LED_ON(GREEN);
			break;
			
			case SW2_:
			LED_ON(BLUE);
			break;

		}
	}
}

uint32_t SW_INPUT(){
	
	return (GPIOF->DATA & 0x11);				// 0001 0001

}

void LED_ON(uint32_t LED){
	
	GPIOF->DATA = LED;
	delay(2000000);
	GPIOF->DATA = 0x00;
	delay(2000000);
	
}

void delay(int time){
	int volatile delay;
	delay=0;
	while(delay < time){
			++delay;
	}	
}