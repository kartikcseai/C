#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the stack structure
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack) {
    stack->top = -1; // Stack is empty initially
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value; // Increment top and add the value
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return -1; // Return an invalid value to indicate underflow
    }
    return stack->arr[stack->top--]; // Return the top element and decrement top
}

// Function to get the top element of the stack without popping it
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return an invalid value to indicate empty stack
    }
    return stack->arr[stack->top];
}

// Function to display the stack
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack); // Output: Stack elements: 10 20 30

    printf("Top element: %d\n", peek(&stack)); // Output: Top element: 30

    printf("Popped element: %d\n", pop(&stack)); // Output: Popped element: 30
    display(&stack); // Output: Stack elements: 10 20

    printf("Popped element: %d\n", pop(&stack)); // Output: Popped element: 20
    printf("Popped element: %d\n", pop(&stack)); // Output: Popped element: 10

    if (isEmpty(&stack)) {
        printf("Stack is empty\n"); // Output: Stack is empty
    }

    return 0;
}
