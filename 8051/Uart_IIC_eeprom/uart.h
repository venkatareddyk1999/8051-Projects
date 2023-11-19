





void ser_init();
void tx(unsigned char send);
void tx_str(unsigned char *s);
unsigned char rx();
void rx_str(unsigned char *buffer, unsigned int max_length);
unsigned int rxTwoDigitInt();
void intToStr(unsigned int num, char* str);
