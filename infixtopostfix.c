#include<stdio.h>

void push(char*a,int*t,char el)
{
	*t=*t+1;
	*(a+*t)=el;
}

char pop(char*a,int*t)
{
	char el=*(a+*t);
	*t=*t-1;
	return el;
}

int pre(char c)
{
	if(c=='^')
		return 3;
	else if(c=='+' || c=='-')
		return 1;
	else if(c=='*' || c=='/')
		return 2;
	else return -1;
}

void main()
{
	char a[100],q[100],p[100],el;
	int i,tp=0,tq=0;
	printf("Enter the infix expression: ");
	scanf("%s",&a);
	for(i=0;a[i]!='\0';i++)
	{
		switch(a[i])
		{
			case '(':
				push(q,&tq,'(');
				break;
			case ')':
				while((el=pop(q,&tq))!='(')
				{
					push(p,&tp,el);
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				if(tq==0)
				{
					push(q,&tq,a[i]);
					break;
				}
				el=pop(q,&tq);
				while(pre(el)>=pre(a[i]))
				{
					push(p,&tp,el);
					el=pop(q,&tq);
					if(tq<=0)
					break;
				}
				push(q,&tq,el);
				push(q,&tq,a[i]);
				break;
			default:
				push(p,&tp,a[i]);
				break;
		}
	}
	if(tq!=0)
		{
			while(tq!=0)
				{
					el=pop(q,&tq);
					push(p,&tp,el);
				}
		}
	for(i=1;i<=tp;i++)
	{
		printf("%c",p[i]);
	}
}
