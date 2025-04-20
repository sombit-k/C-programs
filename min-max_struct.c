#include<stdio.h>

struct res{
    int max;
    int min;
};

struct res minmax(int*a,int f,int l)
{
    int mid;
    struct res r;
    struct res r1;
    struct res r2;
    if(f==l)
    {
        r.max=a[f];
        r.min=a[f];
        return r;
    }
    else if((l-f)==1)
    {
        if(a[f]>a[l])
        {
            r.max=a[f];
            r.min=a[l];
        }
        else
        {
            r.min=a[f];
            r.max=a[l];
        }
        return r;
    }
    else
    {
        mid = (f + l) / 2; 
        r1=minmax(a,f,mid);
        r2=minmax(a,mid+1,l);
        r.max=r1.max>r2.max?r1.max:r2.max;
        r.min=r1.min<r2.min?r1.min:r2.min;
        return r;
    }
    
}

void main()
{
    int a[100],n,i;
    struct res r;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    r=minmax(a,0,n-1);
    printf("Maximum element is: %d and minimum element is: %d",r.max,r.min);
}