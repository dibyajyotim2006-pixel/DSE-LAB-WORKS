#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    printf("--- Circular Linked List: Node Structure ---\n");

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    node->data = 100;
    node->next = node;

    printf("Node Address      : %p\n", (void*)node);
    printf("Node Data         : %d\n", node->data);
    printf("Next Node Pointer : %p (points back to self)\n", (void*)node->next);
    printf("Size of Node      : %u bytes\n", (unsigned int)sizeof(struct Node));

    free(node);
    return 0;
}
