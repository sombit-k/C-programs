#include<stdio.h>
void enqueue(int*a,int* r,int el,int n)
{
	*r=(*r+1)%n;
	a[*r]=el;
}

int dequeue(int*a,int* f,int n)
{
	int el;
	*f=(*f+1)%n;
	el=a[*f];
	return el;
}

void display(int*a,int f,int r,int n)
{
	printf("The Queue is : ");
	while(f!=r)
	{
		f=(f+1)%n;
		printf("%d  ",a[f]);
	}
	printf("\n");
}

void main()
{
	int n,f,r,c,el;
	r=0;f=0;
	printf("Enter the size of the queue: ");
	scanf("%d",&n);
	n++;
	int a[n];
	printf("Choose: 1) enqueue 2) dequeue 3) display 4) stop");
	while(1)
	{
		printf("\nOption: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				if(f==(r+1)%n)
				{
					printf("Queue Overflow!!");
					break;
				}
				printf("Enter the element: ");
				scanf("%d",&el);
				enqueue(a,&r,el,n);
				break;
			case 2:
				if(f==r)
				{
					printf("Queue underflow");
					break;
				}
				el=dequeue(a,&f,n);
				printf("\nThe dequeued element is: %d",el);
				break;
			case 3: 
				display(a,f,r,n);
				printf("\n");
				break;
			case 4:
				printf("\nTerminating");
				return;
		}
	}
}
