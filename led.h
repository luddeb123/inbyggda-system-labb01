#ifndef LED_H
#define LED_H

#define RED_PIN DDB3
#define GREEN_PIN DDB2
#define BLUE_PIN DDB1

#define RED PB3
#define GREEN PB2
#define BLUE PB1

void led_init();
void change_led_state(char*);

#endif