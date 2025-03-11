#include <stdio.h>
#include <time.h>

int main() {
    int n, key, flag = 0;
    float totalTime;
    clock_t startTime, endTime;

    printf("\nEnter the value of n: ");
    scanf("%d", &n);

    int arr[n];

    for (int i=0; i<n; ++i) {
        arr[i] = i;
    }

    printf("\nEnter the key: ");
    scanf("%d", &key);


    startTime = clock();
    for (int i=0; i < 100000000; ++i) {}

    int l = 0, r = n-1;
    while ( l <= r ) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) {
            flag = 1;
            break;
        }
        else if (arr[mid] > key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    if (flag) {
        printf("\nKey found");
    } else  {
        printf("\nKey not found!");
    }
    endTime = clock();

    totalTime = (float) (endTime - startTime) / CLOCKS_PER_SEC;

    printf("\nTotal Time Taken: %f", totalTime);
}

