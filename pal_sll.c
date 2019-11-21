#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
int count=0;
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
	count++;
	printf("NODE INSERTED\n");
}
void palin_check()
{
	if(start==NULL)
		printf("List Empty\n");
	else
	{
		int i=0,j;
    		while (i!=count/2)
    		{
       			currptr=prevptr=start;
        		for (j=0;j<i;j++)
            			currptr=currptr->link;
			for(j=0;j<count-(i+1);j++)
				prevptr=prevptr->link;
			if (currptr->data != prevptr->data)
			{
				printf("It is not a palindromic list\n");
				return;
			}
			else
	    			i++;
		}
    		printf("It is a palindromic list\n");
	}
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
		printf("\nPalindromic singly->linked list\n");
		printf("1:Insert a node\n");
		printf("2:Check for palindromic condition\n");
		printf("3:Display the list\n");
		printf("4:Exit\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert(); break;
			case 2: palin_check(); break;
			case 3: display(); break;
                	case 4: exit(0);
			default: printf("Invalid Choice\n");
		}
	}
}




