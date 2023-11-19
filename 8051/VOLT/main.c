#include <reg51.h>
#include <stdio.h>

// Function prototype for delay_ms
void delay_ms(unsigned int milliseconds);
void LCD_Command(unsigned char cmd);
void LCD_Init();
//void LCD_Data(unsigned char Data);
void IntToStr(unsigned int num, char *buffer);
void ADC_Init();
unsigned int ADC_Read(unsigned char channel);
void LCD_String(char *str);




// Define LCD control pins
sbit RS = P1^0;    // Register Select
sbit RW = P1^1;    // Read/Write
sbit EN = P1^2;    // Enable

// Define ADC control pins
sbit ALE = P2^0;   // Address Latch Enable
sbit START = P2^1; // Start conversion
sbit EOC = P2^2;   // End of Conversion
sbit OE = P2^3;    // Output Enable
sbit rd = P2^4;    // Read
sbit wr = P2^5;    // Write
sbit INTR = P2^6;  // Interrupt

// Function to initialize LCD
void LCD_Init() 
{
    delay_ms(15);
    LCD_Command(0x38); // 2 lines, 5x7 matrix
    LCD_Command(0x0E); // Display on, cursor blinking
    LCD_Command(0x01); // Clear screen
    LCD_Command(0x06); // Increment cursor
    LCD_Command(0x80); // Move cursor to the beginning of the first line
}

// Function to send a command to the LCD
void LCD_Command(unsigned char cmd) 
{
    RS = 0;     // Command mode
    RW = 0;     // Write mode
    EN = 1;     // Enable pulse
    P3 = cmd;   // Send command
    EN = 0;
    delay_ms(1);
}

// Function to send a dat byte to the LCD

//void LCD_Data(unsigned char Data)
//{
//    RS = 1;     // Data mode
//    RW = 0;     // Write mode
//    EN = 1;     // Enable pulse
//    P3 = Data;  // Send dat
//    EN = 0;
//    delay_ms(1);
//}



// Function to send a Data byte to the LCD
void LCD_Data(unsigned char Data)
{
    RS = 1;     // Data mode
    RW = 0;     // Write mode
    EN = 1;     // Enable pulse
    P3 = Data;  // Send Data
    EN = 0;
    delay_ms(1);
}




void LCD_String(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        LCD_Data(str[i]);
    }




// Function to convert an integer to a string
void IntToStr(unsigned int num, char *buffer) 
{
    sprintf(buffer, "%u", num);
}

// Simple software delay function (adjust loop count for your clock frequency)
void delay_ms(unsigned int milliseconds) 
{
    unsigned int i, j;
    for (i = 0; i < milliseconds; i++)
        for (j = 0; j < 122; j++); // Adjust this loop for the desired delay
}

// Function to initialize ADC
void ADC_Init() 
{
    // Configure ADC pins and control pins
    P0 = 0xFF; // Configure all pins on P0 as input
    P1 = 0x00; // Configure P1 as output for LCD control
    P3 = 0x00; // Configure P3 as output for LCD Data and ADC channel selection
    
    // Configure ADC control pins
    ALE = 0;
    START = 0;
    EOC = 1;
    OE = 0;
    rd = 0;
    wr = 0;
    INTR = 1;
}

// Function to read ADC value
unsigned int ADC_Read(unsigned char channel) 
{
    unsigned int result;
    P3 = channel; // Set the channel on address lines
    ALE = 1;      // Enable address latch
    START = 1;    // Start conversion
    delay_ms(1);  // Delay for conversion to complete (you may need to adjust this)
    START = 0;    // Stop conversion
    while (EOC);  // Wait for end of conversion
    result = P0;  // Read ADC result from Data bus
    ALE = 0;      // Disable address latch
    return result;
}

void main() {
    unsigned int adcValue;
    float voltage;
    char voltageStr[10];

    ADC_Init();
    LCD_Init();

    while (1) {
        adcValue = ADC_Read(0); // Read voltage from channel 0 (you can change this as needed)
        voltage = adcValue * 5.0 / 255.0; // Convert ADC value to voltage (assuming 5V reference)
        
        IntToStr(adcValue, voltageStr); // Convert ADC value to a string

        LCD_Command(0x80); // Move cursor to the beginning of the first line
        LCD_String("Voltage: ");
        LCD_Command(0xC0); // Move cursor to the beginning of the second line
        LCD_String(voltageStr);
        LCD_String(" V");
    }
}
