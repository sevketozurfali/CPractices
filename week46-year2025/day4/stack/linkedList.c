//
// Created by so on 17.11.2025.
//

#include "linkedList.h"

#include <stdbool.h>


void addToEnd(Node* fnode, const int data) {

    Node *tmp = fnode;

    if (tmp != NULL) {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
    }

    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = data;
    tmp->next = new_node;

}

void printList(Node* fnode) {

    Node* tmp = fnode;

    printf("\n-------------------------\n");

    int count = 0;
    while (tmp != NULL) {
        printf("%d. Data : %d\n", count++, tmp->data);
        tmp = tmp->next;
    }
    printf("-------------------------\n");
}

Node* reverseList(Node* node) {

    if (node == NULL || node->next == NULL) {
        return node;
    }

    struct Node* newNode = reverseList(node->next);

    node->next->next = node;
    node->next = NULL;

    return newNode;

}

Node * searchAndDelete(Node *node, int data) {

    if (node == NULL) {
        return node;
    }

    printf("Deleting...\n");

    if (node->data == data) {
        printf("Found \n");
        return node->next;
    }

    bool found_flag = false;
    Node* tmp = node->next;
    Node* prev = node;
    while (tmp->next != NULL) {
        if (tmp->data == data) {
            printf("Found \n");
            prev->next = tmp->next;
            found_flag = true;
            break;
        }
        prev = tmp;
        tmp = tmp->next;
        printf("Test\n");
    }

    if (!found_flag) {
        printf("Not found the member\n");
    }

    return node;

}

void push(Node *node, int value) {

    Node* tmp = node;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    Node* new_node= (Node*)malloc(sizeof(Node));

    new_node->data = value;
    new_node->next = NULL;
    tmp->next = new_node;

}

void pop(Node *node) {

    Node *tmp = node;
    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = NULL;

}

Node * peek(Node *node) {

    Node* tmp = node;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    return tmp;
}