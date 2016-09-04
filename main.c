#include <util/delay.h>

#include "uart.h"
#include "ym2149.h"

// Notes
// Np = 2e6 / (16 * Fn)
#define C (2000000 / (16*130.81))
#define D (2000000 / (16*146.83))
#define E (2000000 / (16*164.81))
#define F (2000000 / (16*174.61))
#define G (2000000 / (16*196.00))
#define A (2000000 / (16*220.00))
#define B (2000000 / (16*246.94))

int main() {
  unsigned int i;
  unsigned int data[7] = {C, D, E, F, G, A, B};

  set_ym_clock();
  set_bus_ctl();

  // reset registers
  for (i=0; i<16; i++) {
    send_data(i, 0);
  }
  send_data(7, 0xf8); // Only output clear sound
  send_data(8, 0x0f);
  send_data(9, 0x0f);
  send_data(10, 0x0f);

  for/*ever*/(;;) {
    for (i=0; i<7; i++) {
      send_data(0, data[i] & 0xff);
      send_data(1, data[i] >> 8);
      send_data(2, data[i] >> 1 & 0xff);
      send_data(3, data[i] >> 9);
      send_data(4, data[i] >> 2 & 0xff);
      send_data(5, data[i] >> 10);
      _delay_ms(200.);
    }
  }

  return 0;
}
