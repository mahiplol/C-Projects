#ifndef movieTheaterDB_actor_H
#define movieTheaterDB_actor_H




struct Movie_Actors 
{
    int actor_Code;
    char actor_Name[51];
    int actor_Age;
    char actor_IMDB[51];
};

void insertActor();
void searchActor();
void updateActor();
void print_actor_List();
void eraseActor();

#endif