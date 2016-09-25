#include <AT89C5131.h> // All SFR declarations for AT89C5131
#define LCD_data  P2	    					// LCD Data port

//Function Declarations
void LCD_Init();
void LCD_DataWrite(char dat);
void LCD_CmdWrite(char cmd);
void LCD_WriteString(char * str, unsigned char len);
void LCD_Ready();
void sdelay(int delay);
void delay_ms(int delay);

sbit LCD_rs = P0^0;  								// LCD Register Select
sbit LCD_rw = P0^1;  								// LCD Read/Write
sbit LCD_en = P0^2;  								// LCD Enable
sbit LCD_busy = P2^7;								// LCD Busy Flag


sbit LED = P1^4; //assigning label to P1^4 as "LED"
sbit SWITCH = P1^0;
sbit PARITY = PSW^0;
int switch_val = 0;
int switch_new_val = 0;
char data_bit;
int pointer = 0;
int received_pointer = 0;
char string[16] = "abcdefghijklmnop";

void ISR_Serial(void) interrupt 4 {
	if (RI == 1) {
		// data has been received
		data_bit = SBUF;
		RI = 0;
		LCD_CmdWrite(0x80 + received_pointer);
		LCD_DataWrite(data_bit);
		received_pointer++;
	}
	if (TI == 1) {
		TI = 0;
		pointer++;
		if (pointer < 16) {
			ACC = string[pointer];
			ACC += 1;
			ACC -= 1;
			TB8 = PARITY;
			SBUF = string[pointer];
			LCD_CmdWrite(0xC0 + pointer);
			LCD_DataWrite(string[pointer]);
		}
	}
}

void init_serial() {
	TMOD = 0x20;
	TH1 = 0xCC;
	FE_SM0 = 1;
	SM1 = 1;
	// setting interrupts
	ES = 1;
	ET1 = 0;
	EA = 1;
	// enabling receiving
	REN = 1;
	// starting timer
	TR1 = 1;
}

int check_switch() {
//function to check switches after every 500ms
	delay_ms(500);
	SWITCH = 1;
	return SWITCH;
	
}

void transmit_data(unsigned char str) {
//function to transmit data over TxD pin.
}

void main (void) {
	SWITCH = 1;
	switch_val = SWITCH;
	LCD_Init();
	LCD_Ready();
	LCD_CmdWrite(0x80);
	LED = 0;
	init_serial();
	while(1) {
		switch_new_val = check_switch();
		LED = switch_new_val;
		if (switch_new_val != switch_val && pointer < 16) {
			// Transmit data
			switch_val = switch_new_val;
			ACC = string[0];
			ACC += 1;
			ACC -= 1;
			TB8 = PARITY;
			SBUF = string[0];
			LCD_CmdWrite(0xC0);
			LCD_DataWrite(string[0]);
		}
	}
}

/**
 * FUNCTION_PURPOSE:LCD Initialization
 * FUNCTION_INPUTS: void
 * FUNCTION_OUTPUTS: none
 */
void LCD_Init()
{
  sdelay(100);
  LCD_CmdWrite(0x38);   	// LCD 2lines, 5*7 matrix
  LCD_CmdWrite(0x0E);			// Display ON cursor ON  Blinking off
  LCD_CmdWrite(0x01);			// Clear the LCD
  LCD_CmdWrite(0x80);			// Cursor to First line First Position
}

/**
 * FUNCTION_PURPOSE: Write Command to LCD
 * FUNCTION_INPUTS: cmd- command to be written
 * FUNCTION_OUTPUTS: none
 */
void LCD_CmdWrite(char cmd)
{
	LCD_Ready();
	LCD_data=cmd;     			// Send the command to LCD
	LCD_rs=0;         	 		// Select the Command Register by pulling LCD_rs LOW
  LCD_rw=0;          			// Select the Write Operation  by pulling RW LOW
  LCD_en=1;          			// Send a High-to-Low Pusle at Enable Pin
  sdelay(5);
  LCD_en=0;
	sdelay(5);
}

/**
 * FUNCTION_PURPOSE: Write Command to LCD
 * FUNCTION_INPUTS: dat- data to be written
 * FUNCTION_OUTPUTS: none
 */
void LCD_DataWrite( char dat)
{
	LCD_Ready();
  LCD_data=dat;	   				// Send the data to LCD
  LCD_rs=1;	   						// Select the Data Register by pulling LCD_rs HIGH
  LCD_rw=0;    	     			// Select the Write Operation by pulling RW LOW
  LCD_en=1;	   						// Send a High-to-Low Pusle at Enable Pin
  sdelay(5);
  LCD_en=0;
	sdelay(5);
}
/**
 * FUNCTION_PURPOSE: Write a string on the LCD Screen
 * FUNCTION_INPUTS: 1. str - pointer to the string to be written, 
										2. length - length of the array
 * FUNCTION_OUTPUTS: none
 */
void LCD_WriteString( char * str, unsigned char length)
{
    while(length>0)
    {
        LCD_DataWrite(*str);
        str++;
        length--;
    }
}

/**
 * FUNCTION_PURPOSE: To check if the LCD is ready to communicate
 * FUNCTION_INPUTS: void
 * FUNCTION_OUTPUTS: none
 */
void LCD_Ready()
{
	LCD_data = 0xFF;
	LCD_rs = 0;
	LCD_rw = 1;
	LCD_en = 0;
	sdelay(5);
	LCD_en = 1;
	while(LCD_busy == 1)
	{
		LCD_en = 0;
		LCD_en = 1;
	}
	LCD_en = 0;
}

/**
 * FUNCTION_PURPOSE: A delay of 15us for a 24 MHz crystal
 * FUNCTION_INPUTS: void
 * FUNCTION_OUTPUTS: none
 */
void sdelay(int delay)
{
	char d=0;
	while(delay>0)
	{
		for(d=0;d<5;d++);
		delay--;
	}
}

/**
 * FUNCTION_PURPOSE: A delay of around 1000us for a 24MHz crystel
 * FUNCTION_INPUTS: void
 * FUNCTION_OUTPUTS: none
 */
void delay_ms(int delay)
{
	int d=0;
	while(delay>0)
	{
		for(d=0;d<382;d++);
		delay--;
	}
}