#include <AT89C5131.h> // All SFR declarations for AT89C5131

sbit LED = P1^4; //assigning label to P1^4 as "LED"
sbit PARITY = PSW^0;

void delayms(unsigned int ms_sec);

void ISR_Serial(void) interrupt 4 {
	LED = ~LED;
	TI = 0;
	SBUF = 0xAA;
}

void init_serial() {
	TMOD = 0x20;
	TH1 = 0xCC;
	FE_SM0 = 1;
	SM1 = 1;
	// setting interrupts
	ES = 1;
	ET1 = 0;
	ACC = 0xAA;
	// doing parity check
	ACC += 1;
	ACC -= 1;
	TB8 = PARITY;
	EA = 1;
	SBUF = 0xAA;
	// starting timer
	TR1 = 1;
}

void main (void) {
	LED = 0;
	init_serial();
	while(1);
}

void delayms(unsigned int ms_sec) {
	unsigned int i,j;
	for (i=0;i<ms_sec;i++) {
		for (j=0;j<355;j++);
	}
}