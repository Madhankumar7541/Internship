#include <pic.h>
void main()
{
TRISB=0X00;
ANSEL=ANSELH=0X00;
	while(1)
	{
	PORTB=0X01;
	delay();
	PORTB=0X02;
	delay();
	PORTB=0X04;
	delay();
	PORTB=0X08;
	delay();
	PORTB=0X10;
	delay();
	PORTB=0X20;
	delay();
	PORTB=0X40;
	delay();
	PORTB=0X80;
	delay();
	}
}

delay()
{
unsigned int i;

}