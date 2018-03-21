#include "Switches.h"


void switch_init() {
//	Make switch pins GPIO
	for(int sw = switch_1; sw <= switch_6; sw++) {
		PORTC->PCR[sw] &= ~PORT_PCR_MUX_MASK;
		PORTC->PCR[sw] |= PORT_PCR_MUX(1);
	}
	
//	Set ports to input
	PTC->PDDR &= ~MASK(switch_1) | ~MASK(switch_2) | ~MASK(switch_3) | ~MASK(switch_4) | ~MASK(switch_5) | ~MASK(switch_6);
}

bool switch_pressed(int sw) {
	if (!(PTC->PDIR & MASK(sw))) {
		return true;
	}
}
