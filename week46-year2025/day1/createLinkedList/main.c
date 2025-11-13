#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

int main(void) {
    printf("Hello, World!\n");

    Node *node = (Node*) malloc(sizeof(Node));
    node->data = 12;

    node->next = NULL;
    addToEnd(node, 5);
    addToEnd(node, 20);
    addToEnd(node, 10);

    printList(node);


    free(node);
    return 0;
}