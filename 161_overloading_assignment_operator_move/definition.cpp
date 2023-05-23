#include<cstring>
#include<iostream>
#include "header.h"


//No args constructor
Mystring::Mystring():str{nullptr}
{
    str = new char [1];
    *str = '\0';
}
//Overloaded constructor
Mystring::Mystring(const char *s):str{nullptr}
{
    std::cout << "Overloaded constructor used" << std::endl;
    if (s==nullptr)
    {
        str = new char [1];
        *str = '\0';
    }
    else
    {
        str = new char [std::strlen(s)+1];
        std::strcpy(str, s);
    }
}
//Copy constructor
Mystring::Mystring(const Mystring &source):str{nullptr}
{
    std::cout << "Copy constructor used" << std::endl;
    str = new char [std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}
//Move constructor
Mystring::Mystring(Mystring &&source):str(source.str)
{
    source.str = nullptr;
    std::cout << "Move constructor used" << std::endl;
}
//Destructor
Mystring::~Mystring()
{
    if (str == nullptr)
    {
        std::cout << "Calling destructor for: nullptr" << std::endl;
    }
    else
    {
        std::cout << "Calling destructor for: " << str << std::endl;
    }
    delete [] str;
}


//Overloaded operator = copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
    std::cout << "Using copy assignment" << std::endl;
    if (this == &rhs)
    {
        return *this;
    }
    else
    {
        delete [] str;
        str = new char[std::strlen(rhs.str)+1];
        std::strcpy(str, rhs.str);
        return *this;
    }
}
//Overloaded operator = move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
    {
        return *this;
    }
    else
    {
        delete [] str;
        str = rhs.str;
        rhs.str = nullptr;
        return *this;
    }
}

//getters
int Mystring::get_length() const
{
    return std::strlen(str);
}
const char *Mystring::get_str() const
{
    return str;
}

//Display method
void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}


