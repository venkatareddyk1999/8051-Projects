#include <reg51.h>

sbit LDR_PIN = P1^0;  // Pin connected to LDR
sbit LED_PIN = P1^1;  // Pin connected to LED

void main() {
    while (1) {
        if (LDR_PIN == 1) {  // If LDR senses light
            LED_PIN = 1;    // Turn on the LED
        } else {
            LED_PIN = 0;    // Turn off the LED
        }
    }
}
