#include<stdio.h>
#include<stdlib.h>
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
void inorder(struct node *tree)
{
  	if(tree!=NULL)
  	{
    		inorder(tree->lchild);
    		printf("%d\t",tree->data);
    		inorder(tree->rchild);
  	}
}
void preorder(struct node *tree)
{
  	if(tree!=NULL)
  	{
    		printf("%d\t",tree->data);
		preorder(tree->lchild);
    		preorder(tree->rchild);
  	}
}
void postorder(struct node *tree)
{
  	if(tree!=NULL)
  	{
		postorder(tree->lchild);
    		postorder(tree->rchild);
		printf("%d\t",tree->data);
	}
} 
void main()
{
  	printf("Create the root node\n");
  	root=(struct node*) malloc (sizeof(struct node));
  	printf("Enter the data\n");
  	scanf("%d",&root->data);
  	create(root);
  	printf("\nThe inorder traversal is: ");
  	inorder(root);
	printf("\nThe preorder traversal is: ");
  	preorder(root);
	printf("\nThe postorder traversal is: ");
  	postorder(root);
}
