#include <stdio.h>

int main() {
    int a[5];
    int b[2][3];
    int i, j;

    printf("Enter 5 elements of (1-D) Array :\n");
    for (i = 0; i < 5; i++) {
        if (scanf("%d", &a[i]) != 1) return 0;
    }

    printf("Enter 6 elements of (2-D) Array :\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            if (scanf("%d", &b[i][j]) != 1) return 0;
        }
    }

    printf("\nOne element from (1-D) array : %d\n", a[2]);
    printf("One element from (2-D) array : %d\n", b[1][2]);

    printf("\nTraversing 1-D array :\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }

    printf("\n\nTraversing (2-D) array :\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
