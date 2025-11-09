#ifndef TODO_MISSION_H
#define TODO_MISSION_H


#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>


#define DEF_SIZE 20
#define TITLE_SIZE 512


typedef struct mission
{
    int id;
    char title[TITLE_SIZE];
    int completed;
}mission;

typedef struct tagMission
{
    mission *mis;
    size_t cap;
    size_t size;
}Mission, *HMission;

enum isCompleted {
    completed = 0,
    not_completed = 1,
};

#define get_size(hmission)      ((hmission)->size)

HMission create_mission_list_with_default_cap(size_t cap);
HMission create_mission_list(void);
bool set_capacity(HMission);

// void insert(HMission, const mission *mis, size_t index);
void pop(HMission);
HMission push_back(HMission, mission *mis);
void delete(HMission, const mission *mis);

void print_mission_list(HMission);
void print_mission(const mission *mis);

bool mark_mission_as_completed(HMission, const mission *mis);
void destroy_mission_list(HMission);


#endif