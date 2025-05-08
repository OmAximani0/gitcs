#include <stdio.h>

int a[10][10], visited[10], n, cost = 0;

void get() {
    int i, j;

    printf("Enter No. of Cities: ");
    scanf("%d", &n);
    printf("\nEnter Cost Matrix: \n");
    for (i = 0; i < n; i++) {
        printf("Enter Elements of Row# %d:\n", i + 1);
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0;
    }

    printf("\nThe cost matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }
}

int least(int c) {
    int i, next_city = -1;
    int min = 999;

    for (i = 0; i < n; i++) {
        if (a[c][i] != 0 && !visited[i]) {
            if (a[c][i] < min) {
                min = a[c][i];
                next_city = i;
            }
        }
    }

    if (next_city != -1) {
        cost += a[c][next_city];
    }

    return next_city;
}

void mincost(int city) {
    int next_city;

    visited[city] = 1;
    printf("%d -> ", city + 1);
    next_city = least(city);

    if (next_city == -1) {
        cost += a[city][0];  // return to start
        printf("1");
        return;
    }

    mincost(next_city);
}

void put() {
    printf("\n\nMinimum cost: %d\n", cost);
}

int main() {
    get();

    // Reset cost in case of multiple runs
    cost = 0;

    printf("\nThe Path is:\n");
    mincost(0);
    put();

    return 0;
}

