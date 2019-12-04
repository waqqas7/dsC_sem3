#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
typedef struct node NODE;
NODE *newnode,*start=NULL,*currptr,*prevptr;
NODE *getnode(int value)
{
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=value;
	newnode->link =NULL;
	return newnode;	
}
void insert_beg()
{
	int value;
	printf("Enter the value for the node:\n");
	scanf("%d",&value);
	newnode=getnode(value);
	currptr=start;
	start=newnode;
	start->link=currptr;
	printf("NODE INSERTED\n");
}
void display()
{
	if(start==NULL)
		printf("List Empty, No nodes to display\n");
	else
	{
		printf("The elements in the list are: ");
		for(currptr=start;currptr!=NULL;currptr=currptr->link)
			printf("%d   ", currptr->data);
	}
}
void delete_secondNode()
{
	if(start!=NULL)
	{	
		if(start->link!=NULL)
		{
			currptr=start;
			prevptr=currptr;
			currptr=currptr->link;
			prevptr->link=currptr->link;
			printf("The deleted element is %d\n",currptr->data);
			free(currptr);
			return;
		}
	}
	printf("No node at second position to delete\n");
}
void main()
{
	int ch;
	while(1)
	{
		printf("\nDelete Second Node - singly->linked list\n");
		printf("1:Insert at Begining\n");
		printf("2:Delete second node\n");
		printf("3:Display the list\n");
		printf("4:Exit\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert_beg(); break;
			case 2: delete_secondNode(); break;
			case 3: display(); break;
                	case 4: exit(0);
			default: printf("Invalid Choice\n");
		}
	}
}

