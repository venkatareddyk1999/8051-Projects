
#include <reg51.h>
#include "delay.h"
#include "eeprom.h"
#include "uart.h"



int main()
{
	extern unsigned char rec[25];

 // unsigned char Data[50];
	while(1)
	{
		unsigned char rw,addr;
		unsigned int pg;
  ser_init();
		tx_str(" Which operation You want to perform Read(R) from the EEPROM or Write(W) in to the EEPROM  ");
		 tx_str("\n\r");
		tx_str(" Enter(R/W) :");
		tx_str("\n\r");
		rw = rx();
		if( rw == 'R' || rw == 'r')
		{
			tx_str(" Read mode selected ");
			tx_str("\n\r");
			tx_str(" Enter the page number you want to read from : ");
			pg = rxTwoDigitInt();
			tx_str("\n\r");
			tx_str(" Entered page number is  : ");
			//void intToStr(unsigned int num, char* str)
			intToStr( pg, rec);
			tx_str(rec);
			tx_str("\n\r");
			
			switch(pg)
			{
				case 01:
				{
					addr = 0x00;					
					break;
				}
				case 02:
				{
					addr = 0x10;					
					break;
				}
				case 03:
				{
					addr = 0x20;
					break;
				}
				case 04:
				{
					addr = 0x30;					
					break;
				}
				case 05:
				{
					addr = 0x40;					
					break;
				}
				case 06:
				{
					addr = 0x50;					
					break;
				}
				case 07:
				{
					addr = 0x60;					
					break;
				}
				case 88:
				{
					addr = 0x70;					
					break;
				}
				case 99:
				{
					addr = 0x80;					
					break;
				}
				case 10:
				{
					addr = 0x90;					
					break;
				}
				case 11:
				{
					addr = 0xA0;					
					break;
				}
				case 12:
				{
					addr = 0xB0;					
					break;
				}
				case 13:
				{
					addr = 0xC0;					
					break;
				}
				case 14:
				{
					addr = 0xD0;					
					break;
				}
				case 15:
				{
					addr = 0xE0;					
					break;
				}
				case 16:
				{
					addr = 0xF0;					
					break;
				}
				case 17:
				{
					addr = 0x100;					
					break;
				}
				case 18:
				{
					addr = 0x110;					
					break;
				}
				case 19:
				{
					addr = 0x120;					
					break;
				}
				case 20:
				{
					addr = 0x130;					
					break;
				}
				case 21:
				{
					addr = 0x140;					
					break;
				}
				case 22:
				{
					addr = 0x150;					
					break;
				}
				case 23:
				{
					addr = 0x160;					
					break;
				}
				case 24:
				{
					addr = 0x170;					
					break;
				}
				case 25:
				{
					addr = 0x180;					
					break;
				}
				case 26:
				{
					addr = 0x190;					
					break;
				}
				case 27:
				{
					addr = 0x1A0;					
					break;
				}
				case 28:
				{
					addr = 0x1B0;					
					break;
				}
				case 29:
				{
					addr = 0x1C0;					
					break;
				}
				case 30:
				{
					addr = 0x1D0;					
					break;
				}
				case 31:
				{
					addr = 0x1E0;					
					break;
				}
				case 32:
					{
					addr = 0x1F0;
					//tx_str(" Page 32 selected,now you can read from page 32 ");
					break;
					}
				default:
				{
					tx_str(" oops... invalid page number ");
					tx_str("\n\r");
				}			
			
			}
			
			
			if( pg > 0 && pg < 33 )
			{
				tx_str(" Page ");
				tx_str(rec);
				tx_str(" selected, now you can read from page ");
				tx_str(rec);
				tx_str("\n\r");
				
				
				tx_str(" Data in ");
				tx_str(rec);
				tx_str(" page is :");
				i2c_read_string( addr );
				tx_str( rec );
				tx_str("\n\r");
			}		
			else
			{
				tx_str(" oops... invalid page number ");
					tx_str("\n\r");			
			}		
		
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		if( rw == 'W' || rw == 'w' )
		{
			tx_str(" Write  mode selected");		
			tx_str("\n\r");
			tx_str(" Enter the page number you want to perform write operation : ");
			pg = rxTwoDigitInt();
			tx_str("\n\r");
			tx_str(" Entered page number is  : ");
			//void intToStr(unsigned int num, char* str)
			intToStr( pg, rec);
			tx_str(rec);
			tx_str("\n\r");
			
			switch(pg)
			{
				case 01:
				{
					addr = 0x00;					
					break;
				}
				case 02:
				{
					addr = 0x10;					
					break;
				}
				case 03:
				{
					addr = 0x20;
					break;
				}
				case 04:
				{
					addr = 0x30;					
					break;
				}
				case 05:
				{
					addr = 0x40;					
					break;
				}
				case 06:
				{
					addr = 0x50;					
					break;
				}
				case 07:
				{
					addr = 0x60;					
					break;
				}
				case 88:
				{
					addr = 0x70;					
					break;
				}
				case 99:
				{
					addr = 0x80;					
					break;
				}
				case 10:
				{
					addr = 0x90;					
					break;
				}
				case 11:
				{
					addr = 0xA0;					
					break;
				}
				case 12:
				{
					addr = 0xB0;					
					break;
				}
				case 13:
				{
					addr = 0xC0;					
					break;
				}
				case 14:
				{
					addr = 0xD0;					
					break;
				}
				case 15:
				{
					addr = 0xE0;					
					break;
				}
				case 16:
				{
					addr = 0xF0;					
					break;
				}
				case 17:
				{
					addr = 0x100;					
					break;
				}
				case 18:
				{
					addr = 0x110;					
					break;
				}
				case 19:
				{
					addr = 0x120;					
					break;
				}
				case 20:
				{
					addr = 0x130;					
					break;
				}
				case 21:
				{
					addr = 0x140;					
					break;
				}
				case 22:
				{
					addr = 0x150;					
					break;
				}
				case 23:
				{
					addr = 0x160;					
					break;
				}
				case 24:
				{
					addr = 0x170;					
					break;
				}
				case 25:
				{
					addr = 0x180;					
					break;
				}
				case 26:
				{
					addr = 0x190;					
					break;
				}
				case 27:
				{
					addr = 0x1A0;					
					break;
				}
				case 28:
				{
					addr = 0x1B0;					
					break;
				}
				case 29:
				{
					addr = 0x1C0;					
					break;
				}
				case 30:
				{
					addr = 0x1D0;					
					break;
				}
				case 31:
				{
					addr = 0x1E0;					
					break;
				}
				case 32:
					{
					addr = 0x1F0;
					//tx_str(" Page 32 selected,now you can read from page 32 ");
					break;
					}
				default:
				{
					tx_str(" oops... invalid page number ");
					tx_str("\n\r");
				}			
			
			}
			
			
			
			if( pg > 0 && pg < 33 )
			{
				tx_str(" Page ");
				tx_str(rec);
				tx_str(" selected, now you can write in to the page ");
				tx_str(rec);
				tx_str("\n\r");
				
				
				tx_str(" Enter the Data you want to write :");
				tx_str("\n\r");
				rx_str(rec,17);				
				tx_str(" Entered data is : ");
				tx_str(rec);
				tx_str("\n\r");				
				i2c_send_string(addr, rec );
				tx_str(" Data written successfully ");
				tx_str("\n\r");
				
				
			}		
			else
			{
				tx_str(" oops... invalid page number ");
					tx_str("\n\r");			
			}	
						
			
		}
  
	}	
	//while(1);

}

