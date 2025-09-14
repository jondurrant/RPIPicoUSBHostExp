/**
 * Jon Durrant.
 *
 * Blink STATUS LED
 */

#include "pico/stdlib.h"
#include "pico/status_led.h"

#define DELAY 500 // in microseconds

int main() {
		int c;
		stdio_init_all ();
	 	bool rc = status_led_init();
	    hard_assert(rc);
	    while (true) {
	    	colored_status_led_set_state(false);
			sleep_us(200);
			c = getchar_timeout_us(0);
			if ( c <= 0){
				colored_status_led_set_on_with_color(0x00FF0000);
			} else {
				colored_status_led_set_on_with_color(0x000FF00);
				while (c > 0){
					c = getchar_timeout_us(1000);
				}
			}
			printf("{\"on\":  true}\n");
			sleep_ms(DELAY);

	        status_led_set_state(false);
	        printf("{\"on\":  false}\n");
	        sleep_ms(DELAY);
	    }
	    status_led_deinit();
}
