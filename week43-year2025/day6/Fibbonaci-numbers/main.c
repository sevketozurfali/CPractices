#include <stdio.h>
#include <stdlib.h>

static int *numbers;
int k = 2;
int n = 0;


void calc_fib_numbers(int num) {
    if (num >= n) {
        return ;
    }
    numbers[num] = numbers[num - 1] + numbers[num - 2];
    calc_fib_numbers(num + 1);

}

void print_fib_numbers(void) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void) {

    printf("Hello, World!\n");
    printf("Please enter a number between 2 and 20 :");
    scanf("%d",&n);


    if (n > 2 && n < 20) {
        numbers = (int*)malloc(n * sizeof(int));

        if (numbers) {
            printf("Allocation success\n");
        }
        else {
            fprintf(stderr, "Couldn't allocated memory\n");
            exit(EXIT_FAILURE);
        }
    }

    numbers[0] = 0;
    numbers[1] = 1;

    calc_fib_numbers(k);
    print_fib_numbers();

    free(numbers);


    return 0;
}