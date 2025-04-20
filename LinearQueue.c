#include<stdio.h>

void enq(int*q,int*r,int*f,int el)
{
    *(q+*r)=el;
	*r=*r+1;
}

int deq(int*q,int*r,int*f)
{

	int el=*(q+*f);
	*f=*f+1;
	return el;
}

void main()
{
	int n,i,f,r,t;
	char c;
	printf("Enter the size of the queue: ");
	scanf("%d",&n);
	int q[n];
	f=0;r=0;
	printf("Operations :-\n1)Enqueue\n2)Dequeue\n3)Display all elements\n4)Stop\n");
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%c",&c);
		scanf("%c");
		switch(c)
		{
			case '1':
				if(r>n-1)
				{
					printf("Overflow!!!\n");
					break;
				}
				printf("Enter the element you want to enqueue: ");
				scanf("%d",&t);
				enq(q,&r,&f,t);
				break;
			case '2':
				if(r<=f)
				{
					printf("Underflow!!!!\n");
					break;
				}
				printf("DeQueued Element is %d\n",deq(q,&r,&f));
				break;
			case '3':
				printf("The queue elements are :");
				for(i=f;i<r;i++)
                printf(" %d",q[i]);
				printf("\n");
				break;
			case '4':
				return;
			default : 
				printf("Wrong CHoice!!\n");
		}
	}
}
