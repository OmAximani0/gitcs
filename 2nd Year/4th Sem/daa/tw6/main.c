#include<stdio.h>

#define INFINITY 999
#define MAX 50

void dijkstra(int G[MAX][MAX], int n, int startnode);

int main() {
    int G[MAX][MAX], i, j, n, u, flag = 0;

    printf("Graph: Shortest Path to Other Vertices: Dijkstra Algorithm >>\n\n");
    printf("Enter Number of Vertices Present in the Graph: ");
    scanf("%d", &n);

    printf("\nEnter the Adjacency Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("\nEnter The Starting Node: ");
    scanf("%d", &u);

    printf("\nSo, The Adjacency Matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }

    dijkstra(G, n, u);

    do {
        printf("\nWant to Continueů. 1 for Yes, 0 for No : ");
        scanf("%d", &flag);
        if (flag == 1) {
            printf("\n\nEnter The Starting Node: ");
            scanf("%d", &u);
            dijkstra(G, n, u);
        }
    } while (flag == 1);

    return 0;
}

void dijkstra(int G[MAX][MAX], int n, int startnode) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];

    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    for (i = 0; i < n; i++) {
        if (i != startnode) {
            if (distance[i] == 999) {
                printf("\nThere is no Possible Path Between %d and %d.", i, startnode);
            } else {
                printf("\nDistance of Node %d to %d is: %d", i, startnode, distance[i]);
                printf("\nAnd the Path is: %d ", i);
                j = i;
                do {
                    j = pred[j];
                    printf(" -> %d", j);
                } while (j != startnode);
            }
        }
        printf("\n");
    }
}
