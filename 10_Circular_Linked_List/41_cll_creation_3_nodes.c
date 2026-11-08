#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Creation and manual linking of 3 nodes in a Circular Linked List (CLL).
 */

struct Node {
    int data;
    struct Node* next;
};

int main() {
    printf("--- Circular Linked List: Creation of 3 Nodes ---\n");

    // Allocate memory for three nodes
    struct Node* first  = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third  = (struct Node*)malloc(sizeof(struct Node));

    if (first == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Assign data and link circular: first -> second -> third -> first
    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = first; // Points back to the first node (head)

    struct Node* head = first;

    printf("Node 1: Data = %d, Address = %p, Next = %p (Node 2)\n", first->data, (void*)first, (void*)first->next);
    printf("Node 2: Data = %d, Address = %p, Next = %p (Node 3)\n", second->data, (void*)second, (void*)second->next);
    printf("Node 3: Data = %d, Address = %p, Next = %p (Back to Node 1)\n", third->data, (void*)third, (void*)third->next);

    // Circular traversal using do-while
    printf("\nCircular Traversal: ");
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);

    // Free memory
    free(first);
    free(second);
    free(third);

    return 0;
}
