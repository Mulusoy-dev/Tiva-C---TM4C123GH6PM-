#include "TM4C123.h"                    // Device header

void LCD_init(void);
void LCD_Cmd(unsigned char command);
void delay_micro(int n);
void delay_milli(int n);
void LCD_Data(unsigned char data);

int main()
{
	
	LCD_init();
	LCD_Cmd(0x01);
	LCD_Cmd(0x08);           
	delay_milli(500);
	LCD_Data('C');
	delay_milli(1);
	LCD_Data('M');
	delay_milli(500);
		
}


void LCD_init(void){
		
		SYSCTL->RCGCGPIO = 0x01;    	//  (1U<<0 Same)  Port A Clock Enable
		SYSCTL->RCGCGPIO |= 0x02;      //  (1U<<1 Same)  Port B Clock Enable
		GPIOA->DIR |= 0xE0;           //  (Pin5,6,7) Output       RS,RW,E
		GPIOA->DEN |= 0xE0;						//  (Digital Enable)
		GPIOB->DIR |= 0xFF;           //  (Port B all pin Output
		GPIOB->DEN |= 0xFF;           //  (Digital Enable)
		LCD_Cmd(0x38);                //  8-bits  
	  LCD_Cmd(0x06);                //  Cursor/Blink moves to right
	  LCD_Cmd(0x0F);                //  Display turn on, Cursor turn on, Cursor blink is on
	  LCD_Cmd(0x01);                //  Clear screen
}

void LCD_Data(unsigned char data)
{
	
	GPIOA->DATA = 0x20;             //  RS=1, RW=0, E=0
	GPIOB->DATA = data;
	GPIOA->DATA |= 0x80;            //  E=1, RS=1 
	delay_micro(0);
	GPIOA->DATA = 0x00;             //  RS=0
	delay_micro(0);

}


void LCD_Cmd(unsigned char command)
{
	
	GPIOA->DATA = 0x00;            //RS=0, RW=0, E=0
	GPIOB->DATA = command;         //Write Command 0x38=8bit, 2 display line, 5x8 font
	GPIOA->DATA = 0x80;            //Secure Data, E=1 to a secure command
	delay_micro(0);
	GPIOA->DATA = 0x00;
	
	if (command < 4){
		delay_milli(2);
	}
	else{
		delay_micro(37);     //delay_micro(40)
	}
}

void delay_micro(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{}
	}
}


void delay_milli(int n)
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<3180;j++)
			{}
	}

}










