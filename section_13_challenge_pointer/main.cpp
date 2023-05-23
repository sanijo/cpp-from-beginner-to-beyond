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
    std::vector<Movie> m1;
    Movies my_movies_1(m1);
    add_movie(my_movies_1, "Jack Reacher", "ACTION", 2);
    add_movie(my_movies_1, "Batman", "ACTION", 1);
    add_movie(my_movies_1, "Interstellar", "Sci-Fi", 1);

    std::vector<Movie> m2;
    Movies my_movies_2(m2);
    add_movie(my_movies_2, "Warzone", "ACTION", 2);
    add_movie(my_movies_2, "Mac Max", "ACTION", 5);
    add_movie(my_movies_2, "Star Wars", "Sci-Fi", 3);

    std::vector<Movies> movies_files;
    movies_files.push_back(my_movies_1);
    movies_files.push_back(my_movies_2);

    for (auto &item: movies_files)
    {
        item.display();
    }
    
    return 0;
}
