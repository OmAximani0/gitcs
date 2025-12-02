#include <reg51.h>

void delay(unsigned int t) {
    unsigned int i, j;
    for (i=0; i < t; ++i)
        for (j=0; j < 1275; ++j);
}

int main(void) {
    while (1) {
        P0 = 0xFF;
        delay(250);
        P0 = 0x00;
        delay(50);
    }
}
