#include<iostream>
#include "Movies.h"

//Functions prototipes
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, int watched);

//Functions definitions
void increment_watched(Movies &movies, std::string name)
{
    if (movies.increment_watched(name))
    {
        std::cout << name << " watch incremented." << std::endl;
    }
    else
    {
        std::cout << name << " not found." << std::endl;
    }
}

void add_movie(Movies &movies, std::string name, std::string rating, int watched)
{
    if (movies.add_movie(name, rating, watched))
    {
        std::cout << name << " added." << std::endl;
    }
    else
    {
        std::cout << name << " allready exist." << std::endl;
    }
}

int main()
{
    Movies my_movies;
    add_movie(my_movies, "Jack Reacher", "ACTION", 2);
    add_movie(my_movies, "Batman", "ACTION", 1);
    add_movie(my_movies, "Interstellar", "Sci-Fi", 1);

    my_movies.display();
    
    return 0;
}
