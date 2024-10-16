#include <stdio.h>
#include <string.h>

#include "movieTheaterDB_movie.h"
#include "movieTheaterDB_actor.h"
#include "movieTheaterDB.h"


void commands_Movies(){

    int user_Input;
    

    while(1){
        printf("*********************\n");
        printf("* Movie Database     *\n");
        printf("*********************\n");
        
        printf("To Insert a movie, type 1\n");
        printf("To Search a movie, type 2\n");
        printf("To Update a movie, type 3\n");
        printf("To Print the movie list, type 4\n");
        printf("To Erase a movie, type 5\n");
        printf("To quit the movie database, type 0\n");

        scanf("%d", &user_Input);

        if(user_Input == 1){
            insertMovie();
        }
        else if (user_Input == 2)
        {
            searchMovie();
        }
        else if (user_Input == 3)
        {
            updateMovie();
        }
        else if (user_Input == 4)
        {
            print_movie_List();
        }
        else if (user_Input == 5)
        {
            eraseMovie();
        }
        else if (user_Input == 0)
        {
            break;
        }
        else{
            printf("Invalid Input. Please try again!\n");
        }
    }
}



void commands_Actors(){

    int user_Input;
    while(1){
        printf("*********************\n");
        printf("* Actor Database     *\n");
        printf("*********************\n");
        
        printf("To Insert an actor, type 1\n");
        printf("To Search an actor, type 2\n");
        printf("To Update an actor, type 3\n");
        printf("To Print the actor list, type 4\n");
        printf("To Erase an actor, type 5\n");
        printf("To quit the actor database, type 0\n");

        scanf("%d", &user_Input);

        if(user_Input == 1){
            insertActor();
        }
        else if (user_Input == 2)
        {
            searchActor();
        }
        else if (user_Input == 3)
        {
            updateActor();
        }
        else if (user_Input == 4)
        {
            print_actor_List();
        }
        else if (user_Input == 5)
        {
            eraseActor();
        }
        else if (user_Input == 0){
            break;
        }
        else{
            printf("Invalid Input. Please try again!\n");
        }
    }
}


int main(){

    int user_Input;
    

    printf("$ ./movieTheaterDB\n");
    printf("*********************\n");
    printf("* 2211 Movie Cinema *\n");
    printf("*********************\n");


    while(1){
        printf("Please choose one of the following options:\n");
        printf("To access the Movie Database, type 1\n");
        printf("To access the Actor Database, type 2\n");
        printf("To quit the Database, type 0\n");
        
        scanf("%d", &user_Input);
        
        if(user_Input == 0){
            break;  
        }

        else if(user_Input == 1){
            commands_Movies();  
        }
        else if(user_Input == 2){
            commands_Actors();
        }
        else{
            printf("Invalid Input. Please try again!\n");
        }
    }
}
    
    

