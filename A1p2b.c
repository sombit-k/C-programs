#include<stdio.h>
void main()
{
    int a,b,s,d,p,q,r;
    printf("2nums");
    scanf("%d%d",&a,&b);
    s=a+b;
    d=a-b;
    p=a*b;
    q=a/b;
    r=a%b;
    printf("sum: %d \n %d %d %d %d" ,s,d,p,q,r);
}