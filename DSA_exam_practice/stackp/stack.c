#include<stdio.h>

void dc()
{
    printf("\n1)push\n2)pop\n3)Display\n4)Stop\n");
}

void main()
{
    int a[100];
    int n,i,p,top,d;
    top=0;
    printf("Enter the size of the stack: ");
    scanf("%d",&n);
    dc();
    while(1)
    {
        printf("Your choice: ");
        scanf("%d",&p);
        switch(p)
        {
            case 1:
                if(top==n)
                {
                    printf("Stack overflow!\n");
                    break;
                }
                printf("Enter the value to push: ");
                scanf("%d",&d);
                a[top]=d;
                printf("top is %d\n",top);
                top++;
                break;
            case 2:
                if(top<=0)
                {
                    printf("Stack underflow!\n");
                    break;
                }
                top--;
                printf("%d popped\n",a[top]);
                break;
            case 3:
                i=top-1;
                while(i>=0)
                {
                    printf("%d ",a[i]);
                    i--;
                }
                printf("\n");
                break;
            case 4:
                return;
            default:
                dc();
        }
    }
}