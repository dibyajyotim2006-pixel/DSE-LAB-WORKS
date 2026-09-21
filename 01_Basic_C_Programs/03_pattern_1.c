#include <stdio.h>

int main() {
    int num;
    printf("Enter numbers of rows : ");
    if (scanf("%d", &num) != 1) return 0;

    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
