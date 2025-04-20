#include<stdio.h>

union id
{
    /* data */
    char name[50];
    char id[14];
}data;

void main()
{
    printf("Enter details");
    scanf("%s",&data.name);
    scanf("%s",&data.id);
    printf("%s",data.name);
    printf("%s",data.id);
}
