#include <stdbool.h>
#include <stdio.h>

bool isPrime(const int val) {
    if (val == 1) {
        return true;
    }

    if (val > 2) {
        for (int i = 2; i < val; i++) {
            if (val % i == 0) {
                return false;
            }
        }
        return true;
    }

    else {
        return false;
    }
}



int main(void) {
    printf("Hello, World!\n");


    int value = 0;
    printf("Please enter a value which you would like to learn is it prime or not: ");
    scanf("%d", &value);

    if (isPrime(value)) {
        printf("This is prime!\n");
    }
    else {
        printf("This is not prime\n");
    }


    return 0;
}