#ifndef TODO_MISSION_H
#define TODO_MISSION_H


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>


#define DEF_SIZE 20


typedef struct mission
{
    int id;
    char title[50];
    int completed;
}mission;

typedef struct tagMission
{
    mission *mis;
    size_t cap;
    size_t size;
}Mission, *HMission;


HMission create_mission_list();

HMission create_mission_list_with_cap();




#endif