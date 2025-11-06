#include "mission.h"


HMission create_mission_list_with_cap(){
    HMission *hmission = malloc(DEF_SIZE * sizeof(Mission));

    if(!hmission){
        fprintf(stderr, "Couldn't malloc!\n");
        return 1;
    }

    printf("Success\n");
    
}