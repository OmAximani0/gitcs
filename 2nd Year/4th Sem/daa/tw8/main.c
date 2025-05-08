#include<stdio.h>
#define MAX 200

int V[MAX][MAX] = {0};
int res[200]={0};
int count=0;

int max(int a, int b) {
    return (a > b)? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i==0 || j==0)
            {
                V[i][j] = 0;
            }
            else if (wt[i-1] <= j)
            {
                V[i][j] = max(val[i-1] + V[i-1][j-wt[i-1]], V[i-1][j]);}
            else {
                V[i][j] = V[i-1][j];
            }
        }

        int k,m;
        //Print matrix after every iteration
        for(k=0;k<=n;k++) {
            for(m=0;m<=W;m++) {
                printf("%d ", V[k][m]);
            }
            printf("\n");
        }
        printf("\n");
    }

    i=n;
    j=W;

    while(i>0 && j>0)
    {
        if(V[i][j] != V[i-1][j])
        {
            res[count++]=i;
            j=j-wt[i-1];
            i--;
        }
        else
        i--;
    }

    return V[n][W];
}

int main()
{
    int i, n, W, optsoln;
    int val[20],wt[20];

    printf("\nEnter number of items:\n");
    scanf("%d", &n);

    printf("\nEnter the weights:\n");
    for(i=0;i<n;i++)
        scanf("%d",&wt[i]);

    printf("\nEnter the values:\n");
    for(i=0;i<n;i++)
        scanf("%d",&val[i]);

    printf("\nEnter the knapsack capacity:");
    scanf("%d",&W);

    optsoln=knapSack(W, wt, val, n);
    
    printf("\nThe optimal soluntion is:%d",optsoln);
    printf("\nThe optimal subset\n");
    printf("Items included in knapsack are:");
    for(i=count-1;i>=0;i--)
        printf("\t%d",res[i]);
    printf("\n");

    return 0;
}
