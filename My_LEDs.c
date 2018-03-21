#include "My_LEDs.h"

void LED_init() {
//	Make led pins GPIO
	for(int led = led_1; led <= led_3; led++) {
		PORTE->PCR[led] &= ~PORT_PCR_MUX_MASK;
		PORTE->PCR[led] |= PORT_PCR_MUX(1);
	}
	
//	Set ports to output
	PTE->PDDR |= MASK(led_1) | MASK(led_2) | MASK(led_3);
}
 

void set_LEDs(bool bit_1, bool bit_2, bool bit_3) {
	if (bit_1) {
		PTE->PSOR |= MASK(led_1);
	} else {
		PTE->PCOR |= MASK(led_1);
	}
	
	if (bit_2) {
		PTE->PSOR |= MASK(led_2);
	} else {
		PTE->PCOR |= MASK(led_2);
	}
	
	if (bit_3) {
		PTE->PSOR |= MASK(led_3);
	} else {
		PTE->PCOR |= MASK(led_3);
	}
}
