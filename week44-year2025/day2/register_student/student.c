//
// Created by so on 30.10.2025.
//

#include "student.h"


HStudent create_student_list(void) {
    HStudent hst = create_student_list_with_cap(DEFAULT_CAP);
    return hst;
}

HStudent create_student_list_with_cap(size_t cap) {
    HStudent hst = (HStudent)malloc(sizeof(Student));

    if (!hst) {
        fprintf(stderr, "Coudln't malloc on HStudent!\n");
        exit(EXIT_FAILURE);
    }

    hst->cap = DEFAULT_CAP;
    hst->size = 0;
    hst->st = (student*)malloc(cap * sizeof(student));

    if (!hst->st) {
        fprintf(stderr, "Malloc failed. %s\n", __FILE__);
        free(hst);
        return NULL;
    }

    return hst;
}

HStudent set_capacity(HStudent hst, size_t cap) {

    if (cap < hst->cap) {
        fprintf(stderr, "Please increase the cap size.\n");
        return hst;
    }

    student *tmp = (student*)realloc( hst->st, cap * sizeof(student));
    if (!tmp) {
        fprintf(stderr, "Couldn't increased the size of the Student list...\n");
        free(tmp);
        return NULL;
    }

    hst->cap = cap;
    return hst;
}

HStudent push_back(HStudent hst, student *st) {

    if (hst->cap == hst->size) {
        hst = set_capacity(hst, hst->cap*2);
    }

    hst->st[get_size(hst)] = *st;
    hst->size++;

    return hst;
}


void print_all_student(HStudent hst) {

    if (get_size(hst) == 0) {
        fprintf(stderr, "There is no student in here! \n");
    }
    else {
        for (size_t i = 0; i < hst->size; ++i) {
            printf("\n------------------------------------------------\n");
            printf("Name : %s\n", hst->st[i].name);
            printf("Age : %d\n", hst->st[i].age);
            printf("Grade : %2f\n", hst->st[i].grade);
            printf("-------------------------------------------------\n");
        }
    }
}




