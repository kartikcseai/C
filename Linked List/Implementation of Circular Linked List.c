#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Point to itself to form a circle
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to insert a node at the beginning of the circular linked list
void insertBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        *head = newNode;
        temp->next = *head;
    }
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *current = *head, *prev = NULL;

    // Find the node to delete
    while (current->data != key) {
        if (current->next == *head) {
            printf("Node with value %d not found!\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }

    // If the node to delete is the only node
    if (current->next == *head && prev == NULL) {
        *head = NULL;
        free(current);
        return;
    }

    // If the node to delete is the head
    if (current == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = current->next;
        prev->next = *head;
        free(current);
    }
    // If the node to delete is the last node
    else if (current->next == *head) {
        prev->next = *head;
        free(current);
    }
    // If the node to delete is in the middle
    else {
        prev->next = current->next;
        free(current);
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert elements
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertBeginning(&head, 5);

    // Display the list
    printf("Circular Linked List: ");
    displayList(head);

    // Delete a node
    deleteNode(&head, 20);
    printf("After deleting 20: ");
    displayList(head);

    return 0;
}
