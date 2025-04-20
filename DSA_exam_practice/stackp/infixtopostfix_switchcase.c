#include<stdio.h>

char stack[100];
int top=-1;

void push(char a)
{
    stack[++top]=a;
}

char pop()
{
    if(top==-1)
        return -1;
    else
        return stack[top--];
}

int pre(char c)
{
    if(c=='^')
        return 3;
    if(c=='*' || c=='/')
        return 2;
    if(c=='+' || c=='-')
        return 1;
    return 0;
}
void main()
{
    char exp[100];
    char*e,el;
    printf("Enter the expression: ");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        switch(*e)
        {
            case '(':
                push(*e);break;
            case ')':
                while((el=pop())!='(')
                    printf("%c",el);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if(top==-1)
                {
                    push(*e);
                    break;
                }
                
                while(top>=0 && pre(stack[top])>=pre(*e))
                {
                    printf("%c",pop());

                }
                push(*e);
                break;
            default:
                printf("%c",*e);
            
        }
        e++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
}