#include <stdio.h>

int deleteIndex(int arr[], int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Error : Invalid index. Deletion not possible.\n");
        return 0;
    }
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    return 1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int size = 5;

    printf("Original array : ");
    printArray(arr, size);

    int targetIndex = 2;
    printf("Deleting element at index %d...\n", targetIndex);

    if (deleteIndex(arr, &size, targetIndex)) {
        printf("Array after deletion : ");
        printArray(arr, size);
    }

    return 0;
}
