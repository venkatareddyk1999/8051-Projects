#include <lpc17xx.h>   

void delay_ms(unsigned int ms)
{
    unsigned int i,j;

    for(i=0;i<ms;i++)
        for(j=0;j<20000;j++);
}

/* start the main program */
int main() 
{
    SystemInit();                    //Clock and PLL configuration 
    LPC_PINCON->PINSEL2 = 0x00000000;  //Configure the PORT1 Pins as GPIO;
		LPC_PINCON->PINSEL3 = 0x00000000;  //Configure the PORT1 Pins as GPIO;
    LPC_GPIO1->FIODIR = 0xffffffff;  //Configure the PORT2 pins as OUTPUT;

    while(1)
    {
        LPC_GPIO1->FIOSET = 0xffffffff;     // Make all the Port pins as high  
        delay_ms(10);

        LPC_GPIO1->FIOCLR = 0xffffffff;     // Make all the Port pins as low  
        delay_ms(10);
    }
}
