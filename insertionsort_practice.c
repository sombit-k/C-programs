#include<stdio.h>

void main()
{
    int i,j,t;
    int n;
    printf("Enter the size of array: \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: \n");
        for(i=0;i<n;)
    {
        scanf("%d",(a+i++));
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j>=0;j--)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
            else
            {
                break;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
}