#include <stdio.h>

int a[50][50], n, bvisited[50];
int q[50], front = -1, rear = -1;

void bfs(int start) {
    int i, cur;
    bvisited[start] = 1;
    q[++rear] = start;
    printf("%d ", start);  // Print the starting vertex

    while (front != rear) {
        cur = q[++front];
        for (i = 1; i <= n; i++) {
            if (a[cur][i] == 1 && bvisited[i] == 0) {
                q[++rear] = i;
                bvisited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

int main() {
    int start, i, j;

    printf("\nEnter the number of vertices in graph: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    for (i = 1; i <= n; i++) bvisited[i] = 0;

    printf("\nEnter the starting vertex: ");
    scanf("%d", &start);

    printf("\nNodes reachable from starting vertex %d are: ", start);
    bfs(start);
    printf("\n");

    return 0;
}

