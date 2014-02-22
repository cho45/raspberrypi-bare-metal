// Peripherals Data Sheet
// http://www.raspberrypi.org/wp-content/uploads/2012/02/BCM2835-ARM-Peripherals.pdf
//
// Bare metal info:
// https://github.com/dwelch67/raspberrypi
// Bare metal mruby:
// https://github.com/yamanekko/mruby/blob/rubyconf/mrbgems/mruby-rs-led/src/rs_led.c
// https://github.com/yamanekko/raspberrypi/blob/master/README.ja.md

// dead copy from https://github.com/dwelch67/raspberrypi/blob/master/blinker01/blinker01.c

#include "gpio.h"

extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void dummy ( unsigned int );

int notmain ( void ) {
	volatile unsigned int n;

	PUT32(GPFSEL1, (1<<18));

	while (1) {
		GPSET(16);
		for (n = 0; n < 0x100000; n++) dummy(n);
		GPCLR(16);
		for (n = 0; n < 0x100000; n++) dummy(n);
	}
	return 0;
}

