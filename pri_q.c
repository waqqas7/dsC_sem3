#include<stdio.h>
#include<stdlib.h>
#define max 5
int pq[max],f=-1,r=-1;
void check(int data)
{
	int i,j;
	for(i=f;i<=r;i++)
	{
		if(data <= pq[i])
		{
			for(j=r+1;j>i;j--)
				pq[j]=pq[j-1];
			pq[i]=data;
			return;
		}
	}
	pq[i]=data;
}
void insert()
{
	if(r==(max-1))
	{
		printf("OVERFLOW\n");
		return;
	}
	int item;
	printf("Enter an element\n");
	scanf("%d",&item);
	if(f==-1 && r==-1)
	{
		f=r=0;
		pq[r]=item;
	}
	else 
    {
		check(item);
        r++;
    }
}
void delete()
{
	if(f==-1 || f>r)
		printf("UNDERFLOW\n");
	else
		printf("Element deleted is %d\n",pq[f++]);
}
void display()
{
	if(f==-1 || f>r)
		printf("UNDERFLOW\n");
	else
	{
		for(int i=f;i<=r;i++)
			printf("%d ",pq[i]);
	}
}
void main()
{
	int ch;
	while(1)
	{	
		printf("\nPress 1 to insert\nPress 2 to delete\nPress 3 to display\nPress 4 to exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert();
				break;
			case 2: delete();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("Incorrect choice\n");
		}
	}
}

