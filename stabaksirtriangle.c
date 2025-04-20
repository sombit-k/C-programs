#include<stdio.h>
void main(){
    int n,i,j;
    printf("Enter number of rows: ");
    scanf("%d",&n);
    for(i=n;i>=0;i--)
    {
        for(j=i;j>0;j--)
        {
            printf(" ");
        }
        for(j=1;j<=((((n-1)-i)*2)+1);j++)
        {
            if(j%2==0)
            {
                printf(" ");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
}