#ifndef movieTheaterDB_H
#define movieTheaterDB_H

#include "movieTheaterDB_movie.h"
#include "movieTheaterDB_actor.h"

void commands_Movies();
void commands_Actors();

void insertActor();
void searchActor();
void updateActor();
void print_actor_List();
void eraseActor();
void insertMovie();
void searchMovie();
void updateMovie();
void print_movie_List();
void eraseMovie();

#endif