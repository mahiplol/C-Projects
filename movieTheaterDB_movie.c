#include <stdio.h>
#include <string.h>

struct Movie_Cinema { //creating structure Movie_Cinema 
    int movie_Code; //initializing code for movies
    char movie_Name[101]; //initializing names for movies
    char movie_Genre[26]; //initializing genre for movies
    float movie_Rating; //initializing rating for movies
};

struct Movie_Cinema movies[100]; //creating array that stores movies
int movie_Count = 0; //Creating a counter 

void insertMovie() { // creating function to Insert a new movie (using command i)
    if (movie_Count >= 100) { // if counter > 100 then:
        printf("Movie cannot be added due to the Database being full.\n"); //as we have only 100 possible movies that are shown in the theater.
        return;
    }

    struct Movie_Cinema new_Movie; //creating object new_Movie using the structure Movie_Cinema created.
    printf("        Enter movie code: ");
    scanf("%d", &new_Movie.movie_Code); //scanning user input for movie code
    getchar();

    for (int i = 0; i < movie_Count; i++) { //iterating through the database to find the inputted movie.
        if (movies[i].movie_Code == new_Movie.movie_Code) {
            printf("Movie already exists.\n");
            return; //checking if userinput exists in database.
        }
    }

    printf("        Enter movie name: ");
    fgets(new_Movie.movie_Name, sizeof(new_Movie.movie_Name), stdin); //getting user input for movie name using fgets.
    new_Movie.movie_Name[strcspn(new_Movie.movie_Name, "\n")] = 0; 

    printf("        Enter movie genre: ");
    fgets(new_Movie.movie_Genre, sizeof(new_Movie.movie_Genre), stdin); //getting user input for movie genre using fgets.
    new_Movie.movie_Genre[strcspn(new_Movie.movie_Genre, "\n")] = 0;

    while (1) { //using while(1) to get user to input a valid rating b/w 0.0 and 10.0
        printf("        Enter movie rating: "); //getting user input for movie rating using scanf.
        scanf("%f", &new_Movie.movie_Rating);
        getchar();

        if (new_Movie.movie_Rating < 0.0 || new_Movie.movie_Rating > 10.0) { //condition for invalid input for rating by user.
            printf("\nInvalid input for rating. Please try again!\n");
        } else {
            break;
        }
    }

    movies[movie_Count++] = new_Movie; //incrementing the counter and adding the inputted movie to database
}

void searchMovie() { // creating function to Search for a movie in the database and print it out (using command s)
    int movie_Code;
    printf("        Enter movie code: "); 
    scanf("%d", &movie_Code); //getting user input for movie code.
    getchar();

    for (int i = 0; i < movie_Count; i++) { //iterating through the database to find the inputted movie.
        if (movies[i].movie_Code == movie_Code) {
            printf("Movie Code   Movie Name                      Movie Genre               Movie Rating\n");
            printf("%-12d", movies[i].movie_Code);   //printing all the details(code,name,genre and rating) for the inputted movie.
            printf("%-30s", movies[i].movie_Name);
            printf("%-25s", movies[i].movie_Genre);
            printf("%.1f\n", movies[i].movie_Rating);

            return;
        }
    }
    printf("Movie code %d is not in the database.\n", movie_Code); //ekse printing that movie inputted does not exist in the database.
}

void updateMovie() { // creating a function to Update a movie in the database (using command u)
    int movie_Code;
    printf("        Enter movie code: "); //getting user input for movie code
    scanf("%d", &movie_Code);
    getchar();

    for (int i = 0; i < movie_Count; i++) { //iterating through the database to find the inputted movie.
        if (movies[i].movie_Code == movie_Code) { 
            //updating all the details(code,name,genre and rating) for inputted movie
            printf("        Enter movie name: "); //user inputting movie name
            fgets(movies[i].movie_Name, sizeof(movies[i].movie_Name), stdin); //reading user input while also seeing if it can handle spaces.
            movies[i].movie_Name[strcspn(movies[i].movie_Name, "\n")] = 0;

            printf("        Enter movie genre: "); //user inputting movie genre
            fgets(movies[i].movie_Genre, sizeof(movies[i].movie_Genre), stdin);
            movies[i].movie_Genre[strcspn(movies[i].movie_Genre, "\n")] = 0;

            while (1) {
                printf("        Enter movie rating: "); //getting the valid rating input from user.
                scanf("%f", &movies[i].movie_Rating);
                getchar();

                if (movies[i].movie_Rating < 0.0 || movies[i].movie_Rating > 10.0) {
                    printf("\nInvalid input for rating. Please try again!\n");
                } else {
                    
                    return;
                }
            }
        }
    }
    printf("Movie code %d is not in the database.\n", movie_Code); //if movie code inputted is not valid, its not in database.
}

void print_movie_List() { // creating a function to Print the entire list of movies (using command p).
    printf("Movie Code   Movie Name                      Movie Genre               Movie Rating\n");
    for (int i = 0; i < movie_Count; i++) {
        printf("%-12d", movies[i].movie_Code); //printing all details of movie in a formatted manner. (12 characters for code)
        printf("%-30s", movies[i].movie_Name); //(30 characters for name)
        printf("%-25s", movies[i].movie_Genre); //(25 characters for genre)
        printf("%.1f\n", movies[i].movie_Rating); //(1 decimal point after the rating)
    }
}

void eraseMovie() {
    int movie_Code;
    printf("        Enter movies code to delete it from database: ");
    scanf("%d", &movie_Code);
    getchar();

    for (int i = 0; i < movie_Count; ++i) {
        if (movies[i].movie_Code == movie_Code) {
            movies[i] = movies[movie_Count - 1];
            movie_Count--;
            printf("Movie has been deleted from database.\n");
            return;
        }
    }
    printf("Movie code %d not in the database.\n", movie_Code);
}


