

#include <reg51.h>
#include "eeprom.h"
#include "delay.h"
#include "uart.h"


unsigned char bdata EP_DATA;
sbit SDA =   P1^0;
sbit SCL =   P1^1;

sbit lsb=EP_DATA^0;
sbit msb=EP_DATA^7;

unsigned char rec[25];


void i2c_start(void)
{
  SDA=1;
  SCL=1;
	delay(1);
  SDA=0;
	delay(1);
  SCL=0;
}



void i2c_stop(void)
{
  SDA=0;
  SCL=1;
	delay(1);
  SDA=1;
	delay(1);
  SCL=0;
}


void i2c_send (unsigned char send)
{
  unsigned char i;
  EP_DATA=send;
  for(i=0;i<=7;i++) {
    SDA=msb;
    SCL=1;
    SCL=0;
    EP_DATA=EP_DATA<<1;
  }
  while(SDA!=0);
  SCL=1;
  SCL=0;
}



void i2c_send_byte(unsigned char addr,unsigned char dataa)
{
  i2c_start();
  i2c_send(0xa0);
  i2c_send(addr);
  i2c_send(dataa);
  i2c_stop();
}





void i2c_send_string(unsigned char addr,unsigned char *s)
{
  i2c_start();
  i2c_send(0xa0);
  i2c_send(addr);
  while(*s) 
	{
    i2c_send(*s++);
		//tx(*s);
		
  }
  i2c_stop();
}






unsigned char i2c_read(void)
{
  unsigned char i;
  lsb=SDA;
  for(i=0;i<=7;i++) {
    EP_DATA=EP_DATA<<1;
    lsb=SDA;
    SCL=1;
    SCL=0;
  }
        
  if(EP_DATA==13) {
    SDA=1;
    SCL=1;
		delay(1);
    SCL=0;
		delay(1);
    SDA=0;
    i2c_stop();
		delay(1);
    return(EP_DATA);
  }

  SDA=0;
  SCL=1;
	delay(1);
  SCL=0;
	delay(1);
  SDA=1;

  return(EP_DATA);
}





unsigned char i2c_read_byte(unsigned char addr)
{
  unsigned char rec;
  i2c_start();
  i2c_send(0xa0);
  i2c_send(addr);
  i2c_start();
  i2c_send(0xa1);
  rec=i2c_read();
  i2c_stop();
	tx(rec);
  return rec;
}



unsigned char i2c_read_string(unsigned char addr)
{
  unsigned char i;
  i2c_start();
  i2c_send(0xa0);
  i2c_send(addr);
  i2c_start();
  i2c_send(0xa1);
  for(i=0;i<16;i++) 
	{
  rec[i]=i2c_read();  
	}
  i2c_stop();
  return rec;
}
