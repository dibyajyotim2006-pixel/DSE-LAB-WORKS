#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Insertion at the beginning of a Singly Linked List (SLL).
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = value;
    newNode->next = head; // Point new node to current head
    head = newNode;       // Update head to point to new node
    printf("Inserted %d at beginning.\n", value);
    return head;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- Singly Linked List: Insertion at Beginning ---\n");

    struct Node* head = NULL; // Initially empty list

    printf("Initial list: ");
    displayList(head);

    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    printf("List after insertions: ");
    displayList(head);

    // Free memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
