#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>


#include <avr/interrupt.h>
#include <util/atomic.h>
#include <stdio.h>


int main(void) {
  DDRD = 0xFF;
  DDRC = 0xFF;
  while(1) {
    _delay_ms(50);
    PORTD ^= 0xFF;
    PORTC = PORTD;
  }
}
