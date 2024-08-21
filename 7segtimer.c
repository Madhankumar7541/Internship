#include<pic.h>
unsigned int stepvalue();
unsigned int temp,temp1,val,mv;
unsigned char dcount,temp2;
unsigned char lookup[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7C,0X67};
unsigned char arr[4];
void main()
{
TRISB=TRISC=TRISD=0X00;

TRISA=0X01;
ANSELH=0;
ANSEL=0X01;

GIE=T0IE=1;
OPTION=0X02;

	while(1)
	{
	delay();
	val=stepvalue();
	mv=val*5;
	temp=mv/5;
	
		arr[0]=temp/1000;
		temp1=temp%1000;
		arr[1]=temp1/100;
		temp2=temp1%100;
		arr[2]=temp2/10;
		arr[3]=temp2%10;
		
		if(temp<200)
		RD0=1;
		else
		RD0=0;
	}
}

unsigned int stepvalue()
{
unsigned char adc_del=50;
ADFM=1;
ADCON0=0X81;
while(adc_del--);
GODONE=1;
while(GODONE==1);
return ADRESH*256+ADRESL;
}

void interrupt ist()
{
	if (T0IF==1)
	{
	T0IF=0;
	dcount++;
	if(dcount>3)
	dcount=0;
	RC0=RC1=RC2=RC3=0;
		if(dcount==0)
		{
		PORTB=lookup[arr[0]];
		RC0=1;
		}
		
		else if (dcount==1)
		{
		PORTB=lookup[arr[1]];
		RC1=1;
		}
		
		else if (dcount==2)
		{
		PORTB=lookup[arr[2]];
		RC2=1;
		}
		
		else if (dcount==3)
		{
		PORTB=lookup[arr[3]];
		RC3=1;
		}
	}
}

delay()
{
unsigned int i;
for (i=0;i<50000;i++);
}