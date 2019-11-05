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
	if(newnode==NULL)
		printf("Memory was not allocated\n");
	else
	{
		newnode->data=value;
		newnode->link =NULL;
		return newnode;	
	}
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
void insert_end()
{
	int value;
	printf("Enter the value for the node:\n");
	scanf("%d",&value);
	newnode=getnode(value);
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
void insert_atposition()
{
	int value,pos,count=0,i;
	if(start!=NULL)
	{
		printf("Enter the position for the node:\n");
		scanf("%d",&pos);
		currptr=start;
		while(currptr!=NULL)
		{
			currptr=currptr->link;
			count++;
		}
		if(pos==1)
			insert_beg();
		else if(pos>1 && pos<=(count+1))
		{
			currptr=start;	
			printf("Enter the value for the node:\n");
			scanf("%d", &value);
			newnode=getnode(value);
			for(i=1;i<pos-1;i++)
				currptr=currptr->link;
			newnode->link=currptr->link;
			currptr->link=newnode;	
			printf("NODE INSERTED\n");
		}
		else
			printf("Position out of range\n");
	}
	else
		printf("List empty\n");
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
void delete_firstnode()
{
	if(start==NULL)
		printf("List Empty, No nodes to delete\n");
	else
	{
		currptr=start;
		start=start->link;
		printf("The deleted element is %d\n",currptr->data);
		free(currptr);
	}
}
void delete_lastnode()
{
	if(start==NULL)
		printf("List Empty, No nodes to delete\n");
	else if(start->link==NULL)
	{
		currptr=start;
		start=NULL;
		printf("The deleted element is %d\n",currptr->data);
		free(currptr);
	}
	else
	{
		currptr=start;
		prevptr=NULL;
		while(currptr->link!=NULL)
		{
			prevptr=currptr;
			currptr=currptr->link;
		}
		prevptr->link=NULL;
		printf("The deleted element is %d\n",currptr->data);
		free(currptr);
	}
}
void delete_givenPosition()
{
       	int i,pos;
	if(start!=NULL)
	{	
		printf("Enter the position for the node:\n");
		scanf("%d",&pos);
		if(pos==1)
			delete_firstnode();
		else
		{	
			currptr=start;
			for(i=1;i<pos;i++)
			{
				prevptr=currptr;
				currptr=currptr->link;
			}
			prevptr->link=currptr->link;
			printf("The deleted element is %d\n",currptr->data);
			free(currptr);
		}
	}
	else
		printf("List Empty, No nodes to delete\n");
}
void main()
{
	int ch;
	while(1)
	{
		printf("\nOperations on singly->linked list\n");
		printf("1:Insert at Begining\n");
		printf("2:Insert at End\n");
		printf("3:Insert at Given Position\n");
		printf("4:Delete first node\n");
		printf("5:Delete Last node\n");
		printf("6:Delete node given its position\n");
		printf("7:Display the list\n");
		printf("8:Exit\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert_beg(); break;
			case 2: insert_end(); break;
			case 3: insert_atposition(); break;
			case 4: delete_firstnode(); break;
			case 5: delete_lastnode(); break;
			case 6: delete_givenPosition(); break;
			case 7: display(); break;
                	case 8: exit(0);
			default: printf("Invalid Choice\n");
		}
	}
}
