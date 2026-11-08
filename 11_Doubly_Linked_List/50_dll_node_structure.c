#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Define and demonstrate the Node Structure of a Doubly Linked List (DLL).
 * In a DLL, each node contains data, a pointer to the next node, and a pointer to the previous node.
 */

// Definition of Doubly Linked List Node
struct Node {
    int data;              // Value stored in the node
    struct Node* prev;     // Pointer to the previous node
    struct Node* next;     // Pointer to the next node
};

int main() {
    printf("--- Doubly Linked List: Node Structure ---\n");

    // Dynamic allocation of a single node in heap
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize node fields
    node->data = 100;
    node->prev = NULL;
    node->next = NULL;

    printf("Node Address      : %p\n", (void*)node);
    printf("Node Data         : %d\n", node->data);
    printf("Prev Node Pointer : %p\n", (void*)node->prev);
    printf("Next Node Pointer : %p\n", (void*)node->next);
    printf("Size of Node      : %u bytes\n", (unsigned int)sizeof(struct Node));

    free(node);
    return 0;
}
