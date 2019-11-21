#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{ 
	int coef;
	int power;
	struct node *link;
};
struct node *temp,*start=NULL,*ptr,*curptr;
void display()
{
	if (start == NULL)
		printf(" Empty List");
	else
	{
		ptr = start;
		while (ptr != NULL)
		{
			printf("%dx^%d\t",ptr->coef,ptr->power);
			ptr = ptr->link;
		}
	}
}	
void insert_node()
{	
	int ch;
	do
	{	
		temp = (struct node*) malloc(sizeof(struct node));
		printf("Enter the coefficient and power\n");
		scanf("%d%d",&temp->coef,&temp->power);
		temp->link=NULL;
		if(start == NULL)
			start = temp;
		else if (temp->power > start->power)
		{
			temp->link = start;
			start = temp;
		}
		else
		{
			ptr = start;
			while ((ptr !=NULL) && (temp->power < ptr->power))
			{	
				curptr = ptr;
				ptr = ptr->link;
			}
			if (ptr == NULL)
				curptr->link = temp;
			else
			{
				temp->link = curptr->link;		
				curptr->link = temp;
			}
		}
 		printf("Do you want to continue:\n1 for YES\n0 for NO\n");
		scanf("%d",&ch);
	}while(ch!=0);
}
int evaluate()
{	
	double x,result=0.0;
	ptr = start;
	printf("\nEnter the value of x\n");
	scanf("%lf",&x);
	while (ptr !=NULL)
	{
		result += ptr->coef * pow(x,ptr->power);
		ptr = ptr->link;
	}
	printf("The result of the expression = %lf", result);
}
void main()
{
	insert_node();
	display();
	evaluate();
}
