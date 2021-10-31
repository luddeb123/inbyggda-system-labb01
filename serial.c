#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

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

bool serial_available(){
    if(!(UCSR0A & (1 << UDRE0))){
        return false;
    }
    return true;
}

void uart_putchar(char chr){
    if(chr == '\r' || chr == '\n'){
        while (!serial_available());
        UDR0 = '\r';
        while (!serial_available());
        UDR0 = '\n';
    }
    else {
        while (!serial_available());
        UDR0 = chr;
    }
}

void uart_putstr(char *str){
    char chr = *str;
    while (chr != '\0'){
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

void uart_get_command(char *command){
    char c;
    int i = 0;
    c = uart_getchar();
    uart_putchar(c);
    while((c != '\r') && (c !='\n') && (i <=(MAX_COMMAND_SIZE-3))){
        command[i] = c;
        i++;
        c = uart_getchar();
        uart_putchar(c);
    }
    command[i] = '\r';
    command[i+1] = '\n';
    command[i+2] = '\0';
}
