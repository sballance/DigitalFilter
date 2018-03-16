#include "MKL25Z4.h"
#include "Defines.h"
#include "Board_LEDs.h"

void board_LED_init() {
//	Make led pins GPIO
	PORTB->PCR[red_led] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[red_led] |= PORT_PCR_MUX(1);
	PORTB->PCR[green_led] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[green_led] |= PORT_PCR_MUX(1);
	PORTD->PCR[blue_led] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[blue_led] |= PORT_PCR_MUX(1);
	
//	Set ports to output
	PTB->PDDR |= MASK(red_led) | MASK(green_led);
	PTD->PDDR |= MASK(blue_led);
	
//	turn on to start
	PTB->PCOR |= MASK(red_led);
	PTB->PCOR |= MASK(green_led);
	PTD->PCOR |= MASK(blue_led);
}


void change_color(int switch_num) {
	switch(switch_num) {
		case switch_1: // set led to red
			PTB->PCOR |= MASK(red_led);
			PTB->PSOR |= MASK(green_led);
			PTD->PSOR |= MASK(blue_led);
			break;
		case switch_2: // set led to green
			PTB->PSOR |= MASK(red_led);
			PTB->PCOR |= MASK(green_led);
			PTD->PSOR |= MASK(blue_led);
			break;
		case switch_3: // set led to blue
			PTB->PSOR |= MASK(red_led);
			PTB->PSOR |= MASK(green_led);
			PTD->PCOR |= MASK(blue_led);
			break;
		case switch_4: // set led to yellow
			PTB->PCOR |= MASK(red_led);
			PTB->PCOR |= MASK(green_led);
			PTD->PSOR |= MASK(blue_led);
			break;
		case switch_5: // set led to magenta
			PTB->PCOR |= MASK(red_led);
			PTB->PSOR |= MASK(green_led);
			PTD->PCOR |= MASK(blue_led);
			break;
		case switch_6: // set led to cyan
			PTB->PSOR |= MASK(red_led);
			PTB->PCOR |= MASK(green_led);
			PTD->PCOR |= MASK(blue_led);
			break;
	}
}
