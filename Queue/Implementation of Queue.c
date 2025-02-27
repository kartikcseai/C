#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Maximum size of the queue

// Queue structure
typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
   if (isEmpty(q)) {
        q->front = 0; // Initialize front if the queue is empty
    } 
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued %d to the queue.\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        // Reset the queue if it becomes empty after dequeue
        initializeQueue(q);
    }
    printf("Dequeued %d from the queue.\n", value);
    return value;
}

// Function to display the queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    displayQueue(&q);

    enqueue(&q, 60); // Queue is full

    dequeue(&q);
    dequeue(&q);

    displayQueue(&q);
                                                                                                                                                
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    displayQueue(&q); // Queue is empty

    return 0;
}
