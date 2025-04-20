#include<stdio.h>
void main()
{
    int i,j,k,s,t;
    for(i=1;i<10000;i++)
    {
        s=0;
        for(j=1;j<i;j++)
        {
            if(i%j==0)
            s+=j;
        }
        t=0;
        for(k=1;k<s;k++)
        {
            if(s%k==0)
            t+=k;
        }
        if(t==i &&t<k)
        printf("%d %d\n",t,s);
    }
}