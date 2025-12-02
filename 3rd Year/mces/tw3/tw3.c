#include <reg51.h>

void delay() {
    TMOD = 0x10;    // TIMER 1, MOD 1
    // 50ms delay
    TH1 = 0x4B;
    TL1 = 0xFD;
    TR1 = 1;
    while (TF1 == 0);
    TR1 = 0;
    TF1 = 0;
}

int main(void) {
    while (1) {
        P2 = 0x00;
        delay();
        P2 = 0xFF;
        delay();
    }
    return 0;
}
