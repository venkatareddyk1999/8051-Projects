#include<reg51.h>

#define delay for(i=0;i<10000;i++);
#define lcd P1

sbit rd=P0^0;
sbit wr=P0^1;
sbit intr=P0^2;

sbit rs=P0^5;
sbit rw=P0^6;
sbit en=P0^7;

void lcd_int();
void cmd(unsigned int b);
void dat(unsigned int c);
void show(unsigned char *s);

unsigned char adc(),conv;
int i,v_value, get_value;

void main()
{
    lcd_int();
    show("voltage=");
    while(1)
        {
					
					v_value = adc();
        get_value = v_value * 2;
        cmd(0x88);
        dat((get_value/100)+48);
					show(".");
        dat(((get_value/10)%10)+48);
        dat((get_value%10)+48);
       cmd(0x8c);
        dat('V');
					delay;
					delay;
					delay;

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
    conv=P2;
    
    return conv;
}