#include<stdio.h>
void main()
{
	int a,b,i,j,c=0;
	printf("Enter two numbers as range");
	scanf("%d%d",&a,&b);
	for(i=a; i<=b; i++)
	{
		for(j=1; j<=i; j++)
		{
			if(i%j == 0)
				c++;
		}
		if(c==2)
			printf("%d ",i);
		c=0;
	}

}
