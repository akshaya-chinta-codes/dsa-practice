#include<stdio.h>
#include<stdlib.h>
#define size 6
int Q[size];
int front=-1, rear=-1;
void enQueue(int x)

{
    if(rear==size-1)
    {
        printf("Queue is full\n"); return;
    }
    Q[++rear]=x;
    if(front==-1)
        front=0;
}
void deQueue()
{
    if(front==-1)
    {
        printf("Queue is empty\n"); return;
    }
    printf("Deleted element is %d\n", Q[front]);
    if(front==rear)
        front=rear=-1;
    else
        front++;
}
void display()
{
    if(front==-1)
    {
        printf("Queue is empty\n"); return;
    }
    printf("Queue elements are: ");
    for(int i=front; i<=rear; i++)
        printf("%d\t ", Q[i]);
}
int main()
{
    int choice, x;
    while(1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the element to be enqueued: ");
                    scanf("%d", &x);
                    enQueue(x); break;
            case 2: deQueue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}