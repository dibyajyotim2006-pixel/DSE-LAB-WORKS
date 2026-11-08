#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Deletion at the beginning of a Singly Linked List (SLL).
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to delete the first node of the list
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Underflow! List is already empty.\n");
        return NULL;
    }

    struct Node* temp = head; // Store head to free memory
    head = head->next;        // Move head to next node
    printf("Deleted node with value %d from beginning.\n", temp->data);
    free(temp);               // Free memory

    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- Singly Linked List: Deletion at Beginning ---\n");

    struct Node* head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Initial list: ");
    displayList(head);

    head = deleteAtBeginning(head);
    printf("After 1st deletion: ");
    displayList(head);

    head = deleteAtBeginning(head);
    printf("After 2nd deletion: ");
    displayList(head);

    head = deleteAtBeginning(head);
    printf("After 3rd deletion: ");
    displayList(head);

    // Attempt deletion on empty list
    head = deleteAtBeginning(head);

    return 0;
}
