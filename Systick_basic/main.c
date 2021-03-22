#include "TM4C123.h"


void SysTick_Handler(void);
int main()
{
	
	SYSCTL->RCGCGPIO = 0x20;
	GPIOF->DIR = 0x08;
	GPIOF->DEN = 0x08;
	
	SysTick->LOAD = 15999999;
	SysTick->CTRL = 7;
	
	
	
	
	while(1)
  {
		
  }
	
}

void SysTick_Handler(void)
{
	
	GPIOF->DATA ^= 8;     //Toggle PF3 pin
	
	
}



