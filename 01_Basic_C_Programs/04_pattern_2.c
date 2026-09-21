#include <stdio.h>

int main() {
    int num;
    printf("Enter no. of rows : ");
    if (scanf("%d", &num) != 1) return 0;

    for (int i = num; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
