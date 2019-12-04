#include<stdio.h>         
#include<stdlib.h>        
#define max 5        
int cq[max],f=-1,r=-1;;          
void insert()
{
    int item;
    if( (f==0 && r==max-1) || f==r+1)
    {
        printf("OVERFLOW\n");
        return;
    }
    printf("\nEnter a element:");
    scanf("%d",&item);
    if(f==-1)
        f=0;
    if(r==max-1)
        r=0;
    else 
        r++;
    cq[r]=item;
}
void delete()
{
    if(f==-1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    int e=cq[f];
    if(f==max-1)
        f=0;
    else if(f==r)
        f=r=-1;
    else
        f++;
    printf("Deleted element : %d\n",e);
}
void display()
{
    if(f==-1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    int i;
    if(f<=r)
    {
        for(i=f;i<=r;i++)
            printf("%d ",cq[i]);
        printf("\n");
    }
    else
    {
        for(i=f;i<max;i++)
            printf("%d ",cq[i]);
        for(i=0;i<=r;i++)
            printf("%d ",cq[i]);
        printf("\n");
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. EXIT");
        printf("\nEnter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
        	case 1: insert();
            		break;
        	case 2:	delete();
            		break;
        	case 3:	display();
            		break;
        	case 4:	exit(0);
        	default:printf("Invalid Choice\n");
        }
    }
}




