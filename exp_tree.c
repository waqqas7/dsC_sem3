#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node
{
	char info;
	struct node *left;
	struct node *right;
};
typedef struct node *NODE;
struct stack
{
	int top;
	NODE arr[50];
};
void push(struct stack *s, NODE ele)
{
    	if(s->top==49)
        	printf("Stack Overflow\n");
	else
        	s->arr[++(s->top)]=ele;
}
NODE pop(struct stack *s)
{
    	if(s->top==-1)
        	printf("Stack Underflow\n");
	else
		return s->arr[(s->top)--];
}
void inorder(NODE tree)
{
    	if(tree!=NULL)
    	{
    		inorder(tree->left);
    		printf("%c\t",tree->info);
    		inorder(tree->right);
    	}
}
NODE createtree(char postfix[])
{
    	NODE tree,temp,lc,rc;
    	char ch;
    	int i;
    	struct stack s;
    	s.top=-1;
    	for(i=0; i<strlen(postfix); i++)
    	{
        	ch=postfix[i];
		temp=(NODE)malloc(sizeof(NODE));
     		temp->info=ch;
        	temp->left=NULL;
        	temp->right=NULL;
        	if(isdigit(postfix[i]))
            		push(&s,temp);
        	else
        	{
           		rc=pop(&s);
           		lc=pop(&s);
           		temp->right=rc;
           		temp->left=lc;
           		push(&s,temp);
        	}
    	}
    	tree=pop(&s);
    	return tree;
}
float evaluate(NODE tree)
{
    	switch(tree->info)
    	{
    		case '+':return ( evaluate(tree->left) + evaluate(tree->right) );
    		case '-':return ( evaluate(tree->left) - evaluate(tree->right) );
    		case '*':return ( evaluate(tree->left) * evaluate(tree->right) );
    		case '/':return ( evaluate(tree->left) / evaluate(tree->right) );
    		case '^':return ( pow(evaluate(tree->left),evaluate(tree->right)) );
    		default: return ( (tree->info)-'0' );
    	}
}
void main()
{
    	char postfix[20];
    	NODE tree; 
    	printf("Enter postfix expression :\n");
    	scanf("%s",postfix);
    	tree=createtree(postfix);
    	printf("\nResult = %f\n",evaluate(tree));
	printf("Infix Expression : ");
	inorder(tree);
}
