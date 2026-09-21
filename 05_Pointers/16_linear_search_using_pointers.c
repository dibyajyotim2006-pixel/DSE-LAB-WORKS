#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    int key, found = 0;

    printf("Enter element to search : ");
    if (scanf("%d", &key) != 1) return 0;

    for (int i = 0; i < 5; i++) {
        if (*ptr == key) {
            printf("Element found at index : %d\n", i);
            found = 1;
            break;
        }
        ptr++;
    }

    if (!found) {
        printf("Element not found\n");
    }

    return 0;
}
