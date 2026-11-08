#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Traversal of a Circular Linked List (CLL) using a function.
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the circular linked list
void traverseCLL(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    int count = 0;

    printf("Circular List: ");
    do {
        printf("[%d] -> ", current->data);
        count++;
        current = current->next;
    } while (current != head);

    printf("(Head: %d)\n", head->data);
    printf("Total nodes traversed: %d\n", count);
}

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
    printf("--- Circular Linked List: Traversal ---\n");

    // Create 4 nodes: 10 -> 20 -> 30 -> 40 -> (back to 10)
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);
    struct Node* fourth = createNode(40);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head; // Closing the circle

    // Traverse
    traverseCLL(head);

    // Free memory
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
