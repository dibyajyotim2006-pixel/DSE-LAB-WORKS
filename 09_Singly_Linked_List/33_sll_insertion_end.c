#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Insertion at the end of a Singly Linked List (SLL).
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty, new node becomes the head
    if (head == NULL) {
        printf("Inserted %d as head node.\n", value);
        return newNode;
    }

    // Traverse to the last node
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    printf("Inserted %d at end.\n", value);
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
    printf("--- Singly Linked List: Insertion at End ---\n");

    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Resulting list: ");
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
