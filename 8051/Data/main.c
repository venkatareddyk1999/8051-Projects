#include <reg51.h>

unsigned char bdata EP_DATA;

sbit lsb=EP_DATA^0;
sbit msb=EP_DATA^7;

sbit SDA =   P1^0;
sbit SCL =   P1^1;

unsigned char rec[28];

void i2c_start(void);
void i2c_stop(void);
void delay(unsigned int);

void i2c_send (unsigned char);
void i2c_send_byte(unsigned char addr,unsigned char dataa);
void i2c_send_string(unsigned char addr,unsigned char *s);

unsigned char i2c_read(void);
unsigned char i2c_read_byte(unsigned char addr);
unsigned char i2c_read_string(unsigned char addr);

void ser_init();
void tx(unsigned char send);
void tx_str(unsigned char *s);

void i2c_start(void)
{
  SDA=1;
  SCL=1;
	delay(1);
  SDA=0;
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

void i2c_stop(void)
{
  SDA=0;
  SCL=1;
	delay(1);
  SDA=1;
	delay(1);
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

unsigned char i2c_read_string(unsigned char addr)
{
  unsigned char i;
  i2c_start();
  i2c_send(0xa0);
  i2c_send(addr);
  i2c_start();
  i2c_send(0xa1);
  for(i=0;i<14;i++) 
	{
  rec[i]=i2c_read();  
	}
  i2c_stop();
  return rec;
}

void ser_init()
{
  SCON=0x50;
  TMOD|=0x20;
  TH1=0xFD;
  TL1=0xFD;
  TR1=1;
}

void tx(unsigned char send)
{
  SBUF=send;
  while(TI==0);
  TI=0;
}

void tx_str(unsigned char *s)
{
  while(*s)
    tx(*s++);
}

void delay(unsigned int sec )
{
int i ,j ;
for(i=0;i<sec;i++)
  for(j=0; j<1275; j++);
}

                     
int main()
{
 // unsigned char Data[50];
	while(1)
	{
  ser_init();
		tx_str("Write Data : venkata reddy");
		delay(1);
  i2c_send_string(0x00,"venkata reddy ");
	tx_str("\n\r");
	tx_str("Read back Data : ");
  i2c_read_string(0x00);
	tx_str(rec);
	tx_str("\n\r");
		
  //while(1);
	}	

}
