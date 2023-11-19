#include "uart.h"
#include "delay.h"
#include <reg51.h>



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



unsigned char rx()
{
  while(RI == 0); 
  RI = 0; 
  return SBUF; 
}

void rx_str(unsigned char *buffer, unsigned int max_length)
{
  unsigned int i = 0;
  while (i < max_length - 1) 
  {
    buffer[i] = rx(); 
    if (buffer[i] == '\r' || buffer[i] == '\n') 
    {
      buffer[i] = '\0';
      break;
    }
    i++;
  }
  buffer[i] = '\0'; 
}


unsigned int rxTwoDigitInt() 
{
    unsigned int receivedInt = 0;
    unsigned char rxChar;
    int digitCount = 0;

    while (digitCount < 2) {
        rxChar = rx(); 

        if (rxChar >= '0' && rxChar <= '9') {
            receivedInt = receivedInt * 10 + (rxChar - '0');
            digitCount++;
        }
    }
    
    return receivedInt;
}





void intToStr(unsigned int num, char* str) 
{
    int i = 0;
		int length, j;
    
    if (num == 0) 
		{
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    
    while (num > 0) 
		{
        str[i] = num % 10 + '0';
        num /= 10;
        i++;
    }
    
    
    length = i;
    for ( j = 0; j < length / 2; j++) 
		{
        char temp = str[j];
        str[j] = str[length - j - 1];
        str[length - j - 1] = temp;
    }
    
    str[i] = '\0';
}




