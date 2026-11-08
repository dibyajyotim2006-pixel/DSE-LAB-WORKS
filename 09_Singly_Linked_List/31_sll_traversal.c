#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Traversal of a Singly Linked List (SLL) using a function.
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and display the linked list
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    int count = 0;

    printf("List elements: ");
    while (current != NULL) {
        printf("[%d] -> ", current->data);
        count++;
        current = current->next;
    }
    printf("NULL\n");
    printf("Total nodes traversed: %d\n", count);
}

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    printf("--- Singly Linked List: Traversal ---\n");

    // Creating sample list: 5 -> 15 -> 25 -> 35 -> NULL
    struct Node* head = createNode(5);
    head->next = createNode(15);
    head->next->next = createNode(25);
    head->next->next->next = createNode(35);

    // Perform traversal
    traverseList(head);

    // Free memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
