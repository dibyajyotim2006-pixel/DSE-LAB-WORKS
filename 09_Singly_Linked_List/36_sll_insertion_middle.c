#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtPosition(struct Node* head, int value, int position) {
    if (position < 1) {
        printf("Invalid position: %d. Position must be >= 1.\n", position);
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        printf("Inserted %d at position %d.\n", value, position);
        return newNode;
    }

    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position %d is out of bounds! Insertion failed.\n", position);
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    printf("Inserted %d at position %d.\n", value, position);

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
    printf("--- Singly Linked List: Insertion in the Middle ---\n");

    struct Node* head = NULL;

    head = insertAtPosition(head, 10, 1);
    head = insertAtPosition(head, 20, 2);
    head = insertAtPosition(head, 40, 3);
    head = insertAtPosition(head, 50, 4);

    printf("\nInitial list: ");
    displayList(head);

    printf("\nInserting 30 at middle position 3:\n");
    head = insertAtPosition(head, 30, 3);

    printf("Updated list: ");
    displayList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
