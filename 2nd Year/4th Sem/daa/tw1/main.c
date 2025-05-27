#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int arr[10000], i, j, h, n, key, flag = 0;
    clock_t start, end;
    float t;

    printf("\nEnter value for 'n': ");
    scanf("%d", &n);
    for (i=0; i<n; ++i) {
        arr[i] = rand();
    }

    printf("\nEnter key element: ");
    scanf("%d", &key);
    start = clock();

    // NOTE: increase this number to increase the delay
    for (j=0; j<100000000; ++j) {}

    for (i=0; i<n; ++i) {
        if (arr[i] == key) {
            flag = 1;
            break;
        }
    }

    if (flag) printf("\nKey Element Found!");
    else printf("\nKey Element not found!");

    end = clock();
    t = (float) (end-start) / CLOCKS_PER_SEC;
    printf("\nTotal Time Taken: %f", t);

    return 0;
}
