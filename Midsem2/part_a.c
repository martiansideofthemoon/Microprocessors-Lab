#include <AT89C5131.h> // All SFR declarations for AT89C5131

sbit square = P3^0; //assigning label to P1^4 as "LED"
int counts;

void gen_sig(unsigned int frequency);

void main (void) {
	gen_sig(50);
}

void gen_sig(unsigned int frequency) {
	TMOD = 0x02;
	counts = 1000 / frequency;
	TH0 = 256 - counts;
	TL0 = TH0;
	TR0 = 1;
	while(1) {
		//for (i = 0; i < micros; i++) {
			while(TF0 != 1);
			TF0 = 0;
		//}
		square = ~square;
	}
}
