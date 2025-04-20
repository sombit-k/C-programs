#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* lc;
    int data;
    struct node* rc;
};

struct node* init()
{
    return (struct node*)malloc(sizeof(struct node));
}

struct node* cn(struct node* n,int d)
{
    n->data=d;
    n->lc=NULL;
    n->rc=NULL;
    return n;
}

void insertnode(struct node* root,struct node* q)
{
    printf("\nThe node being used is = %d and lc = %s ,,,, rc = %s",root->data,root->lc,root->rc);
    int d=q->data;
    if(d>root->data && root->rc==NULL)
    {
        root->rc=q;
        return;
    }
    else if(d<=root->data && root->lc==NULL)
    {
        root->lc=q;
        return;
    }
    else if(d>root->data)
    {
        insertnode(root->rc,q);
    }
    else if(d<=root->data)
    {
        insertnode(root->lc,q);
    }
}

void deletenode(struct node* root, int d)
{
    struct node*p=init();
    struct node*q=init();
    struct node*r=init();
    p=root->lc;
    q=root->rc;

    if(d<=root->data && (p!=NULL))
    {
        if(p->data==d)
        {
            if(p->lc==NULL && p->rc==NULL)
            {
                root->lc==NULL;
            }
            else if(p->lc)
            {
                r=(p->lc)->rc;
                //traverse left and find the biggest
                if(r==NULL)
                {
                    //replace p with p->lc
                }
                else
                {    
                    while(r->rc!=NULL)
                    {
                        r=r->rc;
                    }
                    //"r->rc" contains the largest node of the left subtree
                }
            }
            else
            {
                //traverse right tree and find smallest
            }
        }
        else
        {
            deletenode(p,d);
        }
    }
    else if(d>root->data && q!=NULL)
    {
        if(q->data==d)
        {
            if(q->lc==NULL && q->rc==NULL)
            {
                root->rc==NULL;
            }
            else if(q->lc)
            {
                //traverse left and find the largest node
            }
            else
            {
                //travers the right and find the smallest node
            }
        }
        else
        {
            deletenode(q,d);
        }
    }
    else
    {
        printf("\nData not found!\n");
    }
}

void display(struct node* root)
{
    if(root!=NULL)
    {
        display(root->lc);
        printf(" %d ",root->data);
        display(root->rc);
    }
}


void main()
{
    int d,i,v;
    printf("Enter the value of the root: ");
    scanf("%d",&d);
    struct node* root=init();
    root=cn(root,d);
    while(1)
    {
        printf("\n1)Insertnode 2)Deletenode 3)Display 4)Exit :");
        scanf("%d",&d);
        switch(d)
        {
            c=0;
            case 1: printf("Enter the data to be inserted: ");
                    scanf("%d",&v);
                    struct node*q=init();
                    q=cn(q,v);
                    insertnode(root,q);
                    break;
            case 2: printf("\nEnter the node to be deleted: ");
                    scanf("%d",&v);
                    deletenode(root,v);
                    break;
            case 3:
                    printf("\nThe BST in inorder traversal is:  ");
                    display(root);
                    break;
            case 4:return;
        }
    }
}