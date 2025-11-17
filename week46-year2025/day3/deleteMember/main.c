#include <stdio.h>
#include "linkedList.h"

int main(void) {
    printf("Hello, World!\n");

    Node *node = (Node*)malloc(sizeof(Node));

    node->data = 0;
    node->next = NULL;

    // Node *node = NULL;
    addToEnd(node, 1);
    addToEnd(node, 2);
    addToEnd(node, 3);
    addToEnd(node, 4);
    addToEnd(node, 5);
    addToEnd(node, 6);

    printList(node);

    // node = reverseList(node);

    node = searchAndDelete(node, 4);
    node = searchAndDelete(node, 5);
    node = searchAndDelete(node, 1);
    node = searchAndDelete(node, 2);
    node = searchAndDelete(node, 0);


    printList(node);

    return 0;
}









