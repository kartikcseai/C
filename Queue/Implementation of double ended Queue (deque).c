#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Maximum size of the deque

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
} Deque;

// Function to initialize the deque
void initializeDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = 0;
    dq->size = 0;
}

// Function to check if the deque is empty
int isEmpty(Deque *dq) {
    return dq->size == 0;
}

// Function to check if the deque is full
int isFull(Deque *dq) {
    return dq->size == MAX_SIZE;
}

// Function to add an element to the front of the deque
void addFront(Deque *dq, int item) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot add to front.\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->items[dq->front] = item;
    dq->size++;
    printf("Added %d to front.\n", item);
}

// Function to add an element to the rear of the deque
void addRear(Deque *dq, int item) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot add to rear.\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }
    dq->items[dq->rear] = item;
    dq->size++;
    printf("Added %d to rear.\n", item);
}

// Function to remove an element from the front of the deque
int removeFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot remove from front.\n");
        exit(EXIT_FAILURE);
    }
    int item = dq->items[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    dq->size--;
    printf("Removed %d from front.\n", item);
    return item;
}

// Function to remove an element from the rear of the deque
int removeRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot remove from rear.\n");
        exit(EXIT_FAILURE);
    }
    int item = dq->items[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->size--;
    printf("Removed %d from rear.\n", item);
    return item;
}

// Function to print the deque
void printDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    int i = dq->front;
    printf("Deque: ");
    for (int count = 0; count < dq->size; count++) {
        printf("%d ", dq->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

// Example usage
int main() {
    Deque dq;
    initializeDeque(&dq);

    addRear(&dq, 10);
    addFront(&dq, 20);
    addRear(&dq, 30);
    addFront(&dq, 40);

    printDeque(&dq); // Output: Deque: 40 20 10 30

    removeFront(&dq); // Output: Removed 40 from front
    removeRear(&dq);  // Output: Removed 30 from rear

    printDeque(&dq); // Output: Deque: 20 10

    return 0;
}
