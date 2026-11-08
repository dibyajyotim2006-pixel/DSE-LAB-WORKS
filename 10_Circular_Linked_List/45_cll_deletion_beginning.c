#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Deletion at the beginning of a Circular Linked List (CLL).
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to delete the first node of a CLL
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Underflow! List is empty.\n");
        return NULL;
    }

    // Case 1: Only one node in the list
    if (head->next == head) {
        printf("Deleted node with value %d (list is now empty).\n", head->data);
        free(head);
        return NULL;
    }

    // Case 2: More than one node - find last node
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    struct Node* temp = head;
    last->next = head->next; // Last node points to the second node
    head = head->next;       // Update head

    printf("Deleted node with value %d from beginning.\n", temp->data);
    free(temp);

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
    printf("--- Circular Linked List: Deletion at Beginning ---\n");

    struct Node* head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Initial list: ");
    displayCLL(head);

    head = deleteAtBeginning(head);
    printf("After 1st deletion: ");
    displayCLL(head);

    head = deleteAtBeginning(head);
    printf("After 2nd deletion: ");
    displayCLL(head);

    head = deleteAtBeginning(head);
    printf("After 3rd deletion: ");
    displayCLL(head);

    return 0;
}
