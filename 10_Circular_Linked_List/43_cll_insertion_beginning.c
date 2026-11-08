#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Insertion at the beginning of a Circular Linked List (CLL).
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of CLL
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = value;

    // Case 1: Empty list
    if (head == NULL) {
        newNode->next = newNode; // Points to itself
        printf("Inserted %d as head node.\n", value);
        return newNode;
    }

    // Case 2: Non-empty list - find the last node
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    // Link new node
    newNode->next = head;
    last->next = newNode;
    head = newNode; // Update head

    printf("Inserted %d at beginning.\n", value);
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
    printf("--- Circular Linked List: Insertion at Beginning ---\n");

    struct Node* head = NULL;

    printf("Initial list: ");
    displayCLL(head);

    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    printf("List after insertions: ");
    displayCLL(head);

    // Free memory
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
