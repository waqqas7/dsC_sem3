#include<stdio.h>
void bs(int low,int high,int key,int A[])
{
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(key==A[mid])
		{
			printf("\nElement found at %d position",mid+1);
			return;
		}
		else if(key>A[mid])
		{
			bs(mid+1,high,key,A);
			return;
		}
		else
		{
			bs(low,mid-1,key,A);
			return;
		}
	}
	printf("\nElement not found");
}
void main()
{
	int i,n,key;
	printf("Enter the number of elements");
	scanf("%d",&n);
	int A[n];
	printf("Enter the elements in ascending order\n");
	for(i=0;i<n;i++)
	{
		printf("Enter an element");
		scanf("%d",&A[i]);
	}
	printf("Enter the element to search");
	scanf("%d",&key);
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	bs(0,n-1,key,A);
}
