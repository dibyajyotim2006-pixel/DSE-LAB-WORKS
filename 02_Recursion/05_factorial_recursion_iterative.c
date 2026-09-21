#include <stdio.h>

int factorial_Recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial_Recursive(n - 1);
}

int factorial_Iterative(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    int n;
    printf("Enter a number : ");
    if (scanf("%d", &n) != 1) return 0;

    printf("Factorial using Recursion = %d\n", factorial_Recursive(n));
    printf("Factorial using Iteration = %d\n", factorial_Iterative(n));

    return 0;
}
