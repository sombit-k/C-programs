#include<stdio.h>
struct stack
{
   int t;
   int size;
};

void main()
{
    struct stack p;
    p.t=100;
    printf("%d",p.t);
}