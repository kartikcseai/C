#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the queue structure
typedef struct {
    int arr[MAX_SIZE];
    int front; // Index of the front element
    int rear;  // Index of the rear element
} Queue;

// Function to initialize the queue
void initialize(Queue *queue) {
    queue->front = -1; // Queue is empty initially
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0; // Initialize front if the queue is empty
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE; // Circular increment
    queue->arr[queue->rear] = value;
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue\n");
        return -1; // Return an invalid value to indicate underflow
    }
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        // Queue has only one element, reset front and rear
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE; // Circular increment
    }
    return value;
}

// Function to get the front element of the queue without removing it
int peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Return an invalid value to indicate empty queue
    }
    return queue->arr[queue->front];
}

// Function to display the queue
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE; // Circular increment
    }
    printf("%d\n", queue->arr[i]); // Print the last element
}

int main() {
    Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue); // Output: Queue elements: 10 20 30

    printf("Front element: %d\n", peek(&queue)); // Output: Front element: 10

    printf("Dequeued element: %d\n", dequeue(&queue)); // Output: Dequeued element: 10
    display(&queue); // Output: Queue elements: 20 30

    printf("Dequeued element: %d\n", dequeue(&queue)); // Output: Dequeued element: 20
    printf("Dequeued element: %d\n", dequeue(&queue)); // Output: Dequeued element: 30

    if (isEmpty(&queue)) {
        printf("Queue is empty\n"); // Output: Queue is empty
    }

    return 0;
}
