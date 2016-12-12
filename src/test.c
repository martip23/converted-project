#include <avr/io.h>
#include <util/delay.h>
#include "../include/sonar.h"

#define GREEN_PIN		4
#define BLUE_PIN		5

#define BUZZ_PIN		1

#define TRIG_PIN		2	
#define ECHO_PIN		4

#define RED_ON          (PORTB |= (0x0F))
#define RED_OFF         (PORTB &= ~(1<<RED_PIN))
#define GREEN_ON        (PORTB |= (0x10))
#define GREEN_OFF       (PORTB &= ~(1<<GREEN_PIN))
#define YELLOW_ON		(PORTB |= (1<<RED_PIN) | (1<<GREEN_PIN))
#define YELLOW_OFF		(PORTB &= (0x00))

#define TRIG_ON			(PORTD |= (1<<TRIG_PIN))
#define	TRIG_OFF		(PORTD &= ~(1<<TRIG_PIN))

#define SONAR_CONFIG	(DDRD |= (1<<TRIG_PIN))
#define OUTPUT_CONFIG   (DDRB |= (1<<RED_PIN) | (1<<GREEN_PIN) | (1<<BUZZ_PIN))
#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

// Sonar 
int getDistance() {
  // establish variables for duration of the ping, 
  // and the distance result in centimeters:
  long duration, centimeters;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
	TRIG_OFF;
	_delay_ms(2);
	TRIG_ON;
	_delay_ms(10);
	TRIG_OFF;

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH, 20);

  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  centimeters = duration / 29 / 2;

    return centimeters;
}
=======
#define BUZZ_ON          (PORTB |= (1<<BUZZ_PIN))
#define BUZZ_OFF         (PORTB &= ~(1<<BUZZ_PIN))

#define OUTPUT_CONFIG   (DDRB |= (1<<RED_PIN) | (1<<GREEN_PIN) | (1<<BUZZ_PIN))
>>>>>>> 2147ceb3d353933d7bdaa29fa1565a287006e8cf


int main(void) {

<<<<<<< HEAD
    CPU_PRESCALE(2);
    SONAR_CONFIG;
	OUTPUT_CONFIG;
    
	while(1){
    
	}
=======
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
>>>>>>> 2147ceb3d353933d7bdaa29fa1565a287006e8cf
}
