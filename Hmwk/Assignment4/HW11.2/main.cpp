/* 
 * File:   main.cpp
 * Author: Hao Huynh
 *
 * Created on October 7, 2015, 5:14 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/**
 * MovieData Structure 
 */
typedef struct MOVIEDATA {
    /*The title of a movie*/
    string title;

    /*The director of a movie*/
    string director;

    /*The year that a movie war released*/
    int yearRel;

    /*The total running time (in minutes)*/
    float runTime;

    /*The movie’s production costs*/
    float prCosts;

    /*The first-year revenues*/
    float fRevens;

} MovieData;

/**
 * This function displays a movie on the console
 * @param movieData
 */
void showMovie(MovieData * movieData) {

    cout << endl << "--------------------------\n";
    cout << "Movie Title: " << movieData->title << endl;
    cout << "Director: " << movieData->director << endl;
    cout << "Year Released: " << movieData->yearRel << endl;
    cout << "Running Time (in minutes): " << movieData->runTime << endl;

    if (movieData->prCosts < movieData->fRevens) {
        cout << "The first year's profit is: " << movieData->fRevens - movieData->prCosts << endl;
    } else {
        cout << "The first year's loss is: " << movieData->prCosts - movieData->fRevens << endl;
    }

    cout << "--------------------------" << endl;
}

/*
 * Movie Profit
 * Modify the Movie Data program written for Programming Challenge 1 to include two
 * additional members that hold the movie’s production costs and first-year revenues.
 * Modify the function that displays the movie data to display the title, director, release
 * year, running time, and first year’s profit or loss. 
 */
int main(int argc, char** argv) {

    MovieData* firstMovie = new MovieData;
    MovieData* secondMovie = new MovieData;

    firstMovie->title = "Test1T";
    firstMovie->director = "Test1D";
    firstMovie->yearRel = 2015;
    firstMovie->runTime = 120;
    firstMovie->prCosts = 10000;
    firstMovie->fRevens = 50000;
    
    secondMovie->title = "Test2T";
    secondMovie->director = "Test2D";
    secondMovie->yearRel = 2014;
    secondMovie->runTime = 180;
    secondMovie->prCosts = 20000;
    secondMovie->fRevens = 10000;
    
    showMovie(firstMovie);
    showMovie(secondMovie);


    return 0;
}

