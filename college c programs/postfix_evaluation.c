#include<stdio.h>
#include<math.h>
void push(int* a, int*t,int el)
{
	*(a+(*t)+1)=el;
	*t=*t+1;
}

int pop(int* a, int* t)
{
	int el = *(a+*t);
	*t=*t-1;
	return el;
}
void main()
{
	char c[100];
	int a[100],t=0,e1,e2;
	printf("Enter the postfix expression: ");
	scanf("%s",&c);
	for(int i=0;c[i]!='\0';i++)
	{
	switch(c[i])
	{
	case '+':
		e1=pop(a,&t);
		e2=pop(a,&t);
		push(a,&t,e1+e2);
		break;
	case '-':
		e1=pop(a,&t);
		e2=pop(a,&t);
		push(a,&t,e1-e2);
		break;
	case '*':
		e1=pop(a,&t);
		e2=pop(a,&t);
		push(a,&t,e1*e2);
		break;
	case '/':
		e1=pop(a,&t);
		e2=pop(a,&t);
		push(a,&t,e2/e1);
		break;
	case '^':
		e1=pop(a,&t);
		e2=pop(a,&t);
//		push(a,&t,math.pow(e1,e2));
		break;
	default:
		
		push(a,&t,c[i]-'0');
	}
	}
	printf("%d",a[1]);
}
