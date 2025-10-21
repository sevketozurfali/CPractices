#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define     SIZE    10

size_t get_min(const int * arr, const size_t size) {

    size_t idx = 0;
    int tmp = INT_MAX;

    for (size_t i = 0; i < size; ++i) {
        if (arr[i] < tmp) {
            tmp = arr[i];
            idx = i;
        }
    }

    return idx;
}

size_t get_max(const int *arr, const size_t size) {
    size_t idx = 0;
    int tmp = INT_MIN;

    for (size_t i = 0; i < size; ++i) {
        if (arr[i] > tmp) {
            tmp = arr[i];
            idx = i;
        }
    }

    return idx;
}

void generate_random_array(int *arr, const int *digit, const size_t size) {

    srand(time(NULL));

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % *digit;
    }
}

void print_array(const int *arr, size_t size) {

    while (size--) {
        printf("%3d ", *arr++);
        if (size % 10 == 0) {
            printf("\n");
        }
    }
}



int main(void) {
    printf("Hello, World!\n");

    int arr[SIZE] = { 0 };
    int val = 0;
    printf("Please enter a number of the digits you want to generate (Range 0 - 1000) : ");
    scanf("%d", &val);


    generate_random_array(arr, &val, SIZE);

    print_array(arr, SIZE);

    const size_t min_idx = get_min(arr, SIZE);

    const size_t max_idx = get_max(arr, SIZE);

    printf("Max : %3d - index : %lu\n", arr[max_idx], max_idx);
    printf("Min : %3d - index : %lu\n", arr[min_idx], min_idx);


    return 0;
}