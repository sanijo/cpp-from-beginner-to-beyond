#include "Movies.h"


//Constructor
Movies::Movies(std::vector<Movie> m)
{
    movies = new std::vector<Movie>;
    *movies = m;
    std::cout << "Constructor called" << std::endl;
}
//Deep copy constructor
Movies::Movies(const Movies &source):Movies{*source.movies}
{
    std::cout << "Copy constructor - deep" << std::endl;
}
//Move constructor
Movies::Movies(Movies &&source) noexcept:movies{source.movies}
{
    source.movies = nullptr;
    std::cout << "Move constructor moving resources" << std::endl;
}
//Destructor
Movies::~Movies()
{
    if (movies != nullptr)
    {
        std::cout << "Destructor freeing data for object" << std::endl;
    }
    else
    {
        std::cout << "Destructor freeing data for nullptr" << std::endl;
    }
    delete movies;
}

//search the movies vector return true if a movie obj doesn't exist
//return false if movie obj allready exist
bool Movies::add_movie(std::string name, std::string rating, int watched)
{
    for (const auto &movie: *movies)
    {
        if (movie.get_name() == name)
            return false;
    }
    Movie temp {name, rating, watched};
    movies->push_back(temp);
    return true;
}

//returns true if movie object exist if not returns false
bool Movies::increment_watched(std::string name)
{
    for (auto &movie: *movies)
    {
        if (movie.get_name() == name)
        {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const
{
    if (movies->size() == 0)
    {
        std::cout << "\nSorry, no movies to display" << std::endl;
    }
    else
    {
        std::cout << "\n========================" << std::endl;
        for (const auto &movie: *movies)
        {
            movie.display();
        }
        std::cout << "\n========================" << std::endl;
    }
}
