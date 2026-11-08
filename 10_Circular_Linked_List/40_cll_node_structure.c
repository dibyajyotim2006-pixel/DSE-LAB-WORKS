#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Define and demonstrate the Node Structure of a Circular Linked List (CLL).
 * In a CLL, the next pointer of the last node points back to the first (head) node.
 */

// Definition of Circular Linked List Node
struct Node {
    int data;              // Value stored in the node
    struct Node* next;     // Pointer to the next node (circular link)
};

int main() {
    printf("--- Circular Linked List: Node Structure ---\n");

    // Dynamic allocation of a single node
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // In a single-node circular list, the node points to itself
    node->data = 100;
    node->next = node;

    printf("Node Address      : %p\n", (void*)node);
    printf("Node Data         : %d\n", node->data);
    printf("Next Node Pointer : %p (points back to self)\n", (void*)node->next);
    printf("Size of Node      : %u bytes\n", (unsigned int)sizeof(struct Node));

    free(node);
    return 0;
}
