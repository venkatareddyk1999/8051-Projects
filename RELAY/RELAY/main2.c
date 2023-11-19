#include <lpc17xx.h>

#define SwitchPinNumber 12
#define SwitchPinNumber1 11
#define LedPinNumber    28

/* start the main program */
int main() 
{
    uint32_t switchStatus,switchStatus1;
		uint16_t i=0;
    SystemInit();                    //Clock and PLL configuration 
    LPC_PINCON->PINSEL3 = 0x00000000; //Configure the Pins for GPIO;
		LPC_PINCON->PINSEL4 = 0x00000000; //Configure the Pins for GPIO;
    /* Configure the LED pin as output and SwitchPin as input */
    LPC_GPIO1->FIODIR = ((1<<LedPinNumber));
    LPC_GPIO2->FIODIR = ((0<<SwitchPinNumber)|(0<<SwitchPinNumber1));
		LPC_GPIO2->FIODIR = ((0<<SwitchPinNumber1));

  while(1)
    {

     /* Turn On all the leds and wait for one second */ 
       switchStatus = (LPC_GPIO2->FIOPIN>>SwitchPinNumber) & 0x01 ;  // Read the switch status
			 switchStatus1 = (LPC_GPIO2->FIOPIN>>SwitchPinNumber1) & 0x01 ;  // Read the switch status
       
       if(switchStatus1 == 1)                        //Turn ON/OFF LEDs depending on switch status
       {  
         LPC_GPIO1->FIOPIN = (1<<LedPinNumber);
				 for(i=0;i<=1000;i++);
				 while(switchStatus==0)
				 {
					 switchStatus = (LPC_GPIO2->FIOPIN>>SwitchPinNumber) & 0x01 ;  // Read the switch status			 	 
				 
				 }
       }
			 
       else
       {
            LPC_GPIO1->FIOPIN = (0<<LedPinNumber);
						//while(~(switchStatus1));
				 
       }      
    }
}
