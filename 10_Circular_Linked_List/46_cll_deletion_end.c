#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("Underflow! List is empty.\n");
        return NULL;
    }

    if (head->next == head) {
        printf("Deleted node with value %d (list is now empty).\n", head->data);
        free(head);
        return NULL;
    }

    struct Node* current = head;
    while (current->next->next != head) {
        current = current->next;
    }

    struct Node* lastNode = current->next;
    current->next = head;

    printf("Deleted node with value %d from end.\n", lastNode->data);
    free(lastNode);

    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    struct Node* last = head;
    while (last->next != head) last = last->next;
    last->next = newNode;
    newNode->next = head;
    return head;
}

void displayCLL(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}

int main() {
    printf("--- Circular Linked List: Deletion at End ---\n");

    struct Node* head = NULL;
    head = insertAtEnd(head, 100);
    head = insertAtEnd(head, 200);
    head = insertAtEnd(head, 300);

    printf("Initial list: ");
    displayCLL(head);

    head = deleteAtEnd(head);
    printf("After deleting last node: ");
    displayCLL(head);

    head = deleteAtEnd(head);
    printf("After deleting last node: ");
    displayCLL(head);

    head = deleteAtEnd(head);
    printf("After deleting last node: ");
    displayCLL(head);

    return 0;
}
