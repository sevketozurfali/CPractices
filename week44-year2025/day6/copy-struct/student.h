//
// Created by so on 3.11.2025.
//

#ifndef COPY_STRUCT_STUDENT_H
#define COPY_STRUCT_STUDENT_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAP 5

typedef struct student {
    char name[50];
    int age;
    float grade;
}student;

typedef struct tagStudent {
    student *st;
    size_t size;
    size_t cap;
}Student, *HStudent;

#define get_size(hst)   ((hst)->size)
#define get_cap(hst)    ((hst)->cap)

HStudent create_student_list(void);
HStudent create_student_list_with_cap(size_t cap);
HStudent set_capacity(HStudent hst, size_t cap);

HStudent push_back(HStudent hst, student *st);
student findTopStudent(HStudent hst);
float avrg_grades(HStudent hst);
bool copy_student(student *dest_st, const student *src_st);
void print_student(const student *st);



void print_all_student(HStudent hst);


#endif //COPY_STRUCT_STUDENT_H