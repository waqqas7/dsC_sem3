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
    if(newnode==NULL)
        printf("Memory was not allocated\n");
    else
    {
		newnode->data=value;
		newnode->Forw =NULL;
		newnode->Back =NULL;
		return newnode;	
    }
}
void insert_beg()
{
	int value;
	printf("Enter the value for the node:\n");
	scanf("%d", &value);
	newnode=getnode(value);
	if(start==NULL)
	{
		start=newnode;
		start->Forw=NULL;
		start->Back=NULL;
	}
	else
	{
		newnode->Forw=start;
		newnode->Back=NULL;
        	start->Back=newnode;
		start=newnode;
	}
	printf("NODE INSERTED\n");
}
void insert_end()
{
	int value;
	printf("Enter the value for the node:\n");
	scanf("%d", &value);
	newnode=getnode(value);
	if(start==NULL)
	{
		start=newnode;
		start->Forw=NULL;
		start->Back=NULL;
	}
	else
	{	
        	currptr=start;
		while(currptr->Forw!=NULL)
			currptr=currptr->Forw;
		currptr->Forw=newnode;
		newnode->Back=currptr;
		newnode->Forw=NULL;
	}
	printf("NODE INSERTED\n");
}
void insert_atposition()
{
	int value,pos,count=0,i;
	printf("Enter the position for the node:\n");
	scanf("%d", &pos);
	currptr=start;
	while(currptr!=NULL)
	{
		currptr=currptr->Forw;
		count++;
	}
	if(pos==1)
		insert_beg();
	else if(pos>1 && pos<=count)
	{
		currptr=start;	
		printf("Enter the value for the node:\n");
		scanf("%d", &value);
		newnode=getnode(value);
		for(i=1;i<pos-1;i++)
			currptr=currptr->Forw;
		(currptr->Forw)->Back=newnode;
		newnode->Forw=currptr->Forw;
		newnode->Back=currptr;
		currptr->Forw=newnode;	
        	printf("NODE  INSERTED\n");
    	}
    	else
       	 	printf("Position out of range\n");
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
void display_Reverse()
{
    if(start==NULL)
        printf("List Empty, No nodes to display\n");
    else    
    {	
        currptr=start;
        while(currptr->Forw!=NULL)
            currptr=currptr->Forw;
        printf("\nThe elements in the list are:");
        while(currptr!=NULL)
        {	
            printf("%d ", currptr->data);
            currptr=currptr->Back;
        }
    }
}
void delete_firstnode()
{
    if(start==NULL)
        printf("List Empty, No nodes to delete\n");
    else if(start->Forw==NULL)
    {
        currptr=start;
        start=NULL;
	printf("The deleted element is %d\n",currptr->data);
	free(currptr);
    }
    else
    {
        currptr=start;
        start=start->Forw;
	start->Back=NULL;
        printf("The deleted element is %d\n",currptr->data);
        free(currptr);
    }
}
void delete_lastnode()
{
	if(start==NULL)
        	printf("List Empty, No nodes to delete\n");
    	else if(start->Forw==NULL)
    	{
        	currptr=start;
        	start=NULL;
        	printf("The deleted element is %d\n",currptr->data);
        	free(currptr);
     	}
    	else
    	{
        	currptr=start;
        	while(currptr->Forw!=NULL)
            	currptr=currptr->Forw;
        	(currptr->Back)->Forw=NULL;
        	printf("The deleted element is %d\n",currptr->data);
        	free(currptr);
    	}
}
void delete_givenPosition()
{ 	
    int i,pos,count=0;
    if(start==NULL)
	printf("List Empty, No nodes to delete\n");
    else
    {
        printf("Enter the position for the node:\n");
        scanf("%d", &pos);
        currptr=start;
        while(currptr!=NULL)
        {
            currptr=currptr->Forw;
            count++;
        }
        if(pos==1)
            delete_firstnode();
        else if(pos>1 && pos<count)
        {	
            currptr=start;
            for(i=1;i<pos;i++)
                currptr=currptr->Forw;
	    (currptr->Back)->Forw=currptr->Forw;
            (currptr->Forw)->Back=currptr->Back;
            printf("The deleted element is %d\n",currptr->data);
            free(currptr);
        }
        else if(pos==count)
            delete_lastnode();
        else
            printf("Position out of range\n");
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\nOperations on Doubly ->linked list\n");
        printf("1:Insert at Begining\n");
        printf("2:Insert at End\n");
        printf("3:Insert at Given Position\n");
        printf("4:Delete first node\n");
        printf("5:Delete Last node\n");
        printf("6:Delete node given its position\n");
        printf("7:Display the list\n");
        printf("8:Reverese Display the list\n");
        printf("9:Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insert_beg(); 
                    break;
            case 2: insert_end(); 
                    break;
            case 3: insert_atposition(); 
                    break;
            case 4: delete_firstnode(); 
                    break;
            case 5: delete_lastnode(); 
                    break;
            case 6: delete_givenPosition(); 
                    break;
            case 7: display(); 
                    break;
            case 8: display_Reverse(); 
                    break;
            case 9: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
