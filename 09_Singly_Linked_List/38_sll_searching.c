#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int searchElement(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
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
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- Singly Linked List: Searching ---\n");

    struct Node* head = NULL;
    head = insertAtEnd(head, 15);
    head = insertAtEnd(head, 25);
    head = insertAtEnd(head, 35);
    head = insertAtEnd(head, 45);

    printf("List: ");
    displayList(head);

    int target1 = 35;
    int pos1 = searchElement(head, target1);
    if (pos1 != -1) {
        printf("Element %d found at position %d.\n", target1, pos1);
    } else {
        printf("Element %d not found in list.\n", target1);
    }

    int target2 = 99;
    int pos2 = searchElement(head, target2);
    if (pos2 != -1) {
        printf("Element %d found at position %d.\n", target2, pos2);
    } else {
        printf("Element %d not found in list.\n", target2);
    }

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
