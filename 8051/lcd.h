#ifndef LCD_H
#define LCD_H

void lcd_init();
void lcd_data_string(char*);
void lcd_data(unsigned char);
void lcd_cmd(unsigned char);
void lcd_data_adc(unsigned int);

#endif
