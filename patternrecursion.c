#include<stdio.h>

double patt(int n);

double patt(int n)
{
    if(n==0)
    return 1;
    return n/ patt(n-1);
}

void main()
{
    printf("%f",patt(3));
}