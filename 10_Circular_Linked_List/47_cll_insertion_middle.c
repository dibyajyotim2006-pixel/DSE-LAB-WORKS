#include <stdio.h>
#include <stdlib.h>

/*
 * Question: Insertion in the middle (at a given position) of a Circular Linked List (CLL).
 */

struct Node {
    int data;
    struct Node* next;
};

// Function to insert at a given position in CLL (1-based index)
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    if (position < 1) {
        printf("Invalid position: %d.\n", position);
        return head;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = value;

    // Case 1: Inserting at position 1 (head)
    if (position == 1) {
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        printf("Inserted %d at position 1.\n", value);
        return newNode;
    }

    if (head == NULL) {
        printf("Position %d out of bounds! List is empty.\n", position);
        free(newNode);
        return head;
    }

    // Traverse to (position - 1)-th node
    struct Node* current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
        if (current == head) {
            printf("Position %d is out of bounds!\n", position);
            free(newNode);
            return head;
        }
    }

    newNode->next = current->next;
    current->next = newNode;
    printf("Inserted %d at position %d.\n", value, position);

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
    printf("--- Circular Linked List: Insertion in the Middle ---\n");

    struct Node* head = NULL;
    head = insertAtPosition(head, 10, 1);
    head = insertAtPosition(head, 20, 2);
    head = insertAtPosition(head, 40, 3);
    head = insertAtPosition(head, 50, 4);

    printf("\nInitial list: ");
    displayCLL(head);

    // Insert 30 at position 3 (in the middle between 20 and 40)
    printf("\nInserting 30 at position 3:\n");
    head = insertAtPosition(head, 30, 3);

    printf("Updated list: ");
    displayCLL(head);

    // Free memory
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
