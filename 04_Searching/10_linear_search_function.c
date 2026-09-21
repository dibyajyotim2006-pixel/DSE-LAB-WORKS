#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int data[] = {10, 50, 30, 70, 80, 60, 20};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 70;

    int result = linearSearch(data, size, target);
    if (result != -1) {
        printf("Element found at index : %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
