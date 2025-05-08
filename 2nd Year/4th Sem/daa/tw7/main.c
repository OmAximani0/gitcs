#include <stdio.h>

#define MAX 10

void Floyd(int W[][10],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    { printf("matrix D[%d]\n", k) ;
        for(i=1;i<=n;i++)
        { for(j=1;j<=n;j++)
            {
                if((W[i][k]+W[k][j])<W[i][j])
                    W[i][j]=W[i][k]+W[k][j];
                printf("%d\t", W[i][j]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int i,j,n;
    int W[MAX][MAX];
    printf("Floyds Algorithm \n");
    printf("Enter number of nodes :");
    scanf("%d",&n);
    printf("\n Enter the edge weights :");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d", &W[i][j]);
    Floyd(W,n);
    return 0;
}
