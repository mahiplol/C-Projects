#ifndef movieTheaterDB_movie_H
#define movieTheaterDB_movie_H


struct Movie_Cinema { //creating structure Movie_Cinema 
    int movie_Code; //initializing code for movies
    char movie_Name[101]; //initializing names for movies
    char movie_Genre[26]; //initializing genre for movies
    float movie_Rating; //initializing rating for movies
};


void insertMovie();
void searchMovie();
void updateMovie();
void print_movie_List();
void eraseMovie();


#endif

