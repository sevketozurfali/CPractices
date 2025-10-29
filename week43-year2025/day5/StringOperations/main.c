#include <stdio.h>

size_t my_strlen(const char* str) {
    size_t length = 0;
    while (*str++) {
        ++length;
    }
    return length;
}

char* my_strcpy(char* dest, const char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return dest;
}

int my_strcmp(const char* str1, const char* str2) {

    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    return (unsigned char)*str1 - (unsigned char)*str2;
}

int main(void) {
    printf("Hello, World!\n");

    return 0;
}