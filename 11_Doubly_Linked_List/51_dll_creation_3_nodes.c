#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    printf("--- Doubly Linked List: Creation of 3 Nodes ---\n");

    struct Node* first  = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third  = (struct Node*)malloc(sizeof(struct Node));

    if (first == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    first->data = 10;
    first->prev = NULL;
    first->next = second;

    second->data = 20;
    second->prev = first;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = NULL;

    struct Node* head = first;

    printf("Node 1: Prev=%p, Data=%d, Next=%p\n", (void*)first->prev, first->data, (void*)first->next);
    printf("Node 2: Prev=%p, Data=%d, Next=%p\n", (void*)second->prev, second->data, (void*)second->next);
    printf("Node 3: Prev=%p, Data=%d, Next=%p\n", (void*)third->prev, third->data, (void*)third->next);

    printf("\nForward traversal : NULL <- ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("[%d] <-> ", temp->data);
        if (temp->next == NULL) break;
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Backward traversal: NULL <- ");
    while (temp != NULL) {
        printf("[%d] <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");

    free(first);
    free(second);
    free(third);

    return 0;
}
