#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Define and demonstrate the Node Structure of a Singly Linked List (SLL).
 */

// Definition of Singly Linked List Node
struct Node {
    int data;              // Data stored in the node
    struct Node* next;     // Pointer to the next node in the list
};

int main() {
    printf("--- Singly Linked List: Node Structure ---\n");

    // Dynamic allocation of a single node in heap memory
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Assign data and set next pointer to NULL
    node->data = 100;
    node->next = NULL;

    // Display node information
    printf("Node Address      : %p\n", (void*)node);
    printf("Node Data         : %d\n", node->data);
    printf("Next Node Pointer : %p\n", (void*)node->next);
    printf("Size of Node      : %u bytes\n", (unsigned int)sizeof(struct Node));

    // Free allocated memory
    free(node);
    return 0;
}
