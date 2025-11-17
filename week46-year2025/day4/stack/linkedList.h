//
// Created by so on 17.11.2025.
//

#ifndef STACK_LINKEDLIST_H
#define STACK_LINKEDLIST_H

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

void push(Node*, int value);

void pop(Node*);

Node* peek(Node*);

#endif //STACK_LINKEDLIST_H