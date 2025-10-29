#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#define NOTE_SIZE   1024
#define NOTE_COUNT  4096

static const char* mmon[13] = {
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
};

static const char* mdays[7] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
};


typedef struct Date {
    char mday[16];
    int day;
    char mmon[16];
    int year;
}Date;

typedef struct note {
    char note[NOTE_SIZE];
    int id;
    Date date;
}Note;

static Note notes[NOTE_COUNT];
static int current_note_count = 0;

void sgets(char* ch) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        *ch++ = (char)c;
    }

    *ch = '\0';
}

void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


FILE * initialize(void) {

    static FILE* file;
    file = fopen("notes.txt", "a+");
    if (!file) {
        fprintf(stderr, "Couldn't create the file.\n");
        exit(EXIT_FAILURE);
    }
    return file;
}

void print_note(Note *note) {
    printf("%d \t %d %s %d - %s \t %s\n",note->id, note->date.day, note->date.mmon, note->date.year, note->date.mday, note->note);
}

void set_date(Date *date) {
    time_t timer = time(NULL);
    struct tm * now = localtime(&timer);

    strcpy(date->mday, mdays[now->tm_wday]);
    date->day = now->tm_mday;
    date->year = now->tm_year + 1900;
    strcpy(date->mmon, mmon[now->tm_mon]);
}

int add_note(FILE *file, Note *note) {
    fprintf(file, "%d \t %d %s %d - %s \t %s\n",note->id, note->date.day, note->date.mmon, note->date.year, note->date.mday, note->note);
    fflush(file);
}

void set_note(Note *note) {
    printf("Please enter your note and press 'Enter'\n");
    sgets(note->note);

    srand(time(NULL));
    note->id = (rand() % 8999) + 999;

    set_date(&note->date);
}

Note* read_note(FILE *file, Note *note) {
    fscanf(file, "%d%d%s%d - %s", &note->id, &note->date.day, note->date.mmon, &note->date.year, note->date.mday);
    char * status = fgets(note->note, NOTE_SIZE, file);
    if (status) {
        return note;
    }
    else {
        return NULL;
    }
}

void list_notes(FILE *file) {

    printf("----------------------------------------------------------------------------------------\n");
    if (current_note_count == 0) {
        printf("Note file is empty! \n");
    }
    else {
        for (int i = 0; i < current_note_count; ++i) {
            print_note(&notes[i]);
        }
    }
    printf("----------------------------------------------------------------------------------------\n");
}

void delete_note(FILE *file) {

    rewind(file);
    int note_id = 0;
    bool isFound = false;

    printf("Please enter the note id which you would like to delete : ");
    scanf("%d", &note_id);

    for (int i = 0; i < current_note_count; ++i) {
        if (notes[i].id == note_id) {
            isFound = true;
            printf("Found and deleting...\n");
            for (int k = i + 1; k < current_note_count; ++k) {
                notes[i] = notes[k];
                ++i;
            }
            --current_note_count;
            break;
        }
    }

    if (!isFound){
        printf("Can't find the note. Please try again!\n");
    }

    while ((note_id = getchar()) != '\n' && note_id != EOF);

    fclose(file);
    file = fopen("notes.txt", "w");
    fclose(file);
    file = initialize();

    for (int i = 0; i < current_note_count; ++i) {
        add_note(file, &notes[i]);
    }
}


int main(void) {

    FILE *file = initialize();

    Note r_note;
    while (read_note(file,&r_note) != NULL) {
        notes[current_note_count] = r_note;
        ++current_note_count;
    }


    int option = 0;
    while (option != 4) {
        printf(
         "1 - Add New Note\n"
               "2 - List Notes\n"
               "3 - Remove a Note\n"
               "4 - Exit\n");
        printf("Please select an option from menu : ");
        scanf("%d", &option);
        while (getchar() != '\n');

        switch (option) {
            case 1:
                Note new_note;
                set_note(&new_note);
                notes[current_note_count++] = new_note;
                add_note(file, &new_note);
                break;
            case 2:
                list_notes(file);
                break;
            case 3:
                list_notes(file);
                delete_note(file);
                list_notes(file);
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default :
                printf("Out of scope!\n");
                break;
        }

    }

    if (option == 4) {
        fclose(file);
        exit(EXIT_SUCCESS);
    }



    return 0;
}