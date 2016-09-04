#include <util/delay.h>
#include <avr/io.h>

void set_ym_clock(void);
void set_bus_ctl(void);

void send_data(char addr, char data);
char read_data(char addr);
