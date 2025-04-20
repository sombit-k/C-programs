#include<stdio.h>
void main(){
    int n,i,j;
    printf("ENTER NUMBER OF ROWS: ");
    scanf("%d",&n);

    for(i=n;i>=1;i--)
    {
        for(j=i;j>0;j--)
        {
            printf(" ");
        }
        for(j=0;j<=(n-i)*2;j++)
        {
            if(j==0 || j==(n-i)*2)
            {
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for(i=0;i<=n;i++)
    {
        printf("* ");
    }
}