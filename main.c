#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"

int main(void)
{

    // uart_init();
    DDRB |= (1 << PINB3); // set as output

    while (1)
    {

        PORTB |= (1 << PINB3); // HIGH

        _delay_ms(500); // delay 500ms

        PORTB &= ~(1 << PINB3); // LOW

        _delay_ms(500); // delay 500ms
    }
}
