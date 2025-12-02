#include <reg51.h>

void setTx(unsigned char x) {
    SBUF = x;
    while (TI == 0);
    TI = 0;
}

int main(void) {
    SCON = 0x50;

    TMOD = 0x20;
    TH1 = -6;       // BAUD Rate = 2400
    TR1 = 1;
    TI = 0;

    while (1) {
        setTx('G');
        setTx('I');
        setTx('T');
        setTx(10);
    }

}
