#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("Underflow! List is empty.\n");
        return NULL;
    }

    if (position < 1) {
        printf("Invalid position: %d.\n", position);
        return head;
    }

    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted node with value %d from position 1.\n", temp->data);
        free(temp);
        return head;
    }

    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Position %d is out of bounds! Deletion failed.\n", position);
        return head;
    }

    struct Node* targetNode = current->next;
    current->next = targetNode->next;
    printf("Deleted node with value %d from position %d.\n", targetNode->data, position);
    free(targetNode);

    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- Singly Linked List: Deletion from Middle ---\n");

    struct Node* head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    printf("Initial list: ");
    displayList(head);

    printf("\nDeleting node at position 3:\n");
    head = deleteAtPosition(head, 3);
    printf("List after deletion: ");
    displayList(head);

    printf("\nDeleting node at position 10:\n");
    head = deleteAtPosition(head, 10);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
