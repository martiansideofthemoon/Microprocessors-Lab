/**
 LCD HOMEWORK , LABWORK XX
 */

/* @section  I N C L U D E S */
#include "at89c5131.h"
#define LCD_data  P2	    					// LCD Data port

//Function Declarations
void LCD_Init();
void LCD_DataWrite(char dat);
void LCD_CmdWrite(char cmd);
void LCD_WriteString(char * str, unsigned char len);
void LCD_Ready();
void sdelay(int delay);
void delay_ms(int delay);

sbit CS_BAR = P1^4;									// Chip Select for the ADC
sbit LCD_rs = P0^0;  								// LCD Register Select
sbit LCD_rw = P0^1;  								// LCD Read/Write
sbit LCD_en = P0^2;  								// LCD Enable
sbit LCD_busy = P2^7;								// LCD Busy Flag
sbit send_bit = P3^7;
sbit LED = P1^6;
sbit SWITCH = P1^0;
int switch_val = 0;
int new_switch_val = 0;

char baud_rate = 0xCC;
char data_bit = 0x41;
char received_pointer = 0;
char pointer = 0;
char pointer_var = 0;
int size_data = 11;
char bits[11] = {0,1,1,1,0,0,0,1,0,0,1};
int overflows = 0;
int original = 1154;

//Global Variables
bit transmit_completed= 0;					// To check if spi data transmit is complete
char serial_data, data_save_high, data_save_low;	

void ISR_Serial(void) interrupt 4 {
	//if (RI == 1) {
		// data has been received
		data_bit = SBUF;
		pointer_var = pointer;
		LED = 0;
		RI = 0;
		LCD_CmdWrite(0x80);
		LCD_DataWrite('0'+pointer);
	LCD_CmdWrite(0xC0);
		LCD_DataWrite(data_bit);
		//REN = 0;
	//}
}

void timer0_ISR (void) interrupt 1 {
	TF0 = 0;
	overflows++;
	if (overflows >= 32) {
		overflows = 0;
		send_bit = bits[pointer];
		pointer++;
		if (pointer >= 11) {
			pointer = 0;
		}
	}
}

void init_serial() {
	TMOD = 0x22;
	TH1 = baud_rate;
	TL1 = baud_rate;
	FE_SM0 = 1;
	SM1 = 1;
	PSL = 1;
	// setting interrupts
	ES = 1;
	ET1 = 0;
	EA = 1;
	// enabling receiving
	REN = 1;
	// starting timer
	TR1 = 1;
}

void uart_emulator() {
	TH0 = baud_rate;
	TL0 = baud_rate;
	ET0 = 1;
	TR0 = 1;
}

void main(void)
{
	send_bit = 1;
	LED = 1;
	P2 = 0x00;											// Make Port 2 output 
	LCD_Init();
	LCD_Ready();
	init_serial();
	SWITCH = 1;
	switch_val = SWITCH;
	new_switch_val = SWITCH;
	while(new_switch_val == switch_val) {
		SWITCH = 1;
		new_switch_val = SWITCH;
	}
	uart_emulator();
	while(1);
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
