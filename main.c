#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"

int main(void)
{
    char name[] = "Ludvig Berggren hej'\n'";

    uart_init();
    DDRB |= (1 << PINB3); // set as output RED
    //DDRB |= (1 << PINB2); // set as output GREEN
    //DDRB |= (1 << PINB1); // set as output BLUE

    while (1) {
        /*
        PORTB |= (1 << PINB3); // HIGH

        _delay_ms(500); // delay 500ms

        PORTB &= ~(1 << PINB3); // LOW

        _delay_ms(500); // delay 500ms
        */
        // uart_putstr(name);
        uart_echo();
    }
}
