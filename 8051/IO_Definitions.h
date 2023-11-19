#ifndef IO_DEFINITIONS_H
#define IO_DEFINITIONS_H




#define dataport P2
#define adc_input P0


sbit rs = P3^0;
sbit rw = P3^1;
sbit e = P3^2;
sbit wr= P3^3;
sbit rd= P3^4;
sbit intr= P3^5;

int num[10];


#endif
