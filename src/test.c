#include <avr/io.h>
#include <util/delay.h>
#include "../include/Arduino.h"

#define RED_PIN			3
#define GREEN_PIN		4
#define BLUE_PIN		5

#define BUZZ_PIN		1

#define RED_ON          (PORTB |= (0x0F))
#define RED_OFF         (PORTB &= ~(1<<RED_PIN))
#define GREEN_ON        (PORTB |= (0x10))
#define GREEN_OFF       (PORTB &= ~(1<<GREEN_PIN))
#define YELLOW_ON		(PORTB |= (1<<RED_PIN) | (1<<GREEN_PIN))
#define YELLOW_OFF		(PORTB &= (0x00))

#define BUZZ_ON          (PORTB |= (1<<BUZZ_PIN))
#define BUZZ_OFF         (PORTB &= ~(1<<BUZZ_PIN))

#define OUTPUT_CONFIG   (DDRB |= (1<<RED_PIN) | (1<<GREEN_PIN) | (1<<BUZZ_PIN))

int main(void) {

    OUTPUT_CONFIG;
    RED_OFF;
	GREEN_OFF;
    BUZZ_OFF;

    while(1){
        RED_ON;
        _delay_ms(500);
		RED_OFF;
        _delay_ms(500);
		GREEN_ON;
        _delay_ms(500);
		GREEN_OFF;
        _delay_ms(500);
		YELLOW_ON;
        _delay_ms(500);
		YELLOW_OFF;
        _delay_ms(500);
    }
}
