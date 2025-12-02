#include <reg51.h>

unsigned char i;

int main(void) {
    while (1) { 
        for (i=0; i < 255; ++i) {
            P0 = i;
        }

        for (i=255; i > 0; --i) {
            P0 = i;
        }
    }
}
