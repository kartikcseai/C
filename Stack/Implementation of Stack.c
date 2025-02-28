#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define the stack structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is full
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        s->top++;
        s->items[s->top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop from an empty stack\n");
        return -1; // Return an invalid value to indicate underflow
    } else {
        int value = s->items[s->top];
        s->top--;
        printf("Popped %d from the stack\n", value);
        return value;
    }
}

// Function to peek at the top element of the stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty, cannot peek\n");
        return -1; // Return an invalid value to indicate empty stack
    } else {
        return s->items[s->top];
    }
}

// Function to display the stack
void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack s;
    initializeStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    displayStack(&s);

    printf("Top element is %d\n", peek(&s));

    pop(&s);
    pop(&s);

    displayStack(&s);

    pop(&s);
    pop(&s); // This will cause an underflow

    return 0;
}
