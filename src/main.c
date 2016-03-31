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
#include "can.h"


int main(void) {

  // Initialize the MCP2515
can_init(BITRATE_125_KBPS);

// Create a test message
can_t msg;

msg.id = 0x123456;
msg.flags.rtr = 0;
msg.flags.extended = 1;

msg.length = 4;
msg.data [0] = 0xDE;
msg.data [1] = 0xAD;
msg.data [2] = 0xBE;
msg.data [3] = 0xEF;

// Send Message
can_send_message (& msg);

  DDRD = 0xFF;
  DDRC = 0xFF;
  while(1) {
    _delay_ms(50);
    PORTD ^= 0xFF;
    PORTC = PORTD;
  }
}
