#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Traversal of a Doubly Linked List (DLL) in both forward and backward directions.
 */

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to traverse DLL forward
void traverseForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Forward Traversal : ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to traverse DLL backward from the tail node
void traverseBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    // Traverse to the last node
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    printf("Backward Traversal: ");
    while (tail != NULL) {
        printf("%d <-> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

int main() {
    printf("--- Doubly Linked List: Traversal ---\n");

    // Creating sample DLL: 10 <-> 20 <-> 30 <-> 40
    struct Node* n1 = createNode(10);
    struct Node* n2 = createNode(20);
    struct Node* n3 = createNode(30);
    struct Node* n4 = createNode(40);

    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    struct Node* head = n1;

    traverseForward(head);
    traverseBackward(head);

    // Free memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
