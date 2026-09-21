#include <stdio.h>

void bubblesort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int found = 0;
        for (int i = 0; i < size - step - 1; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                found = 1;
            }
        }
        printf("Step %d: ", step + 1);
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");

        if (found == 0) {
            break;
        }
    }
}

int main() {
    int data[] = {6, 4, 7, 8, 1, 9, 5};
    int size = sizeof(data) / sizeof(data[0]);

    bubblesort(data, size);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
