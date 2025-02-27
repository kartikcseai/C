#include <iostream>
using namespace std;

// Node structure
struct Node {
    int coef, exp;
    Node* next;
    Node(int c, int e) : coef(c), exp(e), next(nullptr) {}
};

// Function to insert node at the end
void insert(Node*& head, int coef, int exp) {
    Node* newNode = new Node(coef, exp);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Function to add terms in sorted order and combine like terms
Node* addPolynomials(Node* poly) {
    if (!poly) return nullptr;

    Node* result = nullptr;
    Node* temp = poly;

    while (temp) {
        Node* prev = nullptr;
        Node* curr = result;
        while (curr && curr->exp > temp->exp) {
            prev = curr;
            curr = curr->next;
        }
        
        if (curr && curr->exp == temp->exp) {
            curr->coef += temp->coef;
        } else {
            Node* newNode = new Node(temp->coef, temp->exp);
            if (!prev) {
                newNode->next = result;
                result = newNode;
            } else {
                newNode->next = prev->next;
                prev->next = newNode;
            }
        }
        temp = temp->next;
    }
    return result;
}

// Function to multiply two polynomials
Node* multiplyPolynomials(Node* p1, Node* p2) {
    if (!p1 || !p2) return nullptr;

    Node* result = nullptr;
    
    for (Node* temp1 = p1; temp1; temp1 = temp1->next) {
        for (Node* temp2 = p2; temp2; temp2 = temp2->next) {
            insert(result, temp1->coef * temp2->coef, temp1->exp + temp2->exp);
        }
    }

    return addPolynomials(result);  // Combine like terms
}

// Function to print polynomial
void printPolynomial(Node* head) {
    while (head) {
        cout << head->coef << "x^" << head->exp;
        if (head->next) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    // Polynomial 1: 3x^2 + 5x + 6
    insert(poly1, 3, 2);
    insert(poly1, 5, 1);
    insert(poly1, 6, 0);

    // Polynomial 2: 2x + 4
    insert(poly2, 2, 1);
    insert(poly2, 4, 0);

    cout << "Polynomial 1: ";
    printPolynomial(poly1);
    cout << "Polynomial 2: ";
    printPolynomial(poly2);

    Node* product = multiplyPolynomials(poly1, poly2);
    cout << "Product: ";
    printPolynomial(product);

    return 0;
}
