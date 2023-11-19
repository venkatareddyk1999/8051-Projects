#include <lpc17xx.h>

#define SwitchPinNumber 12
#define LedPinNumber    28

/* start the main program */
int main() 
{
    uint32_t switchStatus;
    SystemInit();                    //Clock and PLL configuration 
    LPC_PINCON->PINSEL3 = 0x00000000; //Configure the Pins for GPIO;
		LPC_PINCON->PINSEL4 = 0x00000000; //Configure the Pins for GPIO;
    /* Configure the LED pin as output and SwitchPin as input */
    LPC_GPIO1->FIODIR = ((1<<LedPinNumber));
    LPC_GPIO2->FIODIR = ((0<<SwitchPinNumber));

  while(1)
    {

     /* Turn On all the leds and wait for one second */ 
       switchStatus = (LPC_GPIO2->FIOPIN>>SwitchPinNumber) & 0x01 ;  // Read the switch status
       
       if(switchStatus == 1)                        //Turn ON/OFF LEDs depending on switch status
       {  
         LPC_GPIO1->FIOPIN = (1<<LedPinNumber);
       }
       else
       {
            LPC_GPIO1->FIOPIN = (0<<LedPinNumber);
       }      
    }
}
