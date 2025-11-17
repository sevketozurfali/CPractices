//
// Created by so on 13.11.2025.
//

#include "linkedList.h"


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



