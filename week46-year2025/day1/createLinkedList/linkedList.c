//
// Created by so on 13.11.2025.
//

#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>


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


