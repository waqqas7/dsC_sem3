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
void insert()
{
	int value;
	printf("Enter the value for the node:\n");
	scanf("%d",&value);
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=value;
	newnode->link =NULL;
	if(start==NULL)
	{
		start=newnode;
		start->link=NULL;
	}
	else
	{
		currptr=start;
		while(currptr->link!=NULL)
			currptr=currptr->link;
		currptr->link=newnode;
		newnode->link=NULL;
	}
	printf("NODE INSERTED\n");
}
void reverseList()
{
    if(start != NULL)
    {
        prevptr=start;
        currptr=start->link;
        start=start->link;
        prevptr->link = NULL;
        while(start != NULL)
        {
            start=start->link;
            currptr->link=prevptr;
	    prevptr=currptr;
	    currptr=start;
        }
        start=prevptr;
        printf("SUCCESSFULLY REVERSED LIST\n");
    }
    else
	    printf("List Empty\n");
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
void main()
{
	int ch;
	while(1)
	{
		printf("\nReversing a singly->linked list\n");
		printf("1:Insert a node\n");
		printf("2:Reverse the list\n");
		printf("3:Display the list\n");
		printf("4:Exit\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert(); break;
			case 2: reverseList(); break;
			case 3: display(); break;
                	case 4: exit(0);
			default: printf("Invalid Choice\n");
		}
	}
}
