#include <avr/io.h>
#include "led.h"
#include "serial.h"

int main(void){
    char command[MAX_COMMAND_SIZE];
    led_init();
    uart_init();

    while (1) {
        uart_get_command(command);
        change_led_state(command);
    }
    return 1;
}