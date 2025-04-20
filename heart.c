#include<stdio.h>
void main()
{
    int i,j;
    for(i=0;i<1;i++)
    {
        printf(" ");
        for(j=0;j<=8;j++)
        {
            if(j==1 ||j==2 ||j==6 ||j==7 )
            {
                printf(" * ");
            }
            else{
                printf(" ");
            }
        }
        printf("\n ");
        for(j=0;j<=8;j++)
        {
            if(j!=4)
            { 
                printf(" *");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    for(i=0;i<=4;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("  ");
        }
        for(j=0;j<2*(4-i)+1;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    
}