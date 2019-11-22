#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct node
{       
	int data;
        struct node* left;
        struct node* right;
};
typedef struct node *NODE;
NODE createNode(int value)
{
        NODE newnode = malloc(sizeof(struct node));
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
}     
NODE insert(NODE root, int data)
{
        if (root == NULL) 
		return createNode(data);
        if (data < root->data)
            	root->left  = insert(root->left, data);
        else if (data > root->data)
            	root->right = insert(root->right, data);   
        return root;
}
void inorder(NODE root)
{
        if(root != NULL)
	{
       		inorder(root->left);
		printf("%d  ", root->data);
        	inorder(root->right);
 	}
}
void main()
{
        NODE root = NULL;
	int item;
	printf("Enter the root\n");
	scanf("%d",&item);
        root = insert(root,item);
	printf("Press (E) to end tree insertion:\n");
	while(1)
	{
		printf("Enter the root:\n");
		if( scanf("%d",&item) != 1)
        		break;
		insert(root,item);
	}
	printf("Inorder(ascending):  ");
	inorder(root);
}
