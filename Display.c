#include "MKL25Z4.h"
#include "Defines.h"
#include "Display.h"

void display_init() {
	delayMs(30);
	LCD_command(0x30);
	delayMs(10);
	LCD_command(0x30);
	delayMs(1);
	LCD_command(0x30);
	
	LCD_command(0x38);															/* 8bit data, 2-line, 5x7 ch*/
	LCD_command(0x06);															/* move cursor right  06    */
	LCD_command(0x01);															/* clr screen, home cursor  */
	LCD_command(0x0F);												/* 0F    display on, cursor blinking*/
}


void LCD_command(uint32_t command) {
//	GPIOC->BRR = RW | RS;                        /* clear lcd R/W and RS        */
//	GPIOA->BSRR = (lcd_clrMask&(~(command<<9))) | (command<<1);
//  GPIOB->BSRR = EN;
//  delayMs(0);
//  GPIOB->BRR = EN;
//	if (command < 4) {
//		delayMs(4);			/* command 1 and 2 need 1.64ms  */
//	} else {
//		delayMs(1);  		/* all others 40us */
//	}
}


void delayMs(uint32_t n) {
	uint32_t i;
	uint32_t j;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 7000; j++) {}
	}
}


void send_message(char **display_lines) {
	
}


void scroll_up () {
	
}


void scroll_down () {
	
}
