#include<stdio.h>
#include<stdlib.h>
int store[50],i=1;
struct node
{
  	int data;
  	struct node *lchild;
  	struct node *rchild;
};
struct node *root=NULL;
int is_lchild(struct node *tree)
{
  	int ch;
  	printf("Do you want to create lchild of %d\nEnter 1 for YES and 0 for NO\n", tree->data);
  	scanf("%d",&ch);
  	if (ch==1)
  		return(1);
  	else
  		return(0);
}
int is_rchild(struct node *tree)
{
  	int ch;
  	printf("Do you want to create rchild of %d\nEnter 1 for YES and 0 for NO\n", tree->data);
  	scanf("%d",&ch);
  	if (ch==1)
  		return(1);
  	else
  		return(0);
}
void create(struct node *tree)
{
  	struct node *temp;
  	if (is_lchild(tree))
  	{
    		tree->lchild = (struct node*) malloc (sizeof(struct node));
    		temp = tree ->lchild;
		printf("Enter the data\n");
    		scanf("%d",&temp->data);
    		create(temp);
  	}
  	else
    		tree->lchild=NULL;
  	if (is_rchild(tree))
  	{
    		tree->rchild = (struct node*) malloc (sizeof(struct node));
    		temp = tree->rchild;
    		printf("Enter the data\n");
    		scanf("%d",&temp->data);
		create(temp);
  	}
  	else
    		tree->rchild=NULL;
}
void inorderStore(struct node *tree)
{
  	if(tree!=NULL)
  	{
    		inorderStore(tree->lchild);
    		store[i++]=tree->data;
    		inorderStore(tree->rchild);
  	}
}
void createSum(struct node *tree)
{
  	if(tree!=NULL)
  	{
    		createSum(tree->lchild);
    		tree->data=store[i-1]+store[i+1];
            	i++;
    		createSum(tree->rchild);
  	}
}
void inorder(struct node *tree)
{
  	if(tree!=NULL)
  	{
    		inorder(tree->lchild);
    		printf("%d ",tree->data);
    		inorder(tree->rchild);
  	}
}
void main()
{
  	printf("Create the root node\n");
  	root=(struct node*) malloc (sizeof(struct node));
  	printf("Enter the data\n");
  	scanf("%d",&root->data);
  	create(root);
  	printf("\nThe inorder traversal is before replacement: ");
  	inorder(root);
    	inorderStore(root);
    	i=1;
    	createSum(root);
    	printf("\nThe inorder traversal is after replacement: ");
  	inorder(root);
}

