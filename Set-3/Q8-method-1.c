#include <stdio.h>


#define SIZE 100

// Two static arrays to represent the actual memory
int queueArray1[SIZE], queueArray2[SIZE];

// Two pointers that will point to the current active queues
int *queue1 = queueArray1;
int *queue2 = queueArray2;

int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

// Queue 1 operations
void enqueue1(int x) {
    if (rear1 == SIZE - 1) {
        printf("Queue1 Overflow\n");
        return;
    }
    if (front1 == -1) front1 = 0;
    queue1[++rear1] = x;
}

int dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        return -1;
    }
    return queue1[front1++];
}

// Queue 2 operations
void enqueue_to_q2(int x) {
    if (rear2 == SIZE - 1) {
        printf("Queue2 Overflow\n");
        return;
    }
    if (front2 == -1) front2 = 0;
    queue2[++rear2] = x;
}

int dequeue2() {
    if (front2 == -1 || front2 > rear2) {
        return -1;
    }
    return queue2[front2++];
}

// Swap both queues and their front/rear values
void swapQueues() {
    int *tempQueue = queue1;
    queue1 = queue2;
    queue2 = tempQueue;

    int tempFront = front1;
    front1 = front2;
    front2 = tempFront;

    int tempRear = rear1;
    rear1 = rear2;
    rear2 = tempRear;
}

// Push: Costly operation
void push(int x) {
    enqueue_to_q2(x);

    while (front1 != -1 && front1 <= rear1) {
        enqueue_to_q2(dequeue1());
    }

    // Swap the two queues
    swapQueues();

    // Reset queue2
    front2 = rear2 = -1;

    printf("Pushed: %d\n", x);
}

// Pop: Simple
void pop() {
    if (front1 == -1 || front1 > rear1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Popped: %d\n", dequeue1());
}

// Display Stack
void display() {
    if (front1 == -1 || front1 > rear1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack: ");
    for (int i = front1; i <= rear1; i++) {
        printf("%d ", queue1[i]);
    }
    printf("\n");
}

// Main Function
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
