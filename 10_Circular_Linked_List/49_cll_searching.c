#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int searchCLL(struct Node* head, int key) {
    if (head == NULL) {
        return -1;
    }

    struct Node* current = head;
    int position = 1;

    do {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    } while (current != head);

    return -1;
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
    printf("--- Circular Linked List: Searching ---\n");

    struct Node* head = NULL;
    head = insertAtEnd(head, 15);
    head = insertAtEnd(head, 25);
    head = insertAtEnd(head, 35);
    head = insertAtEnd(head, 45);

    printf("Circular List: ");
    displayCLL(head);

    int target1 = 35;
    int pos1 = searchCLL(head, target1);
    if (pos1 != -1) {
        printf("Element %d found at position %d.\n", target1, pos1);
    } else {
        printf("Element %d not found in list.\n", target1);
    }

    int target2 = 99;
    int pos2 = searchCLL(head, target2);
    if (pos2 != -1) {
        printf("Element %d found at position %d.\n", target2, pos2);
    } else {
        printf("Element %d not found in list.\n", target2);
    }

    if (head != NULL) {
        struct Node* current = head;
        struct Node* nextNode;
        do {
            nextNode = current->next;
            free(current);
            current = nextNode;
        } while (current != head);
    }

    return 0;
}
