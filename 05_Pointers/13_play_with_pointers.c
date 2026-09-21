#include <stdio.h>

int main() {
    int age = 25;
    int *ptr = &age;

    printf("Value of age : %d\n", age);
    printf("Address of age : %p\n", (void*)ptr);
    printf("Value using pointer : %d\n", *ptr);

    return 0;
}
