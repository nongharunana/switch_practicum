#include <avr/io.h>
#include "peri.h"
#define SWITCH_1 PB1
#define SWITCH_2 PB5
#define SWITCH_3 PB0
#define SWITCH_4 PB3
#define SWITCH_5 PB2

void init_peripheral(){
DDRB&=~(1<<SWITCH_1)&~(1<<SWITCH_2)&~(1<<SWITCH_3)&~(1<<SWITCH_4)&~(1<<SWITCH_5);
PORTB|=(1<<SWITCH_1)|(1<<SWITCH_2)|(1<<SWITCH_3)|(1<<SWITCH_4)|(1<<SWITCH_5);

}

