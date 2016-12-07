#define IS_SWITCH1_PRESSED() !(PINB &(1<<PB1))
#define IS_SWITCH2_PRESSED() !(PINB &(1<<PB5))
#define IS_SWITCH3_PRESSED() !(PINB &(1<<PB0))
#define IS_SWITCH4_PRESSED() !(PINB &(1<<PB3))
#define IS_SWITCH5_PRESSED() !(PINB &(1<<PB2))
void init_peripheral();

