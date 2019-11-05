#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define size 50
int s[size],top=-1;
void push(int item)
{
	s[++top]=item;
}
int pop()
{
	return s[top--];
}
void main()
{
	char posfix[50],ch;
	int i=0,op1,op2;
	printf("Enter the postfix expression\n");
	scanf("%s",posfix);
	while((ch=posfix[i++])!='\0')
	{
		if(isdigit(ch))
			push(ch-'0');
		else
		{
			op2=pop();
			op1=pop();
			switch(ch)
			{
				case '+':push(op1+op2);
					 break;
				case '-':push(op1-op2);
					 break;
				case '*':push(op1*op2);
					 break;
				case '/':push(op1/op2);
					 break;
				case '^':push(pow(op1,op2));
					 break;
			}

		}
	}
	printf("Postfix expression : %s\n",posfix);
	printf("Result : %d",s[top]);
}
