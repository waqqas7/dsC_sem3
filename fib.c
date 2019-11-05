#include<stdio.h>
void fib(int x,int y,int z)
{
	int a,b,sum;
	a=x;
	b=y;
	sum=a+b;
	printf("%d ",sum);
	while(z>1)
	{
		fib(b,sum,(z-1));
		break;
	}
}
void main()
{
	int n;
	printf("Enter a number");
	scanf("%d",&n);
	if(n==1)
		printf("0");
	else if(n==2)
		printf("0 1");
	else
	{
		printf("0 1 ");
		fib(0,1,(n-2));
	}
}
