#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "mission.h"

void clear_buffer (void)
{
    while ( getchar() != '\n' );
}

void sgets(char *ch) {

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        *ch++ = (char)c;
    }

    *ch = '\0';
}

void print_missions(HMission hm) {
    print_mission_list(hm);
}

void append(HMission hmission) {
    printf("Mission :");
    mission mis;
    sgets(mis.title);

    srand(time(NULL));

    mis.id = rand() % 9000;
    mis.completed = not_completed;

    push_back(hmission, &mis);
}

void mark_mission(HMission hm) {
    printf("Please enter id of the task would like to mark as completed :");
    mission m;
    char cid[16];
    sgets(cid);
    m.id = atoi(cid);

    if (!mark_mission_as_completed(hm, &m)) {
        printf("Error Couldn't mark as completed...\n");
    }
    else {
        printf("Done\n");
    }

}

void delete_mission(HMission hm) {

    printf("Please enter the id of would like to delete:");
    mission m;
    char cid[16];
    sgets(cid);
    m.id = atoi(cid);

    delete(hm, &m);
}

int main() {

    HMission hm = create_mission_list();

    while (true){

        printf(
            "1 - Add new mission\n"
            "2 - List all missions\n"
            "3 - Mark the mission as completed\n"
            "4 - Delete mission\n5 - Exit\n"
            );

        int option = 0;
        printf("Please enter an option :");
        scanf("%d", &option);
        clear_buffer();


        switch (option)
        {
        case 1:
            append(hm);
            break;
        case 2:
            print_missions(hm);
            break;
        case 3:
            mark_mission(hm);
            break;
        case 4:
            delete_mission(hm);
            break;
        case 5:
                printf("Exiting...");
                destroy_mission_list(hm);
            exit(EXIT_SUCCESS);
        default:
            break;
        }
    }

    return 0;
}