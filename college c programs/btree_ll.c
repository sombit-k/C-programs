#include<stdio.h>
#include<stdlib.h>
struct node{	
	struct node* left;
	int d;
	struct node* right;
};

struct node* create()
{
	return (struct node*)malloc(sizeof(struct node));
}
struct node* createnode()
{
	struct node* empty=create();
	empty->left=NULL;
	empty->right=NULL;
	return empty;
}
void createlc(struct node* root)//creates left child
{
	int da;
	printf("Enter the left element of left node: ");
	scanf("%d",&da);	
	struct node* nd;
	nd=createnode();
	nd->d=da;
	root->left=nd;
}
void createrc(struct node* root)//creates right child
{
        int da;
        printf("Enter the left element of left node: ");
        scanf("%d",&da);
        struct node* nd;
        nd=createnode();
        nd->d=da;
        root->right=nd;
}

void main()
{
	struct node* root;
	root=create();
	printf("Enter the value of root: ");
	scanf("%d",&(root->d));
	printf("%d %s %s",root->d,root->left,root->right);
}
