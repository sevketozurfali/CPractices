#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define EXT_SIZE 15

int* create_dynamic_array(size_t size) {
    int *arr = (int*)malloc(size * sizeof(int));

    if (!arr) {
        fprintf(stderr, "Couldn't create dynamic array!\n");
        free(arr);
        exit(EXIT_FAILURE);
    }
    return arr;
}

void fill_array(int * arr, size_t size) {
    srand(time(NULL));
    for (size_t i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
}

void print_array(int * arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n-----------------------------------\n");
}

int calc_average_array(int *arr, size_t size) {
    int total = 0;
    for (size_t i = 0; i < size; ++i) {
        total += arr[i];
    }

    printf("Total : %d \n", total);
    return total / (int)size;
}

int* add_numbers_to_array(int *arr, size_t new_size) {

    int *tmp = realloc(arr, new_size * sizeof(int));
    if (!tmp) {
        fprintf(stderr, "Couldn't create a memory!\n");
        free(arr);
        exit(EXIT_FAILURE);
    }

    return tmp;
}

int main(void) {
    printf("Hello, World!\n");

    int *arr = create_dynamic_array(SIZE);
    fill_array(arr, SIZE);
    print_array(arr, SIZE);
    printf("Average : %d\n\n", calc_average_array(arr, SIZE));


    arr = add_numbers_to_array(arr, EXT_SIZE);
    fill_array(arr,EXT_SIZE);
    print_array(arr, EXT_SIZE);
    printf("EXT : Average : %d\n ", calc_average_array(arr, EXT_SIZE));

    free(arr);

    return 0;
}