#ifndef _MOVIES_H_
#define _MOVIES_H_

#include<vector>
#include<string>
#include "Movie.h"

class Movies
{
private:
    std::vector<Movie> movies;
public:
    //Constructor
    Movies();
    //Destructor
    ~Movies();

    //search the movies vector return true if a movie obj doesn't exist
    //return false if movie obj allready exist
    bool add_movie(std::string name, std::string rating, int watched);

    //returns true if movie object exist if not returns false
    bool increment_watched(std::string name);

    void display() const;

};

#endif // _MOVIES_H_
