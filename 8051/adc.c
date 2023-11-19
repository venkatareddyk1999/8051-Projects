#include <reg51.h>
#include "adc.h"
#include "IO_Definitions.h"
#include "lcd.h"

// Implement adc_conv(), adc_read(), and delay() here.


void adc_conv()
{                      
wr = 0;
delay(2);                     
wr = 1;                     
while(intr);
delay(2);
intr=1; 
}




void adc_read()
{
unsigned int value;                  
rd = 0;
delay(2);
value=adc_input;
delay(1);
rd=1; 
lcd_data_adc(value+11);                                          
}




void delay(unsigned int sec )
{
int i ,j ;
for(i=0;i<sec;i++)
  for(j=0; j<1275; j++);
}

