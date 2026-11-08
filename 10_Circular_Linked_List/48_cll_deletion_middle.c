#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Deletion from the middle (at a given position) of a Circular Linked List (CLL).
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to delete node at a given position in CLL (1-based index)
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
        if (head->next == head) {
            printf("Deleted node with value %d from position 1.\n", head->data);
            free(head);
            return NULL;
        }
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        struct Node* temp = head;
        last->next = head->next;
        head = head->next;
        printf("Deleted node with value %d from position 1.\n", temp->data);
        free(temp);
        return head;
    }

    // Case 2: Delete node at given position
    struct Node* current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
        if (current->next == head) {
            printf("Position %d is out of bounds!\n", position);
            return head;
        }
    }

    if (current->next == head) {
        printf("Position %d is out of bounds!\n", position);
        return head;
    }

    struct Node* targetNode = current->next;
    current->next = targetNode->next;
    printf("Deleted node with value %d from position %d.\n", targetNode->data, position);
    free(targetNode);

    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    struct Node* last = head;
    while (last->next != head) last = last->next;
    last->next = newNode;
    newNode->next = head;
    return head;
}

void displayCLL(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}

int main() {
    printf("--- Circular Linked List: Deletion from Middle ---\n");

    struct Node* head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    printf("Initial list: ");
    displayCLL(head);

    // Delete middle node at position 3 (value 30)
    printf("\nDeleting node at position 3:\n");
    head = deleteAtPosition(head, 3);
    printf("List after deletion: ");
    displayCLL(head);

    // Delete at invalid position
    printf("\nDeleting node at position 10:\n");
    head = deleteAtPosition(head, 10);

    // Clean up remaining nodes
    if (head != NULL) {
        struct Node* current = head;
        struct Node* nextNode;
        do {
            nextNode = current->next;
            free(current);
            current = nextNode;
        } while (current != head);
    }

    return 0;
}
