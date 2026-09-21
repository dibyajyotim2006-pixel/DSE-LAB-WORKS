#include <stdio.h>

void insert(int arr[], int *n, int pos, int value) {
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 2;
    int value = 99;

    printf("Original array : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insert(arr, &n, pos, value);

    printf("Array after insertion : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
