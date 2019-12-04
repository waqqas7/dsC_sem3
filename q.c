#include <stdio.h>
#include<stdlib.h>
#define MAX 10
int queue_array[MAX],rear = - 1,front = -1;
void insert()
{
    int add_item;
    if (rear == MAX - 1)
      printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
          front = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        queue_array[++rear] = add_item;
    }
}
void delete()
{
    if (front == - 1 || front > rear)
        printf("Queue Underflow \n");
    else
        printf("Element deleted from queue is : %d\n", queue_array[front++]);
} 
void display()
{
    if (front == - 1 || front > rear)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is : \n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
void main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Wrong choice \n");
        }
    } 
}
