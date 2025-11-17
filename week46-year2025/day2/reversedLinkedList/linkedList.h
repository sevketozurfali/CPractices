//
// Created by so on 13.11.2025.
//

#ifndef REVERSEDLINKEDLIST_LINKEDLIST_H
#define REVERSEDLINKEDLIST_LINKEDLIST_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node;

void addToEnd(Node*, const int data);

void printList(Node* fnode);

Node* reverseList(Node*);
#endif //REVERSEDLINKEDLIST_LINKEDLIST_H