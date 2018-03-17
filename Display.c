#include "MKL25Z4.h"
#include "Defines.h"
#include "Display.h"

void display_init() {
	PTE->PDDR |= MASK(DISPLAY_ENABLE) | MASK(DISPLAY_RW) | MASK(DISPLAY_RS);	// set pins to output
	PTB->PDDR |= 0x00000F0F;	// set pins to output
	delayMs(30);
	LCD_command(0x30);
	delayMs(10);
	LCD_command(0x30);
	delayMs(1);
	LCD_command(0x30);
	
	LCD_command(0x38);				// 8bit data, 2-line, 5x8 ch
	LCD_command(0x06);				// move cursor right
	LCD_command(0x01);				// clr screen, home cursor
	LCD_command(0x0F);				// display on, cursor blinking
}


void LCD_command(uint32_t command) {
	PTE->PCOR |= MASK(DISPLAY_RW ) | MASK(DISPLAY_RS);
	PTB->PSOR &= 0xFFFFF0F0;
	PTB->PSOR &= ((command & 0x000000F0) << 4 | (command & 0x0000000F));		// get lower 8 bits and send them to portB0-3 and portB8-11
	PTE->PSOR |= MASK(DISPLAY_ENABLE);
	PTE->PCOR |= MASK(DISPLAY_ENABLE);		// trigger enable to write to display
  delayMs(0);
	if (command < 4) {
		delayMs(4);			/* command 1 and 2 need 1.64ms  */
	} else {
		delayMs(1);  		/* all others 40us */
	}
}


void delayMs(uint32_t n) {
	uint32_t i;
	uint32_t j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < 7000; j++) {}
	}
}


void send_message(char **display_lines) {
	
}


void scroll_up () {
	
}


void scroll_down () {
	
}
