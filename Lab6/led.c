#include <AT89C5131.h> // All SFR declarations for AT89C5131

sbit LED = P1^4; //assigning label to P1^4 as "LED"

void delayms(unsigned int ms_sec);

void main (void) {
	P1=0x0F7; // port pin P1.3 as output
	LED=0; //Initialise LED to 0;
	while (1) {
		LED=~LED; // To toggle the LED
		delayms(1000);
	}
}

void delayms(unsigned int ms_sec) {
	unsigned int i,j;
	for (i=0;i<ms_sec;i++) {
		for (j=0;j<355;j++);
	}
}