//
// Created by so on 17.11.2025.
//

#ifndef DELETEMEMBER_LINKEDLIST_H
#define DELETEMEMBER_LINKEDLIST_H

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

Node* searchAndDelete(Node*, int data);


#endif //DELETEMEMBER_LINKEDLIST_H