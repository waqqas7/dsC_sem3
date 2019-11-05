#include<stdio.h>
void main()
{
	int A[5][3],i,j,max,pos;
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter marks for subject %d for student %d",j+1,i+1);
			scanf("%d",&A[i][j]);
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		max=A[0][i];
		pos=0;
		for(j=0;j<5;j++)
		{
			if(A[j][i]>max)
			{
				max=A[j][i];
				pos=j;
			}
		}
		printf("Highest marks in subject %d is %d secured by student %d\n",i+1,max,pos+1);
	}
}
