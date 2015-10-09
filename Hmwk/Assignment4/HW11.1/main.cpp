/* 
 * File:   main.cpp
 * Author: Hao Huynh
 *
 * Created on October 7, 2015, 4:55 PM
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
    cout << "--------------------------" << endl;
}

/*
 * Movie Data
 * This program uses a structure named MovieData to store the following information
 * about a movie:
 *   Title
 *   Director
 *   Year Released
 *   Running Time (in minutes)
 * The program creates two MovieData variables, store values in their members,
 * and pass each one, in turn, to a function that displays the information about the movie
 * in a clearly formatted manner. 
 */
int main(int argc, char** argv) {

    MovieData* firstMovie = new MovieData;
    MovieData* secondMovie = new MovieData;

    firstMovie->title = "Test1T";
    firstMovie->director = "Test1D";
    firstMovie->yearRel = 2015;
    firstMovie->runTime = 120;

    secondMovie->title = "Test2T";
    secondMovie->director = "Test2D";
    secondMovie->yearRel = 2014;
    secondMovie->runTime = 180;

    showMovie(firstMovie);
    showMovie(secondMovie);

    return 0;
}

