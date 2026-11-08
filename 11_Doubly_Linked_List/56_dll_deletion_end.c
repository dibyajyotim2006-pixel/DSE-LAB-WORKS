#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Deletion at the end of a Doubly Linked List (DLL).
 */

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete the last node of DLL
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("Underflow! List is empty.\n");
        return NULL;
    }

    // Case 1: Only one node in the list
    if (head->next == NULL) {
        printf("Deleted last node with value %d (list is now empty).\n", head->data);
        free(head);
        return NULL;
    }

    // Case 2: Traverse to the last node
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Disconnect last node
    current->prev->next = NULL;
    printf("Deleted last node with value %d.\n", current->data);
    free(current);

    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void displayDLL(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- Doubly Linked List: Deletion at End ---\n");

    struct Node* head = NULL;
    head = insertAtEnd(head, 100);
    head = insertAtEnd(head, 200);
    head = insertAtEnd(head, 300);

    printf("Initial list:\n");
    displayDLL(head);

    head = deleteAtEnd(head);
    displayDLL(head);

    head = deleteAtEnd(head);
    displayDLL(head);

    head = deleteAtEnd(head);
    displayDLL(head);

    return 0;
}
