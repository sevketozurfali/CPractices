#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    printf("Hello, World!\n");


    int x = 10;
    int y = 20;

    printf("x : %d - y : %d\n", x, y);
    swap(&x, &y);
    printf("x : %d - y : %d\n", x, y);

    return 0;
}