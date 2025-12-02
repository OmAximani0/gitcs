#include <reg51.h>

void delay(unsigned int t) {
    unsigned int i, j;
    for (i=0; i < t; ++i)
        for (j=0; j < 1275; ++j);
}

int main(void) {
    unsigned char i = 0;
    while (1) {
        for (i=0; i < 0xFF; ++i) {
            P2 = i;
            delay(5);
        }
    }
}
