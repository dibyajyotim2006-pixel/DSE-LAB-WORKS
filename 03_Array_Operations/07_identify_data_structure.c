#include <stdio.h>
#include <string.h>

int main() {
    char DS[35];

    printf("Enter a DS: ");
    if (scanf("%34s", DS) != 1) return 0;

    if (strcmp(DS, "Array") == 0) {
        printf("It is a non-primitive, Linear and static DS\n");
    } else if (strcmp(DS, "Linked List") == 0 || strcmp(DS, "LinkedList") == 0) {
        printf("It is a non-primitive, Linear and Dynamic DS\n");
    } else {
        printf("It is a non-primitive, non-linear DS\n");
    }

    return 0;
}
