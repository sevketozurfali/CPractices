#include "mission.h"

#include <time.h>


HMission create_mission_list_with_cap(size_t cap){
    HMission hmission = (HMission)malloc(sizeof(Mission));

    if(!hmission){
        fprintf(stderr, "Couldn't create dynamic memory for HMission!\n");
        return NULL;
    }

    hmission->cap = cap;
    hmission->size = 0;

    hmission->mis = (mission*)malloc(cap * sizeof(mission));

    if (!hmission->mis) {
        fprintf(stderr, "Couldn't create malloc space for mission!\n");
        return NULL;
    }

    return hmission;
}

HMission create_mission_list(void) {
    return create_mission_list_with_cap(DEF_SIZE);
}

bool set_capacity(HMission hmission) {

    size_t new_cap = hmission->cap * 2;
    mission *tmp = (mission*)realloc(hmission->mis, new_cap * sizeof(mission));

    if (!tmp) {
        fprintf(stderr, "Couldn't reallocate memory of the mission list\n");
        return false;
    }

    hmission->mis = tmp;
    hmission->cap = new_cap;

    return true;
}

// void insert(HMission hmission, const mission *mis, size_t index) {
// }

void pop(HMission hmission) {
    size_t current_size = hmission->size;
    hmission->size = current_size - 1;
}

HMission push_back(HMission hmission, mission *mis) {

    if (hmission->size >= hmission->cap) {
        if (!set_capacity(hmission)) {
            fprintf(stderr, "Couldn't added new mission!\n");
            return hmission;
        }
    }

    hmission->mis[get_size(hmission)] = *mis;
    hmission->size = get_size(hmission) + 1;
    return hmission;
}

void delete(HMission hmission, const mission *mis) {
    for (size_t i = 0; i < get_size(hmission); ++i) {
        if (hmission->mis[i].id == mis->id) {
            for (size_t k = i; k < get_size(hmission) - 1; ++k) {
                hmission->mis[k] = hmission->mis[k + 1];
            }
            hmission->size = get_size(hmission) - 1;
        }
    }
}

void print_mission_list(HMission hmission) {

    if (hmission->size > 0) {
        for (size_t i = 0; i < get_size(hmission); ++i) {
            print_mission(&hmission->mis[i]);
        }
    }
    else {
        printf("No Mission in here!\n");
    }

}

void print_mission(const mission *mis) {
    printf("------------------------------------------------------------------\n");
    printf("Title      : %s\n", mis->title);
    printf("Mission ID : #%d\n", mis->id);
    printf("Status     : %s\n",
           mis->completed == completed ? "Completed" : "Not Completed");
    printf("------------------------------------------------------------------\n\n");
}

bool mark_mission_as_completed(HMission hmission, const mission *mis) {

    for (size_t i = 0; i < get_size(hmission); ++i) {
        if (hmission->mis[i].id == mis->id) {
            hmission->mis[i].completed = completed;
            return true;
        }
    }
    return false;
}

void destroy_mission_list(HMission hmission) {

    if (hmission->mis) {
        free(hmission->mis);
    }

    free(hmission);

}















