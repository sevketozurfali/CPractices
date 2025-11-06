#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>








int main() {

    int option = 0;

    while (true){
        printf("\
            1 - Add new mission \
            2 - List all missions \
            3 - Mark the mission as completed \
            4 - Delete mission \
            5 - Exit \
        ");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            append(hmission, mission);
            break;
        case 2:
            list_all_missions(hmission);
            break;
        case 3:
            mark_mission(hmission, mission);
            break;
        case 4:
            delete_mission(hmission, mission);
            break;
        case 5:
            exit(EXIT_SUCCESS);
        
        default:
            break;
        }
    }




    return 0;
}