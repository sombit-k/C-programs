#include<stdio.h>
int a[100];
int f=0;
int r=0;
void enqueue(int*a,int n)
{
    int d;
    if((r+1)%n==f)
    {
        printf("Queue Overflow\n");
        return;
    }
    r=(r+1)%n;
    printf("Enter the value to be enqueued: ");
    scanf("%d",&d);
    a[r]=d;
}

void dequeue(int*a,int n)
{
    if(f==r)
    {
        printf("Queue Underflow!\n");
        return;
    }
    int d;
    f=(f+1)%n;
    d=a[f];
    printf("%d dequeued",d);
}

void display(int*a,int n)
{
    int i,j;
    i=f;
    while(i!=r)
    {
        i=(i+1)%n;
        printf("%d ",a[i]);
    }
    printf("\n");
}

void main()
{
    int n,c,i;
    printf("Enter the size of the queue: ");
    scanf("%d",&n);n++;
    printf("1)Enqueue\n2)Dequeue\n3)Display\n4)Stop\n");
    while(1)
    {
        printf("Your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                enqueue(a,n);
                break;
            case 2:
                dequeue(a,n);
                break;
            case 3:
                display(a,n);
                break;
            case 4:
                return;
        }
    }
}