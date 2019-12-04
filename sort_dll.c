#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *Forw;
    struct node *Back;
};
typedef struct node NODE;
NODE *newnode, *start=NULL, *currptr;
NODE *getnode(int value)
{
    	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=value;
	newnode->Forw =NULL;
	newnode->Back =NULL;
	return newnode;	
}
void SortInsert(int value)
{
	newnode=getnode(value);
	if(start==NULL)
	{
		start=newnode;
		start->Forw=NULL;
		start->Back=NULL;
		printf("NODE INSERTED\n");
	}
	else
	{
		currptr=start;
		while(currptr!=NULL)
		{
            		if(currptr->Back==NULL && value < currptr->data)
			{
				newnode->Forw=currptr;
				newnode->Back=NULL;
                		currptr->Back=newnode;
                		start=newnode;
				printf("NODE INSERTED\n");
				return;
			}
			else if(currptr->Forw==NULL && value >= currptr->data)
			{
				currptr->Forw=newnode;
				newnode->Back=currptr;
				newnode->Forw=NULL;
				printf("NODE INSERTED\n");
				return;
			}
			else if(value >= currptr->data && value <= (currptr->Forw)->data)
			{
				(currptr->Forw)->Back=newnode;
				newnode->Forw=currptr->Forw;
				newnode->Back=currptr;
				currptr->Forw=newnode;
				printf("NODE INSERTED\n");
				return;
			}
			currptr=currptr->Forw;
		}
	}
}
void display()
{
    if(start==NULL)
        printf("List Empty, No nodes to display\n");
    else
    {
        printf("\nThe elements in the list are:");
        for(currptr=start;currptr!=NULL;currptr=currptr->Forw)
            printf("%d ", currptr->data);
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\nSorted Doubly ->linked list\n");
        printf("1:Insert \n");
        printf("2:Display the list\n");
        printf("3:Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter an element");
		    int a;
		    scanf("%d",&a);
		    SortInsert(a); 
                    break;
            case 2: display(); 
                    break;
            case 3: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
