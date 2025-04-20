#include<stdio.h>

void main()
{
    int a[9]={5,32,45,9,46,43,647,325,653};
    int i,j,t,min;


    for(i=0;i<9;i++)
    {
        for(j=i;j>0;j--)
        {
            if(a[j]<a[j-1])
            {
                t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
            
        }
    }
    for(i=0;i<9;i++)
    {
        printf("%d ",a[i]);
    }
}