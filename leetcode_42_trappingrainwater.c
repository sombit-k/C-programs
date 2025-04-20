#include<stdio.h>

// int max(int* h, int n);
int max(int* h, int n)
{
    int max=*h;
    for(int i = 0; i<n;i++)
    {
        if(max<*(h+i))
        {
            max = *(h+i);
        }
    }
    return max;
}
int trap(int* height, int heightSize) {
    int* a = height;
    int n= heightSize;
    int m = max(a,n);
    int i,j,c=0,p=0,s;
    for(i=1;i<=m;i++)
    {
        c=s=0;
        for(j=0;j<n;j++)
        {
            if(a[j]>=i)
            {
                s=1;
                if (c!=0 && s>0)
                {
                    p=p+c;
                    c=0;
                }
            }
            else if(s)
            {
            c++;
            }
            else continue;
        }
    }
    return p;
}
void main()
{
    int a[12]={0,1,0,2,1,0,1,3,2,1,2,1};
    int d =trap(a,12);
    printf("the answer is %d",d);
}