#include<reg51.h>

void delay(unsigned int t) {
    unsigned int i, j;
    for (i=0; i < t; ++i)
        for (j=0; j < 1275; ++j);
}

int main(void) {
    while (1) {
        P2 = 0x10;
        delay(250);
        P2 = 0x20;
        delay(250);
        P2 = 0x30;
        delay(250);
    }
}
