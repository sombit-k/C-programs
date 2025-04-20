#include<stdio.h>
struct info
{
    int age;
    char name[500];
}a[3];

void main()
{
    char c;
    printf("Enter the details: \n");
    for(int i=0;i<3;i++)
    {
    printf("Enter the age: ");
    scanf("%d",&a[i].age);
    printf("Enter the name: ");
    scanf("%s",&a[i].name);
    // for(int j=0;;j++)
    // {
    //     scanf("%c",&c);
    //     if(c=='\0')
    //     {
    //         a[i].name[j]=='\0';
    //         break;
    //     }
    //     a[i].name[j]==c;
    // }
    
    }
    printf("Details successfully entered\n");
    for(int i=0;i<3;i++)
    {
    printf("\nage: %d",a[i].age);
    printf("\nname: %s",a[i].name);
    }
}
