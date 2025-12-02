#include <reg51.h>

void delay(int t) {
	int i, j;
	for (i=0; i < t; ++i)
		for (j=0; j < 1275; ++j);
}

int main(void) {
	while (1) {
		P2 = 0x55;
		delay(250);
		
		P2 = 0xAA;
		delay(250);
	}
}
