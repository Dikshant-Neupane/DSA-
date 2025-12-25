// Deque Data Structure
#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

int size() {
    return isEmpty() ? 0 : rear - front + 1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1) {
        front = 0; // first insertion initializes front
    }

    rear++;
    queue[rear] = value;
    printf("%d inserted into queue\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty\n");
        front = rear = -1; // keep indices consistent when empty
        return;
    }

    printf("%d removed from queue\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1; // reset when queue becomes empty
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void printMiddle() {
    int n = size();
    if (n == 0) {
        printf("Queue is empty. No middle element.\n");
        return;
    }

    // Choose the lower middle when even number of elements
    int midIndex = front + (n - 1) / 2;
    printf("Middle element: %d\n", queue[midIndex]);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    printMiddle();

    dequeue();
    dequeue();
    display();
    printMiddle();

    return 0;
}