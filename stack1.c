#include<stdio.h>
#define max 5
int k;
struct stacks
{
	int top;
	int stck[max];
}s[2];
int isfull()
{
	if(s[k].top>=(max-1))
		return 1;
	return 0;
}
int isempty()
{
	if(s[k].top<0)
		return 1;
	return 0;
}
void push(int item)
{
		s[k].stck[++s[k].top]=item;
}
void pop()
{
	if(isempty())
		printf("Stack underflow\n");
	else
		printf("The element deleted is %d\n",s[k].stck[s[k].top--]);
}
void display()
{
	if(s[k].top<0)
		printf("No elements to display\n");
	else
	{
		int i;
		for(i=s[k].top; i>=0; i--)
			printf("%d\n",s[k].stck[i]);
	}
}
void stacktop()
{
	if(isempty())
		printf("No top element to display\n");
	else
		printf("%d\n",s[k].stck[s[k].top]);
}
void main()
{
	for(int j=0;j<2;j++)
	{
		k=j;
		printf("Operations for stack number %d\n",j+1);
		int ch;
   		s[j].top=-1;
		do
		{	
			printf("Press 1 to push\nPress 2 to pop\nPress 3 to display\nPress 4 for top element\nPress 5 to exit");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: if(isfull())
						printf("Stack overflow\n");
					else
					{
						printf("Enter an element\n");
						int a;
						scanf("%d",&a);
						push(a);
					}
					break;
				case 2: pop();
					break;
				case 3: display();
					break;
				case 4: stacktop();
					break;
				case 5: break;
				default: printf("Incorrect choice\n");
			}
		}while(ch!=5);
	}
}
