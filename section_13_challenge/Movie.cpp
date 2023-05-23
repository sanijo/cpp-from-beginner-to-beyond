#include "Movie.h"


//constructor
Movie::Movie(std::string name, std::string rating, int watched)
    :name{name}, rating{rating}, watched{watched}{}

//Copy constructor
Movie::Movie(const Movie &source)
    :Movie{source.name, source.rating, source.watched}{}

//Destructor
Movie::~Movie(){}

//Basic setters and getters
void Movie::set_name(std::string name)
{
    this->name=name;
}
std::string Movie::get_name() const
{
    return name;
}

void Movie::set_rating(std::string rating)
{
    this->rating=rating;
}
std::string Movie::get_rating() const
{
    return rating;
}

void Movie::set_watched(int watched)
{
    this->watched=watched;
}
int Movie::get_watched() const
{
    return watched;
}

void Movie::increment_watched()
{
    ++watched;
}

void Movie::display() const
{
    std::cout << name << " " << rating << " " << watched << std::endl;
}
