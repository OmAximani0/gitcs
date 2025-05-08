#include <stdio.h>
#include <stdlib.h>

int main() {
    int tph, i, howhung, cho;
    int philname[20], status[20], hu[20];
    printf("\n\nDINING PHILOSOPHER PROBLEM\n");
    printf("Enter the total no. of philosophers: ");
    scanf("%d", &tph);
    for (i = 0; i < tph; i++) {
        philname[i] = (i + 1);
        status[i] = 1; // 1 means thinking, 2 means hungry
    }
    printf("How many are hungry: ");
    scanf("%d", &howhung);
    if (howhung == tph) {
        printf("\nAll are hungry..\nDeadlock stage will occur");
        printf("\nExiting\n");
        exit(0);
    } else {
        for (i = 0; i < howhung; i++) {
            printf("Enter philosopher %d position (1 to %d): ", (i + 1), tph);
            scanf("%d", &hu[i]);
            if (hu[i] < 1 || hu[i] > tph) {
                printf("Invalid position! Exiting.\n");
                exit(0);
            }
            hu[i]--; // Adjust for zero-based indexing
            status[hu[i]] = 2; // Mark as hungry
        }
        do {
            printf("\n1. One can eat at a time\n2. Exit\nEnter your choice: ");
            scanf("%d", &cho);
            if (cho == 1) {
                int pos = 0, x;
                printf("\nAllow one philosopher to eat at any time\n");
                for (i = 0; i < howhung; i++, pos++) {
                    printf("\nP %d is granted to eat", philname[hu[pos]]);
                    for (x = pos + 1; x < howhung; x++) {
                        printf("\nP %d is waiting", philname[hu[x]]);
                    }
                }
            } else if (cho == 2) {
                exit(0);
            } else {
                printf("\nInvalid option..\n");
            }
        } while (1);
    }
    return 0;
}
