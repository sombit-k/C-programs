#include<stdio.h>

void enq(int*a,int*r,int el)
{
	*r=*r+1;
	a[*r]=el;
}

int deq(int*a,int*f)
{
	int el;
	*f=*f+1;
	el=a[*f];
	return el;
}

void display(int*a,int f,int r)
{
	int i;
	for(i=f+1;i<=r;i++)
	printf("%d ",a[i]);
}

void main()
{
	int a[100],f,r,c,n,el;
	f=0;
	r=0;
	printf("Enter the size of the queue: ");
	scanf("%d",&n);
	while(1)
	{
		printf("\nEnter your choice\n1)enquque\n2)dequeue\n3)display\n4)stop\nYour choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				if(r==n){
					printf("Overflow!!!\n");break;}
				printf("Enter the element to enqueue: ");
				scanf("%d",&el);
				enq(a,&r,el);
				break;
			case 2:
				if(f==r){
					printf("Underflow!!");break;}
				el=deq(a,&f);
				printf("The dequeued element is %d",el);
				break;
			case 3:display(a,f,r);break;
			case 4:return;
		}
	}
}
