#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Insertion at the end of a Doubly Linked List (DLL).
 */

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert at the end of DLL
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = value;
    newNode->next = NULL;

    // Case 1: Empty list
    if (head == NULL) {
        newNode->prev = NULL;
        printf("Inserted %d as head node.\n", value);
        return newNode;
    }

    // Case 2: Non-empty list - traverse to the last node
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    printf("Inserted %d at end.\n", value);
    return head;
}

void displayDLL(struct Node* head) {
    struct Node* temp = head;
    printf("List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- Doubly Linked List: Insertion at End ---\n");

    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("\nResulting list:\n");
    displayDLL(head);

    // Free memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
