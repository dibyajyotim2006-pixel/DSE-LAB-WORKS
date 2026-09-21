#include <stdio.h>

void SelectionSort(int array[], int size) {
    for (int step = 0; step < size / 2; step++) {
        int min_idx = step;
        int max_idx = step;

        for (int i = step + 1; i < size - step; i++) {
            if (array[i] < array[min_idx]) {
                min_idx = i;
            }
            if (array[i] > array[max_idx]) {
                max_idx = i;
            }
        }

        int temp = array[step];
        array[step] = array[min_idx];
        array[min_idx] = temp;

        if (max_idx == step) {
            max_idx = min_idx;
        }

        temp = array[size - step - 1];
        array[size - step - 1] = array[max_idx];
        array[max_idx] = temp;

        printf("Step %d: ", step + 1);
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}

int main() {
    int data[] = {6, 4, 7, 8, 1, 9, 5};
    int size = sizeof(data) / sizeof(data[0]);

    SelectionSort(data, size);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
