#include "lcd.h"



void delay(unsigned int sec)
{
    int i, j;
    for (i = 0; i < sec; i++)
        for (j = 0; j < 1275; j++);
}

void lcd_cmd(unsigned char item)
{
    dataport = item;
    rs = 0;
    rw = 0;
    e = 1;
    delay(1);
    e = 0;
    return;
}

void lcd_data(unsigned char item)
{
    dataport = item;
    rs = 1;
    rw = 0;
    e = 1;
    delay(1);
    e = 0;
}

void lcd_init()
{
    lcd_cmd(0x01);
    delay(1);
    lcd_cmd(0x06);
    delay(1);
    lcd_cmd(0x0e);
    delay(1);
    lcd_cmd(0x38);
    delay(1);
    lcd_cmd(0x80);
    delay(1);
}

void lcd_data_string(char *x)
{
    while (*x != '\0')
    {
        lcd_data(*x);
        delay(2);
        x++;
    }
}

void lcd_data_adc(unsigned int i)
{
    int p,num[10];
    int k = 0;
    while (i > 0)
    {
        num[k] = i % 10;
        i = i / 10;
        k++;
    }
    k--;
    for (p = k; p >= 0; p--)
    {
        dataport = num[p] + 48;
        rw = 0;
        rs = 1;
        e = 1;
        delay(1);
        e = 0;
    }
}
