#include<stdio.h>
void af(int *a);
void main()
{
    int a[5]={1,2,3,4,5};
    af(a);
}

void af(int *a)
{
    for(int i=0;i<=4;i++)
    {
        printf("%d\n",*(a+i));
    }
    
}

// #include<stdio.h>

// void main()
// {
//     int a[5]={1,2,3,4,5};
//     int *p=a;
//     printf("%d",*(p+1));
// }
