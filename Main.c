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


#include "Menu.h"
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
	
	bool pressed = false;
	
	while(1) {
		if(switch_pressed(switch_1)) {
			set_LEDs(0,0,1);
		} else if (switch_pressed(switch_2)) {
			set_LEDs(0,1,0);
		} else if (switch_pressed(switch_3)) {
			set_LEDs(0,1,1);
		} else if (switch_pressed(switch_4)) {
			set_LEDs(1,0,0);
		} else if (switch_pressed(switch_5)) {
			set_LEDs(1,0,1);
		} else if (switch_pressed(switch_6)) {
			set_LEDs(1,1,0);
		} else {
			pressed = false; // proven guilty
			set_LEDs(1,1,1);
		}
	}
	
//	default_menu();
	
//	while(1) {

//	}
};
