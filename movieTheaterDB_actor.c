#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Movie_Actors {
    int actor_Code;
    char actor_Name[51];
    int actor_Age;
    char actor_IMDB[51];
};

struct Movie_Actors actors[100];
int actor_Count = 0;

void insertActor(){
    if (actor_Count >= 50) {
        printf("Actors cannot be added due to the Database being full.\n");
        return;
    }


    struct Movie_Actors new_Actor;
    printf("        Enter actor code: ");
    scanf("%d", &new_Actor.actor_Code);
    getchar();

    for (int i = 0; i < actor_Count; i++){
        if (actors[i].actor_Code == new_Actor.actor_Code){
            printf("Actor already exists in database/\n");
            return;
        }
    }


    printf("        Enter actor's name: ");
    fgets(new_Actor.actor_Name, sizeof(new_Actor.actor_Name), stdin);
    new_Actor.actor_Name[strcspn(new_Actor.actor_Name, "\n")] = 0;



    while(1){
        printf("        Enter actor's age: ");
        scanf("%d", &new_Actor.actor_Age);
        getchar();

        if(new_Actor.actor_Age < 0 || new_Actor.actor_Age > 120){
            printf("Invalid input for age, Please try again. \n");
        }
        else{
            break;
        }

    }
    

    printf("        Enter actor's IMBD profile page: ");
    fgets(new_Actor.actor_IMDB, sizeof(new_Actor.actor_IMDB), stdin);
    new_Actor.actor_IMDB[strcspn(new_Actor.actor_IMDB, "\n")] = 0;

    actors[actor_Count++] = new_Actor;
}



void searchActor(){
    int actor_Code;
    printf("        Enter actor's code: ");
    scanf("%d", &actor_Code);
    getchar();

    for (int i = 0; i < actor_Count; i++) { 
        if (actors[i].actor_Code == actor_Code) {
            printf("Actor Code  Actor Name            Actor Age            Actor IMDB\n");
            printf("%-12d", actors[i].actor_Code);   
            printf("%-30s", actors[i].actor_Name);
            printf("%-12d", actors[i].actor_Age);
            printf("%-30s\n", actors[i].actor_IMDB);

            return;
        }
    }
    printf("Actor code %d is not in the database.\n", actor_Code);

}

void updateActor(){
    int actor_Code;
    printf("        Enter actor code: ");
    scanf("%d", &actor_Code);
    getchar();

    for(int i = 0; i < actor_Count; i++){
        if (actors[i].actor_Code == actor_Code){
            printf("        Enter actor's name: ");
            fgets(actors[i].actor_Name, sizeof(actors[i].actor_Name), stdin); //reading user input while also seeing if it can handle spaces.
            actors[i].actor_Name[strcspn(actors[i].actor_Name, "\n")] = 0;

            while(1){
                printf("        Enter actor's age: ");
                scanf("%d", &actors[i].actor_Age);
                getchar();

                if(actors[i].actor_Age < 0 || actors[i].actor_Age > 120){
                    printf("\nInvalid input for age, Please try again. \n");
                }
                else{
                    break;
                }

            }

            printf("        Enter actor's IMBD profile page: ");
            fgets(actors[i].actor_IMDB, sizeof(actors[i].actor_IMDB), stdin); //reading user input while also seeing if it can handle spaces.
            actors[i].actor_IMDB[strcspn(actors[i].actor_IMDB, "\n")] = 0;


        }
        else{
            printf("Actor code %d is not in the database.\n", actor_Code);
        }
    
    }
    
}

void print_actor_List(){
    printf("Actor Code  Actor Name            Actor Age            Actor IMDB\n");
    for (int i = 0; i < actor_Count; i++) {
        printf("%-12d", actors[i].actor_Code);   
        printf("%-30s", actors[i].actor_Name);
        printf("%-12d", actors[i].actor_Age);
        printf("%-30s\n", actors[i].actor_IMDB);
    }
}


void eraseActor() {
    int actor_Code;
    printf("        Enter actor's code to delete them from database: ");
    scanf("%d", &actor_Code);
    getchar();

    for (int i = 0; i < actor_Count; ++i) {
        if (actors[i].actor_Code == actor_Code) {
            actors[i] = actors[actor_Count - 1];
            actor_Count--;
            printf("Actor has been deleted from database.\n");
            return;
        }
    }
    printf("Actor code %d not in the database.\n", actor_Code);
}






            
        
    







    
    

    






    


    
