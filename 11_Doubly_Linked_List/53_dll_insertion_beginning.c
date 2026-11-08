#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Insertion at the beginning of a Doubly Linked List (DLL).
 */

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert at the beginning of DLL
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    // If list is not empty, update old head's prev pointer
    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode; // Update head
    printf("Inserted %d at beginning.\n", value);
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
    printf("--- Doubly Linked List: Insertion at Beginning ---\n");

    struct Node* head = NULL;

    printf("Initial state:\n");
    displayDLL(head);

    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    printf("\nAfter insertions:\n");
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
