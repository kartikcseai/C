#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the stack
struct Stack {
    struct Node* top;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top; // Point the new node to the current top
    stack->top = newNode; // Update the top to the new node
    printf("%d pushed to the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        exit(1);
    }
    struct Node* temp = stack->top; // Store the top node
    int poppedData = temp->data; // Save the data of the top node
    stack->top = stack->top->next; // Move the top to the next node
    free(temp); // Free the memory of the popped node
    return poppedData;
}

// Function to peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek.\n");
        exit(1);
    }
    return stack->top->data;
}

// Function to display the stack
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to test the stack implementation
int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    displayStack(&stack); // Output: Stack: 30 -> 20 -> 10 -> NULL

    printf("Top element: %d\n", peek(&stack)); // Output: Top element: 30

    printf("Popped: %d\n", pop(&stack)); // Output: Popped: 30
    displayStack(&stack); // Output: Stack: 20 -> 10 -> NULL

    printf("Popped: %d\n", pop(&stack)); // Output: Popped: 20
    displayStack(&stack); // Output: Stack: 10 -> NULL

    printf("Popped: %d\n", pop(&stack)); // Output: Popped: 10
    displayStack(&stack); // Output: Stack is empty.

    return 0;
}
