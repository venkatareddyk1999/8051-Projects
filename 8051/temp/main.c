#include <reg51.h>
#include "lcd.h"
#include "adc.h"

#define dataport P2

int num[10];

void main()
{
    lcd_init();
    lcd_data_string(" VENKATA REDDY ");
    delay(1000);
    lcd_init();
    lcd_data_string("AJAY REDDY");
    delay(700);
    lcd_init();
    lcd_data_string("  NARASIMHA ");
    delay(700);
    lcd_init();
    lcd_data_string(" CHARAN /RISHI");
    delay(700);
    lcd_init();
    lcd_data_string("TEMPERATURE=");

    while (1)
    {
        dataport = 0x00;
        adc_input = 0xff;
        P3 = 0x00;
        lcd_cmd(0x8c);
        delay(1);
        adc_conv();
        adc_read();
        lcd_data('C');
        delay(50);
    }
}
