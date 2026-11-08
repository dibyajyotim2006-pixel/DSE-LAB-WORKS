#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Deletion at the end of a Singly Linked List (SLL).
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to delete the last node of the list
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("Underflow! List is already empty.\n");
        return NULL;
    }

    // Case 1: Only one node in the list
    if (head->next == NULL) {
        printf("Deleted last node with value %d.\n", head->data);
        free(head);
        return NULL;
    }

    // Case 2: More than one node - traverse to the second-to-last node
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    printf("Deleted last node with value %d.\n", current->next->data);
    free(current->next); // Free the last node
    current->next = NULL; // Update second-to-last node's next to NULL

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
    printf("--- Singly Linked List: Deletion at End ---\n");

    struct Node* head = NULL;
    head = insertAtEnd(head, 100);
    head = insertAtEnd(head, 200);
    head = insertAtEnd(head, 300);

    printf("Initial list: ");
    displayList(head);

    head = deleteAtEnd(head);
    printf("After deleting last node: ");
    displayList(head);

    head = deleteAtEnd(head);
    printf("After deleting last node: ");
    displayList(head);

    head = deleteAtEnd(head);
    printf("After deleting last node: ");
    displayList(head);

    return 0;
}
