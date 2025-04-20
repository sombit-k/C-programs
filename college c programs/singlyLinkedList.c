#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};

struct node * insertB(struct node* head)
{
	struct node* t=(struct node*) malloc (sizeof(struct node));
	int d;
	printf("Enter the data u want to enter: ");
	scanf("%d",&d);
	t->data=d;
	t->link=head;
	return t;
}

struct node * insertE(struct node* head)
{
        struct node* t=(struct node*) malloc (sizeof(struct node));
	struct node* p=(struct node*) malloc (sizeof(struct node));
        int d;
        printf("Enter the data u want to enter: ");
        scanf("%d",&d);
	t->data=d;
	t->link=NULL;
        p=head;

	while(p->link!=NULL)
	p=p->link;
	
	p->link=t;
        return head;
}
struct node * insertM(struct node* head)
{
        struct node* t=(struct node*) malloc (sizeof(struct node));
        struct node* p=(struct node*) malloc (sizeof(struct node));
        int el,d;
        printf("Enter the data of node after which u want to enter: ");
        scanf("%d",&el);
        p=head;
	while(p->data!=el)
	{
		if(p->link==NULL && p->data!= el)
		{printf("Element not found!\n");return head;}
		p=p->link;
	}
	printf("Enter the data to enter: ");
        scanf("%d",&d);
	t->data=d;
	t->link=p->link;
	p->link=t;
        return head;
}

struct node * deleteB(struct node* head)
{
        struct node* t=(struct node*) malloc (sizeof(struct node));
        t=head;
	printf("%d delted\n",t->data);
	head=head->link;
	free(t);
        return head;
}

struct node * deleteE(struct node* head)
{
        struct node* t=(struct node*) malloc (sizeof(struct node));
        struct node* p=(struct node*) malloc (sizeof(struct node));
	t=head;
	p=t->link;
        while(p->link!=NULL)
        {
	p=p->link;
	t=t->link;
	}
	t->link=NULL;
	free(p);
        return head;
}

struct node * deleteM(struct node* head)
{
        struct node* t=(struct node*) malloc (sizeof(struct node));
        struct node* p=(struct node*) malloc (sizeof(struct node));
        int el,d;
        printf("Enter the data of node after which u want to delete: ");
        scanf("%d",&el);
        p=head;
        while(p->data!=el)
        {
                if(p->link==NULL && p->data!= el)
                {printf("Element not found!\n");return head;}
                p=p->link;
        }
        t=p->link;
	p->link=t->link;
	free(t);
        return head;
}

void main()
{
	int d,c;
	struct node* t=(struct node*) malloc (sizeof(struct node));
	struct node* temp=(struct node*) malloc (sizeof(struct node));
	struct node* p=(struct node*) malloc (sizeof(struct node));
	struct node* head=(struct node*) malloc (sizeof(struct node));
	printf("Enter the value for the head node:  ");
	scanf("%d",&d);
	head->data=d;
	head->link=NULL;
	printf("Enter the operation: Insertion\n1)beginning 2)End 3)Middle\nDeletion\n4)beginning 5)End 6)Middle\n7)Display the linked list\n0)To Kill the program!!");
	while(1)
	{
	printf("\nYour choice: ");
	scanf("%d",&c);
	switch(c)
	{
	case 1:
		head=insertB(head);
		break;
	case 2:
		head=insertE(head);
		break;
	case 3:
		head=insertM(head);
		break;
	case 4:
		head=deleteB(head);
		break;
	case 5:
		head=deleteE(head);
		break;
	case 6:
		head=deleteM(head);
		break;
	case 7:
		printf("The linked list is: ");
		p=head;
		while(p->link!=NULL)
		{
		printf("%d ",p->data);
		p=p->link;
		}
		printf("%d ",p->data);
		printf("\n");
		break;
	case 0:
		return;
	}
	}
}
