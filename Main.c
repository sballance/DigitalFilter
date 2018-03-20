/*----------------------------------------------------------------------------
 * Author:				Seth Ballance
 * Project Name:	Digital Filter
 * Company:				Walla Walla University
 * Class:					Embedded Systems Design
 *
 * File Name:			Main.c
 * Purpose:				base controller for my project
 *----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * defines
 *----------------------------------------------------------------------------*/
#include "MKL25Z4.h"                    // Device header


#include "Board_LEDs.h"
#include "Defines.h"
#include "Display.h"
#include "My_LEDs.h"
#include "Switches.h"

/*----------------------------------------------------------------------------
 * functions
 *----------------------------------------------------------------------------*/

void delay(volatile unsigned int time_del) {
	while (time_del--) {
		;
	}
}


void initialize_board() {
	// Enable Clock to Port B, C, D, E
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;
	display_init();
	LED_init();
	board_LED_init();
	switch_init();
}
 
/*----------------------------------------------------------------------------
 * main
 *----------------------------------------------------------------------------*/
int main (void) {
	initialize_board();
	
	send_string("Hello World");
	
	while(1) {
//		send_string("Hello World");
//		if(!(PTC->PDIR & MASK(switch_1))) {
//			set_LEDs(1, 1, 1);
//		} else {
//			set_LEDs(0, 0, 0);
//		}
	}
};
