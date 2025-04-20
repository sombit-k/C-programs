#include<stdio.h>
#include<math.h>
void push(char* a, int*t,int el)
{
	*(a+(*t)+1)=el;
	*t=*t+1;
}

char pop(char* a, int* t)
{
	char el = *(a+*t);
	*t=*t-1;
	return el;
}

int prec(char c)
{
	if(c=='^')
	return 3;
	else if(c=='*' || c== '/')
	return 2;
	else if(c=='+' || c=='-')
	return 1;
	else return -1;
}
void main()
{
	char c[100],q[100],p[100];
	int tp=0,tq=0,b,el,i;
	printf("Enter the postfix expression: ");
	scanf("%s",&c);
	while(c[i]!='\0')
	{
		
		if(c[i]=='(')
		{
			push(p,&tp,'(');
		}
		else if(c[i]==')')
		{
			while((el=pop(q,&tq)!='('))
			{
				push(p,&tp,el);
			}
			if(q[tq]==')' && tq!=-1)
		}
		else if(c[i]=='+' ||c[i]=='-' || c[i]=='*' || c[i]=='\\' ||
c[i]=='^')
		{
			while(prec(q[tq])>=prec(c[i]))
			{
				push(p,&tp,c[i]);
			}
		push(q,&tq,c[i]);
		}
		else
		{
		push(p,&tp,c[i]);
		}
	}
	while(tp>0)
	{
		printf("%c ",p[tp]);
		tp--;
	}

}

