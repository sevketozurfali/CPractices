#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(const char* word, size_t size) {

    const char* reversed = word + size -1;

    size_t halfed = size/2;

    while (halfed--) {
        if (*reversed-- != *word++) {
            return false;
        }
    }
    return true;
}



int main(void) {
    printf("Hello, World!\n");

    char word[100];
    printf("Please enter a word which you would like to learn is it a Palindrome word? : ");

    scanf("%s", word);

    if (isPalindrome(word, strlen(word))) {
        printf("This is palindrome!\n");
    }
    else {
        printf("This word is not palindrome sorry!\n");
    }


    return 0;
}