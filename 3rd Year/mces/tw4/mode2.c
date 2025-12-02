// TIMER 1 MOD 2
#include <reg51.h>

int main(void) {
    TMOD = 0x60;
	TH1 = 0;
    while (1) {
        do {
            T1 = 0;
            T1 = 1;

            TR1 = 1;
            P1 = TL1;
        } while (TF1 == 0);
        TR1 = 0;
        TF1 = 0;
    }
}
