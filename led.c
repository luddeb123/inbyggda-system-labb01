#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "string.h"


void led_init(){
    // Set the DDRB registry for pin 11-9 to be output
    DDRB |= (1<<RED_PIN);
    DDRB |= (1<<GREEN_PIN);
    DDRB |= (1<<BLUE_PIN);

    // make the bits high so led is off
    PORTB |= (1 << RED);
    PORTB |= (1 << GREEN);
    PORTB |= (1 << BLUE);
}

// changes the values of the "led-pin-bits" depending on what value the "command-string" is. 
void change_led_state(char *command){
    if (strcmp(command, "off\r\n")==0){
        PORTB |= (1 << RED);
        PORTB |= (1 << GREEN);
        PORTB |= (1 << BLUE);
    }
    if(strcmp(command, "on\r\n")==0){
        PORTB &= ~(1 << RED);
        PORTB &= ~(1 << GREEN);
        PORTB &= ~(1 << BLUE);
    }
}