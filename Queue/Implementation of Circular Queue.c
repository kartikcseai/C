#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Define the maximum size of the queue

// Structure to represent a Circular Queue
struct CircularQueue {
    int items[SIZE];
    int front, rear;
};

// Function to initialize the queue
void initQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    return (q->front == -1);
}

// Function to check if the queue is full
int isFull(struct CircularQueue* q) {
    return ((q->rear + 1) % SIZE == q->front);
}

// Function to insert an element (Enqueue)
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot insert %d.\n", value);
        return;
    }
    if (isEmpty(q)) { // First element
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
    printf("Inserted %d\n", value);
}

// Function to delete an element (Dequeue)
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int data = q->items[q->front];
    if (q->front == q->rear) { // Only one element was present
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    printf("Deleted %d\n", data);
    return data;
}

// Function to get the front element
int peek(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No front element.\n");
        return -1;
    }
    return q->items[q->front];
}

// Function to display the queue elements
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function to test the Circular Queue
int main() {
    struct CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50); // Queue should be full now

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 60);
    enqueue(&q, 70); // Circular insertion

    display(&q);

    printf("Front element: %d\n", peek(&q));

    return 0;
}
