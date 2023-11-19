#ifndef ADC_H
#define ADC_H

#include <reg51.h>

#define adc_input P0

sbit wr = P3^3;
sbit rd = P3^4;
sbit intr = P3^5;

void adc_conv();
void adc_read();

#endif
