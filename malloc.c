#include<stdlib.h>
#include<stdio.h>
void main()
{
    printf("sizeof(int)= %d",sizeof(int));
    int *p= (int*)malloc(4*sizeof(int));
    for(int j =0;j<4;j++)
        scanf("%d",p+j);
    for(int j =0;j<4;j++)
        printf("%d",*(p+j));
}