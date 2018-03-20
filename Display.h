#define DISPLAY_RW								(1)		// Read/Write output on port E
#define DISPLAY_RS								(2)		// Register select output on port E
#define DISPLAY_ENABLE						(0)		// Operation (data read/write) enable signal on port E
#define DISPLAY_D0								(0)		// Display D0 (first bit) on port B
#define DISPLAY_D1								(1)		// Display D1 (second bit) on port B
#define DISPLAY_D2								(2)		// Display D2 (third bit) on port B
#define DISPLAY_D3								(3)		// Display D3 (fourth bit) on port B
#define DISPLAY_D4								(8)		// Display D4 (fifth bit) on port B
#define DISPLAY_D5								(9)		// Display D5 (sixth bit) on port B
#define DISPLAY_D6								(10)	// Display D6 (seventh bit) on port B
#define DISPLAY_D7								(11)	// Display D7 (eighth bit) on port B

void display_init();

void LCD_command(uint32_t command);

void delayMs(uint32_t n);

void send_multiline_message(char **display_lines);

void send_string(char *s);

//void scroll_up();

//void scroll_down();
