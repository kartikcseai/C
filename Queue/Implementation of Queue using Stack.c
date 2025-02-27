#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Stack structure
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Initialize a stack
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Queue structure using two stacks
typedef struct {
    Stack stack1; // For enqueue operations
    Stack stack2; // For dequeue operations
} Queue;

// Initialize the queue
void initializeQueue(Queue* queue) {
    initializeStack(&queue->stack1);
    initializeStack(&queue->stack2);
}

// Enqueue an element into the queue
void enqueue(Queue* queue, int data) {
    if (isFull(&queue->stack1)) {
        printf("Queue is full!\n");
        return;
    }
    push(&queue->stack1, data);
}

// Dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(&queue->stack1) && isEmpty(&queue->stack2)) {
        printf("Queue is empty!\n");
        return -1;
    }

    // If stack2 is empty, move all elements from stack1 to stack2
    if (isEmpty(&queue->stack2)) {
        while (!isEmpty(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }

    // Pop from stack2 (which is the front of the queue)
    return pop(&queue->stack2);
}

// Display the queue
void displayQueue(Queue* queue) {
    if (isEmpty(&queue->stack1) && isEmpty(&queue->stack2)) {
        printf("Queue is empty.\n");
        return;
    }

    // Display stack2 (front of the queue)
    printf("Queue: ");
    for (int i = queue->stack2.top; i >= 0; i--) {
        printf("%d ", queue->stack2.arr[i]);
    }

    // Display stack1 (rear of the queue)
    for (int i = 0; i <= queue->stack1.top; i++) {
        printf("%d ", queue->stack1.arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("After enqueue operations:\n");
    displayQueue(&queue);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    printf("After dequeue operations:\n");
    displayQueue(&queue);

    enqueue(&queue, 40);
    enqueue(&queue, 50);

    printf("After enqueue operations:\n");
    displayQueue(&queue);

    return 0;
}
