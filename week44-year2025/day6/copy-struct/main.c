#include <stdio.h>

#include "student.h"

int main(void) {
    printf("Hello, World!\n");



    HStudent hst;
    hst = create_student_list();

    student st;

    strcpy(st.name, "Yusuf");
    st.age = 35;
    st.grade = 10;

    push_back(hst, &st);

    student st2;

    strcpy(st2.name, "Kerim");
    st2.age = 35;
    st2.grade = 10;

    push_back(hst, &st2);
    student st3;

    strcpy(st3.name, "Hakkı");
    st3.age = 35;
    st3.grade = 20;

    push_back(hst, &st3);

    student st4;

    strcpy(st4.name, "Mert");
    st4.age = 35;
    st4.grade = 30;

    push_back(hst, &st4);

    student st5;

    strcpy(st5.name, "Melih");
    st5.age = 45;
    st5.grade = 40;

    push_back(hst, &st5);

    student st6;

    strcpy(st6.name, "Caglar");
    st6.age = 35;
    st6.grade = 50;

    push_back(hst, &st6);

    printf("Size : %lu \n", get_size(hst));
    printf("CAP : %lu\n", get_cap(hst));

    print_all_student(hst);

    student top_student = findTopStudent(hst);
    printf("Top student name is : %s\n", top_student.name);

    printf("Average of the grades : %2f\n", avrg_grades(hst));

    student latest_student;
    if (copy_student(&latest_student, &hst->st[get_size(hst) - 1])) {
        print_student(&latest_student);
    }


    free(hst->st);
    free(hst);




    return 0;
}
