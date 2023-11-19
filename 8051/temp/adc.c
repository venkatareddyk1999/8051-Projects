#include "adc.h"
#include "lcd.h"


void adc_conv()
{
    wr = 0;
    delay(2);
    wr = 1;
    while (intr);
    delay(2);
    intr = 1;
}

void adc_read()
{
    unsigned int value;
    rd = 0;
    delay(2);
    value = adc_input;
    delay(1);
    rd = 1;
    lcd_data_adc(value + 11);
}
