#include <stdio.h>

int main() {
    int arr[3][4];
    (void)arr;
    int row, col, choice;
    int base, address;

    printf("Enter base address of array: ");
    fflush(stdout);
    if (scanf("%d", &base) != 1) return 0;

    printf("Enter row and column: ");
    fflush(stdout);
    if (scanf("%d %d", &row, &col) != 2) return 0;

    printf("\n1. Row Major Address\n");
    printf("2. Column Major Address\n");
    printf("Enter your choice: ");
    fflush(stdout);
    if (scanf("%d", &choice) != 1) return 0;

    switch (choice) {
        case 1:
            address = base + ((row * 4) + col) * 4;
            printf("Address = %d\n", address);
            break;
        case 2:
            address = base + ((col * 3) + row) * 4;
            printf("Address = %d\n", address);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
