#include <reg51.h>

sbit sw = P1^7;
sbit mb = P1^0;
sbit wv = P2^5;

void timer0(void) interrupt 1 {
    wv = ~wv;
}

int main(void) {
    IE = 0x82;
    TMOD = 0x02;
    TH0 = 0xA4;

	TR0 = 1;
	while (TF0 == 0);
	TR0 = 0;
	TF0 = 0;

    while (1) {
        mb = sw;
    }
}
