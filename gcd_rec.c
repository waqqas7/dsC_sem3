#include<stdio.h>
void gcd(int m,int n)
{
	while(m!=n)
	{
		if(m>n)
		{
			gcd(m-n,n);
			return;
		}
		else
		{
			gcd(m,n-m);
			return;
		}
	}
	printf("GCD = %d",m);
}
void main()
{
	int x,y;
	printf("Enter two numbers");
	scanf("%d%d",&x,&y);
	gcd(x,y);
}
