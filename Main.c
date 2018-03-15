/*----------------------------------------------------------------------------
 * Author:				Seth Ballance
 * Project Name:	Digital Filter
 * Company:				Walla Walla University
 * Class:					Embedded Systems Design
 *
 * File Name:			main.c
 * Purpose:				base controller for my project
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * defines
 *----------------------------------------------------------------------------*/
#include "MKL25Z4.h"                    // Device header
#include "stdbool.h"										// Booleans

#define red_led		(18)		// PORT B
#define green_led	(19)		// PORT B
#define blue_led	(1)			// PORT D

#define led_1	(3)					// PORT E
#define led_2	(4)					// PORT E
#define led_3	(5)					// PORT E

#define switch_1	(8)			// PORT C
#define switch_2	(9)			// PORT C
#define switch_3	(10)		// PORT C
#define switch_4	(11)		// PORT C
#define switch_5	(12)		// PORT C
#define switch_6	(13)		// PORT C

#define MASK(x) (1UL << (x))

/*----------------------------------------------------------------------------
 * functions
 *----------------------------------------------------------------------------*/
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
 
void LED_init() {
//	Make led pins GPIO
	for(int led = led_1; led <= led_3; led++) {
		PORTE->PCR[led] &= ~PORT_PCR_MUX_MASK;
		PORTE->PCR[led] |= PORT_PCR_MUX(1);
	}
	
//	Set ports to output
	PTE->PDDR |= MASK(led_1) | MASK(led_2) | MASK(led_3);
}
 
void switch_init() {
//	Make switch pins GPIO
	for(int sw = switch_1; sw <= switch_6; sw++) {
		PORTC->PCR[sw] &= ~PORT_PCR_MUX_MASK;
		PORTC->PCR[sw] |= PORT_PCR_MUX(1);
	}
	
//	Set ports to input
	PTC->PDDR &= ~MASK(switch_1) | ~MASK(switch_2) | ~MASK(switch_3) | ~MASK(switch_4) | ~MASK(switch_5) | ~MASK(switch_6);
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

void delay(volatile unsigned int time_del) {
	while (time_del--) {
		;
	}
}

void initialize_board() {
	// Enable Clock to Port B, C, D, E
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;
	LED_init();
	board_LED_init();
	switch_init();
}
 
/*----------------------------------------------------------------------------
 * main
 *----------------------------------------------------------------------------*/
int main (void) {
	initialize_board();
	
	while(1) {
		if(!(PTC->PDIR & MASK(switch_1))) {
			set_LEDs(1, 1, 1);
		} else {
			set_LEDs(0, 0, 0);
		}
	}
}
