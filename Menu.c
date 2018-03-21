#include "Menu.h"


void default_menu() {
	char *message[4] = {"1 Signal Toggle", "2 Sample Rate", "3 Sample Mode", "4 Change Filter"};
	
	send_multiline_message(message);
	
	bool pressed = false;
	
	while(!pressed) {
		// watch for button press
		pressed = true; // innocent until proven guilty
		if(switch_pressed(switch_1)) {
			// toggle the signal
		} else if (switch_pressed(switch_2)) {
			// go to sample rate menu
			sample_rate_menu();
		} else if (switch_pressed(switch_3)) {
			// go to sample mode menu
			sample_mode_menu();
		} else if (switch_pressed(switch_4)) {
			// go to change filter menu
			filter_select_menu();
		} else if (switch_pressed(switch_5)) {
			// scroll up
			scroll_up();
		} else if (switch_pressed(switch_6)) {
			// scroll down
			scroll_down();
		} else {
			pressed = false; // proven guilty
		}
	}
}

void sample_rate_menu() {
	char *message[3] = {"1 Option1", "1 Option1", "1 Option1"};
	
	send_multiline_message(message);
	
	bool pressed = false;
	
	while(!pressed) {
		// watch for button press
		pressed = true; // innocent until proven guilty
		if(switch_pressed(switch_1)) {
			// choose option1
		} else if (switch_pressed(switch_2)) {
			// choose option2
		} else if (switch_pressed(switch_3)) {
			// choose option3
		} else if (switch_pressed(switch_5)) {
			// scroll up
			scroll_up();
		} else if (switch_pressed(switch_6)) {
			// scroll down
			scroll_down();
		} else {
			pressed = false; // proven guilty
		}
	}
}

void sample_mode_menu() {
	char *message[2] = {"1 FIR mode", "1 Sample/Output"};
	
	send_multiline_message(message);
	
	bool pressed = false;
	
	while(!pressed) {
		// watch for button press
		pressed = true; // innocent until proven guilty
		if(switch_pressed(switch_1)) {
			// choose FIR mode
		} else if (switch_pressed(switch_2)) {
			// choose sample/output mode
		} else if (switch_pressed(switch_5)) {
			// scroll up
			scroll_up();
		} else if (switch_pressed(switch_6)) {
			// scroll down
			scroll_down();
		} else {
			pressed = false; // proven guilty
		}
	}
}

void filter_select_menu() {
	char *message[3] = {"1 Filter1 (LP1)", "1 Filter2 (LP2)", "1 Filter3 (HP)"};
	
	send_multiline_message(message);
		
	bool pressed = false;
	
	while(!pressed) {
		// watch for button press
		pressed = true; // innocent until proven guilty
		if(switch_pressed(switch_1)) {
			// choose filter1
		} else if (switch_pressed(switch_2)) {
			// choose filter2
		} else if (switch_pressed(switch_3)) {
			// choose filter3
		} else if (switch_pressed(switch_5)) {
			// scroll up
			scroll_up();
		} else if (switch_pressed(switch_6)) {
			// scroll down
			scroll_down();
		} else {
			pressed = false; // proven guilty
		}
	}
}