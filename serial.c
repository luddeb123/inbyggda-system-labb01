#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"

#define BAUD 38400
#define FOSC 16000000

void uart_init(void)
{
    //UART transmit and receive
    UCSR0B |= _BV(TXEN0); // Enable transmitter:
    UCSR0B |= _BV(RXEN0); // Enable Receiver:

    // 8 bits of data data
    UCSR0C |= _BV(UCSZ01);
    UCSR0C |= _BV(UCSZ00);

    // No Parity bit
    UCSR0C &= ~_BV(UPM00);
    UCSR0C &= ~_BV(UPM01);

    // 1 Stop bit
    UCSR0C &= ~_BV(USBS0);

    // Set baudrate
    uint16_t ubrrn = FOSC / (16 * BAUD) - 1;
    UBRR0 = ubrrn;
}

void uart_putchar(char chr)
{
    // Wait untill the data is set
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = chr;
    if (chr == '\n')
    {
        uart_putchar('\r');
    }
}

void uart_putstr(const char *str)
{
    char chr = *str;
    while (chr != '\0')
    { // While char is not null 
        chr = *str;
        uart_putchar(chr);
        ++str;
    }
}

char uart_getchar(void){
    // Wait untill the data is set
    loop_until_bit_is_set(UCSR0A, RXC0);
    // Take data from memory and return it.
    return UDR0;
}

void uart_echo(void) {
    char chr = uart_getchar();
    uart_putchar(chr);
}
