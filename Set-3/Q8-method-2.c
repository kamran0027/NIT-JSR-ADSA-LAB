#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Static memory for the queues
int queueArray1[SIZE], queueArray2[SIZE];

// Use pointers to refer to the actual queues
int *queue1 = queueArray1;
int *queue2 = queueArray2;

int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

// Enqueue in queue1
void enqueue1(int x) {
    if (rear1 == SIZE - 1) return;
    if (front1 == -1) front1 = 0;
    queue1[++rear1] = x;
}

// Dequeue from queue1
int dequeue1() {
    if (front1 == -1 || front1 > rear1) return -1;
    return queue1[front1++];
}

// Enqueue in queue2
void enqueue2(int x) {
    if (rear2 == SIZE - 1) return;
    if (front2 == -1) front2 = 0;
    queue2[++rear2] = x;
}

// Dequeue from queue2
int dequeue2() {
    if (front2 == -1 || front2 > rear2) return -1;
    return queue2[front2++];
}

// Swap the pointers and indices
void swapQueues() {
    // Swap queue pointers
    int *tempQueue = queue1;
    queue1 = queue2;
    queue2 = tempQueue;

    // Swap front and rear
    int tempFront = front1;
    front1 = front2;
    front2 = tempFront;

    int tempRear = rear1;
    rear1 = rear2;
    rear2 = tempRear;
}

// Push: Simple
void push(int x) {
    enqueue1(x);
    printf("Pushed: %d\n", x);
}

// Pop: Costly
void pop() {
    if (front1 == -1 || front1 > rear1) {
        printf("Stack is Empty\n");
        return;
    }

    while (front1 < rear1) {
        enqueue2(dequeue1());
    }

    int popped = dequeue1();
    printf("Popped: %d\n", popped);

    // Reset queue2's front and rear
    front2 = rear2 = -1;

    // Swap the queues
    swapQueues();
}

void display() {
    if (front1 == -1 || front1 > rear1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = front1; i <= rear1; i++)
        printf("%d ", queue1[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    push(40);
    display();

    return 0;
}
