#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

static struct tm * p;



typedef struct Date {

}Date;

typedef struct note {
    char *note;
    int id;
    struct tm*
}Note, *NOTE;



int add_new_note() {

}

void get_date(struct tm*) {

}



void print_menu(void) {
    int option = 0;

    printf(
     "1 - Add New Note\n"
           "2 - List Notes\n"
           "3 - Remove a Note\n"
           "4 - Exit\n");
    printf("Please select an option from menu : ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Selected 1\n");

            break;
        case 2:
            printf("Selected 2\n");
            break;
        case 3:
            printf("Selected 3\n");
            break;
        case 4:
            exit(EXIT_SUCCESS);
        default :
            printf("Out of scope!\n");
            break;
    }
}

int main(void) {


    print_menu();



    return 0;
}