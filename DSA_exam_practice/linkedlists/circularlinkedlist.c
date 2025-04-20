#include<stdio.h>
#include<stdlib.h>

void dp()
{
    printf("1)addb\n2)adde\n3)addm\n4)delb\n5)dele\n6)delm\n7)display\n8)choices\n9)end program\n");
}
struct node{
    int data;
    struct node*link;
};
struct node* nn()
{
    return (struct node*)malloc(sizeof(struct node));
}

struct node* cn()
{
    int d;
    struct node* new=nn();
    printf("Enter the value of the node: ");
    scanf("%d",&d);
    new->data=d;
    new->link=NULL;
    return new;
}

struct node * fln(struct node*head)//find last node
{
    struct node* p;
    p=head;
    while(p->link!=head)
    {
        p=p->link;
    }
    return p;
}

struct node* f2n(struct node* head)//find second last node
{
    struct node* p;
    struct node* q;
    p=head;
    q=p->link;
    while(q->link!=head)
    {
        q=q->link;
        p=p->link;
    }
    return p;
}

struct node * fdn(struct node* head)
{
    struct node*p;
    p=head;
    int d;
    printf("Enter the value of node : ");
    scanf("%d",&d);
    while(p->link!=head)
    {
        if(p->data==d)
            return p;
        p=p->link;
    }
    return NULL;
}

struct node* addb(struct node * head)
{
    struct node* newnode=cn();
    struct node* lastnode=fln(head);
    newnode->link=head;
    lastnode->link=newnode;
    // printf("first node: %d ,link is %u\n",newnode->data,newnode->link);
    // printf("second node: %d ,link is %u\n",(newnode->link)->data,(newnode->link)->link);
    return newnode;
}

struct node* adde(struct node * head)
{
    struct node* newnode=cn();
    struct node* ln=fln(head);
    ln->link=newnode;
    newnode->link=head;
    return head;
}

struct node* addm(struct node * head)//add after an element
{
    struct node* p;
    struct node* q;
    p=fdn(head);
    if(p==NULL)
    {
        printf("Node doesnot exist\n");
        return head;
    }
    q=cn();
    q->link=p->link;
    p->link=q;
    return head;
}


struct node* delb(struct node* head)
{
    struct node *p=nn();
    struct node* ln=fln(head);
    p=head->link;
    ln->link=p;
    printf("%d deleted \n",head->data);
    free(head);
    return p;
}

struct node* dele(struct node* head)
{
    struct node* secondln=f2n(head);
    struct node* ln=secondln->link;
    secondln->link=head;
    printf("%d deleted \n",ln->data);
    free(ln);
    return head;
}

struct node* delm(struct node* head)
{
    struct node* p=fdn(head);
    if(p==NULL)
    {
        printf("Node does not exists!!\n");
        return head;
    }
    struct node* q=nn();
    q=p->link;
    p->link=q->link;
    printf("%d deleted \n",q->data);
    free(q);
    return head;
}

void display(struct node* head)
{
    struct node * p= head;
    while(p->link!=head)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("%d\n",p->data);
    return;
}


void main()
{
    int c;
    struct node *head=cn();
    head->link=head;
    dp();
    while(1)
    {
        printf("Your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                head=addb(head);
                break;
            case 2:
                head=adde(head);
                break;
            case 3:
                head=addm(head);
                break;
            case 4:
                head=delb(head);
                break;
            case 5:
                head=dele(head);
                break;
            case 6:
                head=delm(head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                dp();
                break;
            case 9:
                return;
            default:
                printf("Wrong choice!\n");
                dp();
                break;
        }
    }
    
}