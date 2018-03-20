#include "MKL25Z4.h"
#include "Defines.h"
#include "Display.h"

char *message[100];		// initialize array for holding message in case it is long enough to scroll
int current_line = 0;
int last_line = 1;
int line;

void display_init() {
	// Make pins GPIO
	uint32_t k;
	for (k=0; k<4; k++) {
	PORTB->PCR[k] &= ~PORT_PCR_MUX_MASK;   //    low 4 LCD data bits
	PORTB->PCR[k] |= PORT_PCR_MUX(1);
	}

	for (k=8; k<12; k++) {
	PORTB->PCR[k] &= ~PORT_PCR_MUX_MASK;   //    upper 4 LCD data bits
	PORTB->PCR[k] |= PORT_PCR_MUX(1);
	}
	
	for (k=0; k<3; k++) {
	PORTE->PCR[k] &= ~PORT_PCR_MUX_MASK;   //   LCD control 3-bits 
	PORTE->PCR[k] |= PORT_PCR_MUX(1);
	}
	
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
	LCD_command(0x0C);				// display on without cursor
}


void LCD_command(uint32_t command) {
	PTE->PCOR |= MASK(DISPLAY_RW ) | MASK(DISPLAY_RS) | MASK(DISPLAY_ENABLE);
	PTB->PCOR = 0x00000F0F;
	PTB->PSOR |= ((command & 0x000000F0) << 4) | (command & 0x0000000F);	// get lower 8 bits and send them to portB0-3 and portB8-11
	
	// trigger enable to write to display
	PTE->PSOR |= MASK(DISPLAY_ENABLE);
	delayMs(0);
	PTE->PCOR |= MASK(DISPLAY_ENABLE);
  delayMs(0);
	
	if (command < 4) {
		delayMs(4);			// command 1 and 2 need 1.64ms
	} else {
		delayMs(1);  		// all others 40us
	}
}


void LCD_data(uint32_t data) {
	PTE->PCOR = MASK(DISPLAY_RW) | MASK(DISPLAY_ENABLE);					// clear R/W and EN
	PTE->PSOR = MASK(DISPLAY_RS);																	// set RS
	PTB->PCOR = 0x00000F0F;																				// clear output data bits to 0
	PTB->PSOR |= ((data & 0x000000F0) << 4) | (data & 0x0000000F);// output command to portB0-3 and portB8-11
	
	PTE->PSOR = MASK(DISPLAY_ENABLE);															// assert enable
	delayMs(0);
	PTE->PCOR = MASK(DISPLAY_ENABLE);															// de-assert enable
	delayMs(1);	
}


void delayMs(uint32_t n) {
	uint32_t i;
	uint32_t j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < 7000; j++) {}
	}
}


void send_multiline_message(char **display_lines) {
	LCD_command(0x01);							// Clear the screen
	line = 0;
	while(*display_lines)
	{
		message[line] = *display_lines;
		// if this is either the first or second line that we want displayed then display it, otherwise skip it
		if ((line == current_line) && ((1 == (last_line - current_line)) || (0 == (last_line - current_line)))) {
			send_string(*display_lines);
			LCD_command(0xC0);						// Force the cursor to the beginning of the second line
			current_line++;
		}
		display_lines++;
		line++;
	}
}


void send_message(char *string) {
	LCD_command(0x01);							// Clear the screen
	send_string(string);
}
	

void send_string(char *s) {
    while(*s)
    {
			LCD_data(*s);
			s++;
    }
}


void scroll_up() {
	// if we can scroll up
	if (current_line > 2) {
		current_line = current_line - 3;
		last_line = current_line + 1;
		send_multiline_message(message);
	}
}


void scroll_down() {
	// if we can scroll down
	if (line != last_line) {
		current_line = last_line;
		last_line++;
		send_multiline_message(message);
	}
}
