#include <stdio.h>
#include <stdlib.h>

// Define structure for a polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial linked list
void insertTerm(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }

    struct Node* temp = *poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coeff, exp;

        if (poly1 != NULL && (poly2 == NULL || poly1->exp > poly2->exp)) {
            coeff = poly1->coeff;
            exp = poly1->exp;
            poly1 = poly1->next;
        } else if (poly2 != NULL && (poly1 == NULL || poly2->exp > poly1->exp)) {
            coeff = poly2->coeff;
            exp = poly2->exp;
            poly2 = poly2->next;
        } else {
            coeff = poly1->coeff + poly2->coeff;
            exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (coeff != 0) {
            struct Node* newNode = createNode(coeff, exp);
            if (result == NULL) {
                result = newNode;
                temp = result;
            } else {
                temp->next = newNode;
                temp = temp->next;
            }
        }
    }
    return result;
}

// Function to print the polynomial
void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next != NULL)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

// Driver function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Creating first polynomial: 5x^3 + 4x^2 + 2x^1
    insertTerm(&poly1, 5, 3);
    insertTerm(&poly1, 4, 2);
    insertTerm(&poly1, 2, 1);

    // Creating second polynomial: 3x^3 + 1x^2 + 6x^0
    insertTerm(&poly2, 3, 3);
    insertTerm(&poly2, 1, 2);
    insertTerm(&poly2, 6, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);

    printf("Sum: ");
    printPolynomial(result);

    return 0;
}
