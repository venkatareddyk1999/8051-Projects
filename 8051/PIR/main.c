#include <reg51.h>

// Define macros for PIR sensor and LED pins
sbit PIR_PIN = P2^0;
sbit LED_PIN = P1^0;

// Function to initialize the microcontroller
void init()
{
    // Configure PIR_PIN as input
    PIR_PIN = 1;

    // Configure LED_PIN as output
    LED_PIN = 0;
}

// Function to check PIR sensor status
unsigned char readPIR() 
{
    return PIR_PIN;  // Read the PIR sensor pin
}

// Function to control the LED based on PIR sensor output
void controlLED(unsigned char pirStatus) 
{
    if (pirStatus) 
		{
        LED_PIN = 1;  // Turn on the LED
    } else 
		{
        LED_PIN = 0;  // Turn off the LED
    }
}

void main() 
{
    unsigned char pirStatus;

    init();  // Initialize the microcontroller

    while (1) 
		{
        pirStatus = readPIR();  // Read PIR sensor status
        controlLED(pirStatus);  // Control the LED based on PIR status
    }
}
