#include <pic.h>
void main()
{
TRISB=0X00;
ANSEL=ANSELH=0X00;
	while(1)
	{
	PORTB=0X01;
	delay();
	PORTB=0X03;
	delay();
	PORTB=0X07;
	delay();
	PORTB=0X0F;
	delay();
	PORTB=0X1F;
	delay();
	PORTB=0X3F;
	delay();
	PORTB=0X7F;
	delay();
	PORTB=0XFF;
	delay();
	}
}

delay()
{
unsigned int i;
for (i=0;i<50000;i++);
}