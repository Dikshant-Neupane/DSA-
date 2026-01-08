#include <stdio.h>
#define MAX 5

int queue[MAX][2]; // queue[i][0] = value, queue[i][1] = priority
int front = -1, rear = -1;

// Enqueue
void enqueue(int value, int priority) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear][0] = value;
    queue[rear][1] = priority;
    printf("%d inserted into queue with priority %d\n", value, priority);
}

// Dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }

    // Find the index of the highest priority element
    int highest = front;
    for (int i = front + 1; i <= rear; i++) {
        if (queue[i][1] > queue[highest][1]) { // higher number = higher priority
            highest = i;
        }
    }

    printf("%d removed from queue (priority %d)\n", queue[highest][0], queue[highest][1]);

    // Shift elements to fill the gap
    for (int i = highest; i < rear; i++) {
        queue[i][0] = queue[i + 1][0];
        queue[i][1] = queue[i + 1][1];
    }

    rear--;
    if (rear < front) {
        front = rear = -1;
    }
}

// Display
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements with priorities: ");
    for (int i = front; i <= rear; i++) {
        printf("(%d, %d) ", queue[i][0], queue[i][1]);
    }
    printf("\n");
}

int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);
    enqueue(40, 2);
    display();

    dequeue();
    display();

    enqueue(50, 5);
    display();

    return 0;
}
