#include <reg51.h>

int main(void) {
    SCON = 0x50;

    TMOD = 0x20;
    TH1 = -3;
    TR1 = 1;
    TI = 0;

    while (1) {
        SBUF = 'A';
        while (TI == 0);
        TI = 0;
    }
}
