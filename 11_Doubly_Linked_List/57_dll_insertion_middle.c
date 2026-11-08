#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Insertion in the middle (at a given position) of a Doubly Linked List (DLL).
 */

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert at a specified position in DLL (1-based index)
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    if (position < 1) {
        printf("Invalid position: %d.\n", position);
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Insertion at position 1 (head)
    if (position == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        printf("Inserted %d at position 1.\n", value);
        return newNode;
    }

    // Traverse to the (position - 1)-th node
    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position %d is out of bounds! Insertion failed.\n", position);
        free(newNode);
        return head;
    }

    // Insert newNode between current and current->next
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    printf("Inserted %d at position %d.\n", value, position);
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
    printf("--- Doubly Linked List: Insertion in the Middle ---\n");

    struct Node* head = NULL;
    head = insertAtPosition(head, 10, 1);
    head = insertAtPosition(head, 20, 2);
    head = insertAtPosition(head, 40, 3);
    head = insertAtPosition(head, 50, 4);

    printf("\nInitial list:\n");
    displayDLL(head);

    // Insert 30 at position 3 (between 20 and 40)
    printf("\nInserting 30 at middle position 3:\n");
    head = insertAtPosition(head, 30, 3);

    printf("Updated list:\n");
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
