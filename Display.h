#define RW                 0x00000010    /* Read/Write output on pin 5													*/
#define RS                 0x00000020    /* Register select output on pin 4											*/
#define EN                 0x00000001    /* Operation (data read/write) enable signal on pin 6	*/
#define lcd_clrMask        0x01FE0000    /* bits 8 down to 1 are ones														*/
#define on                 1
#define off                0

void display_init();

void LCD_command(uint32_t command);

void delayMs(uint32_t n);

void send_message(char **display_lines);

void scroll_up();

void scroll_down();
