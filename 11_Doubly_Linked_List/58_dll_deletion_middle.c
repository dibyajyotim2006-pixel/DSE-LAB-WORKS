#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Deletion from the middle (at a given position) of a Doubly Linked List (DLL).
 */

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete node at a given position in DLL (1-based index)
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("Underflow! List is empty.\n");
        return NULL;
    }

    if (position < 1) {
        printf("Invalid position: %d.\n", position);
        return head;
    }

    // Case 1: Delete head node (position 1)
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        printf("Deleted node with value %d from position 1.\n", temp->data);
        free(temp);
        return head;
    }

    // Case 2: Traverse to the node at `position`
    struct Node* current = head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position %d is out of bounds! Deletion failed.\n", position);
        return head;
    }

    // Unlink current node
    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    printf("Deleted node with value %d from position %d.\n", current->data, position);
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
    printf("--- Doubly Linked List: Deletion from Middle ---\n");

    struct Node* head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    printf("Initial list:\n");
    displayDLL(head);

    // Delete middle node at position 3 (value 30)
    printf("\nDeleting node at position 3:\n");
    head = deleteAtPosition(head, 3);
    printf("List after deletion:\n");
    displayDLL(head);

    // Delete invalid position
    printf("\nDeleting node at position 10:\n");
    head = deleteAtPosition(head, 10);

    // Free remaining memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
