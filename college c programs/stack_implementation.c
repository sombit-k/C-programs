#include<stdio.h>

int pop(int* a,int* t)
{
	int el;
	el=*(a+(*t));
	*t=*t-1;
	return el;
}
void push(int* a, int*t,int el)
{
	*(a+(*t)+1)=el;
	*t=*t+1;
	printf("Element pushed\n");
}
void display(int*a , int t)
{	
	printf("\n\n\nThe stack is\n");
	while(t>0)
	{
		printf("%d \n",*(a+t));
		t--;
	}	
}
void main()
{
	int a[100],t,el;
	char c;
	t=0;
	printf("Press \n1 for push,\n 2 for pop, \n 3 for Display\n 4 to stop execution\n");
	while(1)
	{
		printf("Enter your option\n");
		scanf("%c",&c);
		scanf("");
		switch(c)
		{
		case '1':printf("Enter the element to push: ");
			scanf("%d",&el);
			push(a,&t,el);
			break;

		case '2':
			if(t==0)
			{
			printf("Stack is Empty");
			break;
			}
			el = pop(a,&t);
			printf("The popped item is: %d \n",el);	
			break;
		case '3':
			display(a,t);
			break;
		case '4':
			return;	
		}	
	}
}
