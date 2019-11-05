#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
typedef struct node NODE;
NODE *newnode, *last=NULL, *currptr, *prevptr;
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
	if(last==NULL)
	{
		last=newnode;
		last->link=last;
	}
	else
	{
		newnode->link=last->link;
		last->link=newnode;
	}
	printf("NODE INSERTED\n");
}
void insert_end()
{
	insert_beg();
	last=newnode;
}
void insert_atposition()
{
	int value,pos,count=0,i;
	if(last!=NULL)
	{
		printf("Enter the position for the node:\n");
		scanf("%d",&pos);
		currptr=last->link;
		while(currptr!=last)
		{
			currptr=currptr->link;
			count++;
		}
		if(pos==1)
			insert_beg();
		else if(pos>1 && pos<=(count+1))
		{
			currptr=last->link;	
			printf("Enter the value for the node:\n");
			scanf("%d",&value);
			newnode=getnode(value);
			for(i=1;i<pos-1;i++)
				currptr=currptr->link;
			newnode->link=currptr->link;
			currptr->link=newnode;	
			printf("NODE INSERTED\n");
		}
		else if(pos==count+2)
			insert_end();
		else
			printf("Position out of range\n");
	}
	else
		printf("List empty\n");
}
void display()
{
	if(last==NULL)
		printf("List Empty, No nodes to display\n");
	else
	{
		printf("The elements in the list are: ");
		for(currptr=last->link;currptr!=last;currptr=currptr->link)
			printf("%d   ",currptr->data);
		printf("%d",currptr->data);
	}
}
void delete_firstnode()
{
	if(last==NULL)
		printf("List Empty, No nodes to delete\n");
	else if(last->link==last)
	{
		currptr=last;
		last=NULL;
		printf("The deleted element is %d\n",currptr->data);
		free(currptr);
	}
	else
	{
		currptr=last->link;
		last->link=currptr->link;
		printf("The deleted element is %d\n",currptr->data);
		free(currptr);
	}
}
void delete_lastnode()
{
	if(last==NULL)
		printf("List Empty, No nodes to delete\n");
	else if(last->link==last)
	{
		currptr=last;
		last=NULL;
		printf("The deleted element is %d\n",currptr->data);
		free(currptr);
	}
	else
	{
		currptr=last->link;
		prevptr=NULL;
		while(currptr->link!=last->link)
		{
			prevptr=currptr;
			currptr=currptr->link;
		}
		prevptr->link=last->link;
		last=prevptr;
		printf("The deleted element is %d\n",currptr->data);
		free(currptr);
	}
}
void delete_givenPosition()
{ 
	int i,pos,count=0;
	if(last!=NULL)
	{
		printf("Enter the position for the node:\n");
		scanf("%d", &pos);
       		currptr=last->link;
		while(currptr!=last)
		{
			currptr=currptr->link;
			count++;
		}
		if(pos==1)
			delete_firstnode();
		else if(pos>1 && pos<=(count+1))
		{
			currptr=last->link;
			for(i=1;i<pos;i++)
			{
				prevptr=currptr;
				currptr=currptr->link;
			}
			prevptr->link=currptr->link;
			if(currptr==last)
				last=prevptr;
			printf("The deleted element is %d\n",currptr->data);
			free(currptr);
		}
		else
			printf("Position out of range\n");
	}
	else
		printf("List empty, No nodes to delete\n");

}
void main()
{
	int ch;
	while(1)
	{
		printf("\nOperations on Circular linked list");
		printf("\n1:Insert at Begining");
		printf("\n2:Insert at End");
		printf("\n3:Insert at Given Position");
		printf("\n4:Delete first node");
		printf("\n5:Delete Last node");
		printf("\n6:Delete node given its position");
		printf("\n7:Display the list");
		printf("\n8:Exit");
		printf("\nEnter the choice\n");
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
