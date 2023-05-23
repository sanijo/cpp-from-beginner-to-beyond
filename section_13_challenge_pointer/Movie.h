#ifndef _MOVIE_H_
#define _MOVIE_H_

#include<iostream>
#include<string>

class Movie
{
private:
    std::string name; //name of the movie
    std::string rating; //movie rating A, B, C, D, F
    int watched; //number of times watched
public:
    //constructor
    Movie(std::string name="None", std::string rating="None", int watched=0);

    //Copy constructor
    Movie(const Movie &source);

    //Destructor
    ~Movie();

    //Basic setters and getters
    void set_name(std::string name);
    std::string get_name() const;

    void set_rating(std::string rating);
    std::string get_rating() const;

    void set_watched(int watched);
    int get_watched() const;

    void increment_watched();

    void display() const;

};

#endif // _MOVIE_H_
