#include<stdio.h>
char stack[100];
int top=-1;

void push(char c)
{
	stack[++top]=c;
}
char pop()
{
	return(stack[top--]);
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
	char *e,c,el;
	printf("Enter the expression : ");
	scanf("%s",exp);
	e=exp;
	while(*e!='\0')
	{
		if(*e=='(')
			push(*e);		
		else if(*e==')')
		{
			while((el=pop())!='(')
				printf("%c",el);
		}
		else if(*e=='^' || *e=='*' || *e=='/' || *e=='+' || *e=='-')
		{
			if(top==-1)
				push(*e);
			else
			{
				while(pre(stack[top])>=pre(*e))
				{
					printf("%c",pop());
				}
				push(*e);
			}
		}
		else
		{
			printf("%c",*e);
		}
		e++;
	}
	while(top>=0)
		printf("%c",pop());
}

