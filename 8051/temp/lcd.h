#ifndef LCD_H
#define LCD_H

#include <reg51.h>

#define dataport P2

sbit rs = P3^0;
sbit rw = P3^1;
sbit e = P3^2;

void delay(unsigned int);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_data_string(unsigned char*);
void lcd_init();
void lcd_data_adc(unsigned int);

#endif
