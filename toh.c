#include<stdio.h>
void toh(int n,char source,char tmp,char dest)
{
	if(n==1)
		printf("Move Disk from %c to %c\n",source,dest);
	else
	{
		toh(n-1,source,dest,tmp);
		printf("Move Disk from %c to %c\n",source,dest);
		toh(n-1,tmp,source,dest);
	}
}
void main()
{
	int n;
	printf("Enter a number");
	scanf("%d",&n);
	if(n<1)
		printf("Incorrect input");
	else
		toh(n,'A','B','C');
}

