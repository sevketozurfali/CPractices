#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define  SIZE 10

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

double calculate_average(const int *arr, const size_t size) {
    int total = 0;
    for (size_t i = 0; i < size; ++i) {
        total += arr[i];
    }

    return (double)total / (double)size;
}

double standard_deviation(const int* arr, const double* average, const size_t size) {

    double total = 0;
    for (size_t i = 0; i < size; ++i) {
        const double tmp = pow((arr[i] - *average), 2);
        total += tmp;
    }

    const double variant = total / (double)size;
    return sqrt(variant);
}


int main(void) {
    printf("Hello, World!\n");

    int digit;
    int avg[SIZE];
    printf("Please enter a digit : ");
    scanf("%d", &digit);

    generate_random_array(avg, &digit, SIZE);
    print_array(avg, SIZE);

    const double average = calculate_average(avg, SIZE);
    printf("%f\n", average);

    const double s_dev = standard_deviation(avg, &average, SIZE);

    printf("standard deviation : %f\n", s_dev);

    return 0;
}