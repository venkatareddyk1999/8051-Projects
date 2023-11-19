#include<reg51.h>
sfr p0=0xA0;
sbit s1=P1^0;
sbit s2=P1^1;
sbit s3=P1^2;
sbit s4=P1^3;
void delay(unsigned int);
void main()
{
	unsigned char i,j,k,l,m;
		char digit[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
		for(l=0; l<10; l++)
		{
		for(k=0; k<10; k++)
		{
			for(j=0; j<10; j++)
			{
				for(i=0; i<10; i++)
				{
					for(m=0; m<10; m++)
					{
					p0=digit[i];
					s1=1;
					s2=0;
					s3=0;
					s4=0;
					delay(15);
					p0=digit[j];
					s1=0;
					s2=1;
					s3=0;
					s4=0;
					delay(15);
					p0=digit[k];
					s1=0;
					s2=0;
					s3=1;
					s4=0;
					delay(15);
					p0=digit[l];
					s1=0;
					s2=0;
					s3=0;
					s4=1;
					delay(15);
				}
			}
		}
	}
}
}
void delay(unsigned int value)
{
	unsigned int i,j;
	for(i=0; i<value; i++)
	{
		for(j=0; j<1; j++);
	}
}
