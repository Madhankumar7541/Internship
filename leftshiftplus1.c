#include <pic.h>
void main()
{
TRISB=0;
ANSEL=ANSELH=0x00;
PORTB=0X01;
	while(1)
	{
	delay();
	PORTB=PORTB<<1;
	PORTB=PORTB++;
	if (PORTB==0XFF)
	PORTB=0X01;
	}
}

delay()
{
unsigned int i;
for (i=0;i<50000;i++);
}