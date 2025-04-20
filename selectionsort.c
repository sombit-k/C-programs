#include<stdio.h>

void main()
{
    int i,j,t,m;
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
        for(j=i;j<n;j++)
        {
            if(a[i]>*(a+j))
            {
                t=*(a+j);
                *(a+j)=a[i];
                a[i]=t;
            }
        }        
    }
    printf("Sorted array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
}