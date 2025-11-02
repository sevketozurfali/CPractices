#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sgets(char *ch) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        *ch++ = (char)c;
    }

    *ch = '\0';
}


int main(void) {
    printf("Hello, World!\n");
    printf("Please enter a text :");
    char tmp[100];

    sgets(&tmp);

    int length = strlen(tmp);

    char *text = malloc(length * sizeof(char));

    strcpy(text, tmp);

    printf("Text: %s\n", text);

    free(text);


    return 0;
}
