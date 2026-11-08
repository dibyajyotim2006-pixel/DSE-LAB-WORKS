#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Creation and manual linking of 3 nodes in a Singly Linked List (SLL).
 */

struct Node {
    int data;
    struct Node* next;
};

int main() {
    printf("--- Singly Linked List: Creation of 3 Nodes ---\n");

    // Allocate memory for three nodes
    struct Node* first  = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third  = (struct Node*)malloc(sizeof(struct Node));

    if (first == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Assign data and link nodes
    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // Head points to the first node
    struct Node* head = first;

    // Display each node's details
    printf("Node 1: Data = %d, Address = %p, Next = %p\n", first->data, (void*)first, (void*)first->next);
    printf("Node 2: Data = %d, Address = %p, Next = %p\n", second->data, (void*)second, (void*)second->next);
    printf("Node 3: Data = %d, Address = %p, Next = %p\n", third->data, (void*)third, (void*)third->next);

    // Print the entire linked list
    printf("\nLinked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Clean up allocated memory
    free(first);
    free(second);
    free(third);

    return 0;
}
