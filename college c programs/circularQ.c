#include<stdio.h>

void enq(int*a,int*r,int n,int el)
{
	*r=(*r+1)%n;
	a[*r]=el;
}

int deq(int*a,int*f,int n)
{
	int el;
	*f=(*f+1)%n;
	el=a[*f];
	return el;
}

void display(int*a,int f,int r,int n)
{
	f++;
	while(f!=r)
	{
			
		printf("%d ",a[f]);
		f=(f+1)%n;
	}
	if((f+1)<=n)
	{
		printf("%d ",a[r]);
	}
}

void main()
{
	int a[100],f,r,c,n,el;
	f=0;
	r=0;
	printf("Enter the size of the queue: ");
	scanf("%d",&n);n++;
	while(1)
	{
		printf("\nEnter your choice\n1)enquque\n2)dequeue\n3)display\n4)stop\nYour choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				if(f==(r+1)%n){
					printf("Overflow!!!\n");break;}
				printf("Enter the element to enqueue: ");
				scanf("%d",&el);
				enq(a,&r,n,el);
				break;
			case 2:
				if(f==r){
					printf("Underflow!!");break;}
				el=deq(a,&f,n);
				printf("The dequeued element is %d",el);
				break;
			case 3:
				if(f==r)
				{
				printf("Underflow!!\n");
				break;
				}
				display(a,f,r,n);break;
			case 4:return;
		}
	}
}

