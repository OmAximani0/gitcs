#include<stdio.h>
#include <stdlib.h>

int a[30],count=0;

//row= index & column=value ie i=row and a[i]=column
int place(int pos)
{
    int i;
    for(i=1;i<pos;i++) //from  1st row to (current row-1)to check with all prev queens
    {
        if(
            (a[i]==a[pos]) || 
            ((abs(a[i]-a[pos])==abs(i-pos)))
        )
            return 0;  //if a queen exists in same column or diagonally
    }
    return 1;
}

void printsol(int n)
{
    int i,j;
    count++;
    printf("\n\nSolution #%d \n\n",count);
    for(i=1;i<=n;i++)
    {               
        for(j=1;j<=n;j++)
        {                   
            if(a[i]==j) printf("Q\t");
            else printf("*\t");
        }
        printf("\n");
    }
}

void queen(int n)
{
    int k=1;
    a[k]=0;
    while(k!=0)
    {
        a[k]=a[k]+1;
        while(a[k]<=n && !place(k))  //while columns are left and k cant be placed
            a[k]++;
        if(a[k]<=n)
        {
            if(k==n)
                printsol(n);
            else
            {
                k++;
                a[k]=0;
            }
        }
        else
        k--;
    }
}

int main()
{	
    int n;
    printf("Enter the Number of queens\n");
    scanf("%d",&n);
    queen(n);
    printf("\nTotal Number of Solutions=%d",count);
}

