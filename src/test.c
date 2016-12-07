#include <avr/io.h>
#include <util/delay.h>

#define RED_PIN			3
#define GREEN_PIN		4
#define BLUE_PIN		5

#define BUZZ_PIN		9

#define RED_ON          (PORTB |= (1<<RED_PIN))
#define GREEN_ON        (PORTB |= (1<<GREEN_PIN))
#define YELLOW_ON       (PORTB |= (1<<LED_PIN))
#define LED_OFF         (PORTB &= ~(1<<LED_PIN))

#define LED_CONFIG      (DDRB |= (1<<RED_PIN))
#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

int main(void) {

    CPU_PRESCALE(2);
    LED_CONFIG;
    LED_OFF;

    while(1){
        RED_ON;
        _delay_ms(500);
        RED_OFF;
        _delay_ms(500);
    }
}
