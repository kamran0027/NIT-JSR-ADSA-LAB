#include<stdio.h>
// implement circular queue using array
int front = -1, rear = -1, size = 5;
int queue[5];
void enqueue(int value)
{
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
    {
        printf("Queue is full\n");
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
        queue[rear] = value;
    }
    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = value;
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    int data = queue[front];
    queue[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;
    printf("Deleted element is %d\n", data);
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;

}

