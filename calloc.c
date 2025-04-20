#include<stdlib.h>
#include<stdio.h>
void main()
{
    int *p = (int*) calloc(4,sizeof(int));
    printf("%d",*(p+1));
}