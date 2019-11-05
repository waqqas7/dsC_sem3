#include<stdio.h>
#include<ctype.h>
#define MAX 100
typedef struct stacks
{
	int data[MAX];
	int top;
}stack;
int priority (char);
void init (stack *);
int empty(stack *);
int full(stack *);
char pop(stack *);
void push(stack *,char);
char top(stack *);
void main()
{
	stack s;
	char x;
	char token;
	init(&s); 
	printf("Enter infix expression\n");
	while((token=getchar())!='\n')
	{
		if(isalpha(token))
			printf("%c",token);
		else
		{
			if(token=='(')
				push(&s,'(');
			else
			{
				if(token==')')
				{
					while((x=pop(&s))!='(')
					{
						printf("%c",x);
					}
				}
				else
				{
					while(priority(token)<=priority(top(&s)) && !empty(&s))
					{
						x=pop(&s);
						printf("%c",x);
					}
					push(&s,token);
				}	
			}
		}
	}
	while(!empty(&s))
	{
		x=pop(&s);
		printf("%c",x);
	}
}
int priority(char x)
{
	if(x=='(')
		return 0;
	if(x=='+' || x=='-')
		return 1;
	if(x=='*' || x=='/' || x=='%')
		return 2;
	return 3;
}
void init(stack *s)
{
	s->top=-1;
}
int empty(stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
int full(stack *s)
{
	if(s->top==(MAX-1))
		return 1;
	else
		return 0;
}
void push(stack *s, char x)
{
	s->top=s->top+1;
	s->data[s->top]=x;
}
char pop(stack *s)
{
	char x;
	x=s->data[s->top];
	s->top=s->top-1;
	return x;
}
char top(stack *s)
{
	return (s->data[s->top]); 
}
