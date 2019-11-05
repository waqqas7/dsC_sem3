#include<stdio.h>
#include<math.h>
void main()
{
	int i,j,m,t=0;
	float n=0.0;
	printf("Enter the number of rows or columns");
	scanf("%d",&m);
	int A[m][m];
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("Enter the element");
			scanf("%d",&A[i][j]);
			if(i==j)
				t=t+A[i][j];
			n=n+pow(A[i][j],2);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
	printf("Trace = %d\nNormal = %f",t,sqrt(n));
}
