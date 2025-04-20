#include<stdio.h>
#include<string.h>
struct info
{
    /* data */
    int acc;
    char name[100];
    int x;
};

void main()
{
    struct info customer;
    struct info *p=&customer;
    p->acc=10;
    customer.x=1;
    printf("enter name");
    gets(customer.name);
    printf("\n%d %d ",customer.acc,customer.x);
    puts(customer.name);
}