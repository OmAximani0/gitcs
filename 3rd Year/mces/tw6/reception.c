#include <reg51.h>

int main(void) {
    unsigned char b;
    
    SCON = 0x50;

    TMOD = 0x20;
    TH1 = -3;
    TR1 = 1;

    while (1) {
        while (RI == 0);
        RI = 0;
        b = SBUF;
        P1 = b;
        SBUF = b;
        while (TI == 0);
        TI = 0;
    }
}
