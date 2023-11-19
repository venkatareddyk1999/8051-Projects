#include<reg51.h>

#define delay for(i=0;i<1000;i++);
#define lcd P2

sbit rd=P0^0;
sbit wr=P0^1;
sbit intr=P0^2;

sbit rs=P3^2;
sbit rw=P3^3;
sbit en=P3^4;

void lcd_int();
void cmd(unsigned int b);
void dat(unsigned int c);
void show(unsigned char *s);

unsigned char adc(),get_value, conv;
int i;
float voltage;

void main()
{
    lcd_int();
    show("Voltag: ");
    while(1)
        {
        get_value = adc();  //voltage = adcValue * 5.0 / 255.0;
        cmd(0x87);
        dat((get_value/100)+48);
        dat(((get_value/10)%10)+48);
        dat((((get_value%10)+48)*(5.0 / 255.0))/5);
        dat(0x60);
				//cmd(0x90);
				//dat();
        //dat('c');

        }
}

void lcd_int()
{
    cmd(0x38);
    cmd(0x0e);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}

void cmd(unsigned int b)
{
    lcd=b;
    rs=0;
    rw=0;
    en=1;
    delay;
    en=0;
}

void dat(unsigned int c)
{
    lcd=c;
    rs=1;
    rw=0;
    en=1;
    delay;
    en=0;
}

void show(unsigned char *s)
{
    while(*s)
        dat(*s++);
}

unsigned char adc()
{
    wr=0;
    rd=1;
    wr=1;
    while(intr==1);
    rd=0;
    conv=P1;
    
    return conv;
}