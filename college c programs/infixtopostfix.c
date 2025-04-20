#include<stdio.h>
void push(char* a, int*t,char el)
{
	a[*t]=el;
	*t=*t+1;
}

char pop(char* a, int* t)
{
	*t=*t-1;
	return a[*t];
}

int prec(char c)
{
	if(c=='^')
	{
	return 3;
	}
	else if(c=='*' || c=='/')
	{
	return 2;
	}
	else if(c=='+' || c=='-')
	{
	return 1;
	}
	return -1;
}


void main()
{
	char c[100],q[100],p[100],el;
	int tp=0,tq=0,i;
	printf("Enter the infix expression: ");
	scanf("%s",&c);
	for(i=0;c[i]!='\0';i++)
	{
	switch(c[i])
	{
	case '(':
		push(q,&tq,'(');
		break;
	case ')':
		el=pop(q,&tq);
		while(el!='(')
		{	
			push(p,&tp,el);
			el=pop(q,&tq);
		}
		break;
	case '-':
	case '+':
	case '*':
	case '/':
	case '^':
		if(tq==0)
		{
		push(q,&tq,c[i]);
		break;
		}

		el=pop(q,&tq);
		while(prec(el)>prec(c[i]))
		{
			push(p,&tp,el);
			el=pop(q,&tq);
			if(tq==0)
			break;
		}	
		push(q,&tq,el);
		push(q,&tq,c[i]);
		break;	
	default:	
		push(p,&tp,c[i]);
		break;
	}
}
while(tq>0)
{
	el=pop(q,&tq);
	push(p,&tp,el);
}
for(i=1;i<=tp+1;i++)
{
	printf("%c",p[i]);
}
}
