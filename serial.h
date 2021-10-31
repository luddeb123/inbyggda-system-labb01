#ifndef SERIAL_H_
#define SERIAL_H_

#define MAX_COMMAND_SIZE 16

void uart_init(void);

void uart_putchar(char chr);
void uart_putstr(char *chr);

char uart_getchar(void);

void uart_echo(void);

void uart_get_command(char *command);

#endif

