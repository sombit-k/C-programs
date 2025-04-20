#include<stdio.h>
// #include<bool.h>
#define STACKSIZE 100

struct Stack
{
    int pos;
    int items[STACKSIZE];
}s;

int isEmpty(struct Stack *ps)
{
    return ps->pos==0;
}
void push(struct Stack *ps,int el)
{
    ps->items[++ps->pos]=el;
    printf("\nelement %d pushed",ps->items[ps->pos]);
    printf("\ttop is %d",ps->pos);
}
int pop(struct Stack *ps)
{
    return ps->items[ps->pos--];
}
void displayOptions()
{
    printf("\nEnter the operation you want to perform: \n1: Push\n2: Pop\n3: IsEmpty\n4: Display all elements\n5: Exit\n");
}
void main()
{
    int i,op,el,b=1;
    s.pos=0;    
    displayOptions();
    while(b)
    {
        printf("\nYour option : ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("\nEnter the element to push : ");
            scanf("%d",&el);
            push(&s,el);
            break;
        case 2:
            if(isEmpty(&s))
            {
                printf("\nStack is empty\n");
            }
            else
            {
                el=pop(&s);
                printf("\n Item Popped : %d\n",el);
            }
            break;
        case 3:
            isEmpty(&s)?printf("\nThe stack is empty!!\n"):printf("\nThe stack has elements\n");
            break;
        case 4:
        if(!isEmpty(&s))
        {
            printf("\nThe elements of the stack is :\n");
            printf("Top : %d\n",s.items[s.pos]);
            for(i=s.pos-1;i>=1;i--)
            {
                printf("element %d : %d\n",i,s.items[i]);
            }
        }
        else
        {
            printf("\nStack is empty !!\n");
        }
            break;
        case 5:
            printf("\nExiting the stack!");
            b=0;
            break;
        default:
            printf("\nWrong choice!!\n");
            displayOptions();
            break;
        }
    }
}