//
// Created by Jimmy Mee on 10/21/19.
//

#ifndef PROJECT3_MOVIES_H
#define PROJECT3_MOVIES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Movies class
class Movies{
private:
    int year;
    int length;
    string title;
    string genre;
    string director;
    string actor;

public:
    //Constructors
    Movies() {
        year = 2019;
        length = 160;
        title = "Once Upon a time in hollywood";
        genre = "drama";
        director = "Quentin Terintino";
        actor = "Leonardo Dicaprio";
    }
    Movies(int year, int length, string title, string genre, string director, string actor){
        this ->title = title;
        this -> genre = genre;
        this -> director = director;
        this -> actor = actor;
        setYear(year);
        setLength(length);


    }
    //Getters
    // const means the method cannot be modified of the class
    string getTitle() const{
        return title;
    }

    string getGenre() const{
        return genre;
    }

    string getDirector() const{
        return director;
    }

    string getActor() const{
        return actor;
    }

    int getYear() const{
        return year;
    }

    int getLength() const{
        return length;
    }

    //Setters
    void setTitle(string title){
        this-> title = title;

    }
    void setGenre(string genre){
        this -> genre = genre;
    }

    void setDirector( string director){
        this -> director = director;
    }

    void setActor(string actor){
        this -> actor = actor;
    }

    void setYear( int year){
        this -> year = year;
    }

    void setLength( int length){
        this -> length = length;
    }

    //overload the << operator to allow us to print a music object
    friend ostream& operator << (ostream& outs, const Movies & movie) {
        outs << setw(10) << movie.getYear() << setw(10) << movie.getLength() << setw(20) <<  movie.getTitle() << setw(20)<< movie.getGenre();
        outs << setw(20) << movie.getDirector() << setw(20) << movie.getActor() << endl;
        return outs;

    }

    // Overload the < operator to compare Lecturers by the length of their names
    // lhs = left hand side; rhs = right hand side (of operator)
    friend bool operator < (const Movies &lhs, const Movies &rhs) {
         return lhs.getTitle() < rhs.getTitle();
     }

    friend bool operator > (const Movies &lhs, const Movies &rhs) {
        return lhs.getTitle() > rhs.getTitle();
    }

    // Overload the == operator to compare Lecturers for equality
    // lhs = left hand side; rhs = right hand side (of operator)
    friend bool operator == (const Movies &lhs, const Movies &rhs) {
        // Compare the unique attribute (in this case, name)
        return lhs.getTitle() == rhs.getTitle();
    }





};
void readMoviesFromFile(string filename, vector<Movies> &movie){
    ifstream fIn;
    //open the movies.csv file from outside the cmake-make-debug folder

    fIn.open(filename);

    //Get rid of header line
    if (fIn) {
        string header = "";
        getline(fIn, header);
    }
    //Loop while there are still rows in the data
    //Stop when you reach the end of the file (EOF)

    while (fIn && fIn.peek() != EOF) {
        string title = "", genre = "", director = "", actor = "";
        int year = -1, length = -1;
        char comma;


        //Read year
        fIn >> year;
        fIn >> comma;

        //Read Length
        fIn >> length;
        fIn >> comma;

        //Read Title (String)
        //getLine for reading Strings
        getline(fIn, title, ',');

        //Read Genre
        getline(fIn, genre, ',');

        //Read actor
        getline(fIn, actor, ',');

        //Read Director
        //Last Column
        getline(fIn, director);


        movie.push_back(Movies(year, length, title, genre, actor, director));

    }
    fIn.close();


}
void testMoviesClass(){
    //test the defeault constructor
    Movies movie;
    //Testing << operator
    cout << movie;
    //Test the non-default constructor
    Movies movie2(2018, 180, "Jimmy", "Comedy", "Clint Eastwood", "James");

    //Testing the < operator
//    cout<< boolalpha << (movie< movie2) << endl;
    //Getters and setter test

}
int calcNewest(vector<Movies> movies){
    //initialize newest movies
    int newestMovie = 0;
    //loop through vector and initilize largest year
    for (Movies& mov : movies){
        if(mov.getYear() > newestMovie){
            newestMovie = mov.getYear();
        }

    }
    return newestMovie;
}


#endif //PROJECT3_MOVIES_H
