#include<stdio.h>
void main()
{
	int m,n,i,j;
	printf("Enter the number of rows and columns");
	scanf("%d%d",&n,&m);
	int A[n][m],B[m][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("Enter the element");
			scanf("%d",&A[i][j]);
			B[j][i]=A[i][j];
		}
	}
	printf("Original Matrix :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
	printf("Transpose Matrix :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",B[i][j]);
		printf("\n");
	}
}
