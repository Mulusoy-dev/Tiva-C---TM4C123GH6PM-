//0x400F.E000, 0x608 RCGC     R5,VALUE=1    Enable and provide a clock to GPIO Port F in Run mode
//0x4002.5000, 0x400 DIR			VALUE=0 INPUT,	VALUE=1 OUTPUT
//0x4002.5000, 0x51C DEN			VALUE=1 The digital functions for the corresponding pin are enabled.			
//0x400253FCU,   DATA
int main()
{
	unsigned int *pt;
	pt=(unsigned int *)0x400FE608U;
	*pt=0x20U;
	pt=(unsigned int *)0x40025400U;
	*pt=0x0EU;													//0x20 = RED,	0x40 = BLUE,	0x80 = GREEN,	0x0E=RED+BLUE+GREEN
	pt=(unsigned int *)0x4002551CU;
	*pt=0x0EU;
	pt=(unsigned int *)0x400253FCU;
	*pt=0x02U;      //0X02=RED, 0x04=BLUE, 0x08=GREEN
	
}
