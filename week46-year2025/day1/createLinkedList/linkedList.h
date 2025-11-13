//
// Created by so on 13.11.2025.
//

#ifndef CREATELINKEDLIST_LINKEDLIST_H
#define CREATELINKEDLIST_LINKEDLIST_H

#include <stddef.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

void addToEnd(Node*, const int data);

void printList(Node* fnode);

#endif //CREATELINKEDLIST_LINKEDLIST_H