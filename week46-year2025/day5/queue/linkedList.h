//
// Created by so on 17.11.2025.
//

#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H


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

void enqueue(Node *, int value);

Node* dequeue(Node *);

#endif //QUEUE_LINKEDLIST_H