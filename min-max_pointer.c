#include<stdio.h>

void maxmin(int*a,int f,int l,int* max,int* min)
{
    int mid;
    if(f==l)
    {
        *max=*min=a[f];
    }
    else if((l-f)==1)
    {
        *max=a[l]>a[f]?a[l]:a[f];
        *min=a[l]>a[f]?a[f]:a[l];
    }
    else
    {
        mid=(f+l)/2;
        int max1, min1;
        maxmin(a,f,mid,max,min);
        maxmin(a,mid+1,l,&max1,&min1);
        if(max1 > *max) *max = max1;
        if(min1 < *min) *min = min1;
    }
}
void main()
{
    int a[100],n,i;
    int max, min;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    maxmin(a,0,n-1,&max,&min);
    printf("Maximum element is: %d and minimum element is: %d",max,min);
}