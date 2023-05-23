#include <iostream>
#include <cstring>
#include "header.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

/*********************SOLUTION*************************************************/
//Make lowercase
Mystring operator-(const Mystring &obj)
{
    char *buff = new char[std::strlen(obj.str)+1];
    std::strcpy(buff, obj.str);
    for (size_t i{0}; i<std::strlen(buff); ++i)
    {
        *(buff+i) = std::tolower(*(buff+i));
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}
//Equality
bool operator==(const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str)==0);
}
//Not equal
bool operator!=(const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str)!=0);
}
//lhs less then rhs
bool operator<(const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str)<0);
}
//lhs greater then rhs
bool operator>(const Mystring &lhs, const Mystring &rhs)
{
    return (std::strcmp(lhs.str, rhs.str)>0);
}
//Concatenation
Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
    char *buff = new char[std::strlen(lhs.str)+std::strlen(rhs.str)+1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}
//Concatenation
Mystring &operator+=(Mystring &lhs, const Mystring &rhs)
{
    lhs = lhs + rhs;
    return lhs;
}
//repeat
Mystring operator*(const Mystring &lhs, int rhs)
{
    Mystring temp;
    for (size_t i{0}; i<rhs; ++i)
    {
        temp = temp + lhs;
    }
    return temp;
/*    char *buff = new char[rhs*std::strlen(lhs.str)+1];
    std::strcpy(buff, lhs.str);
    for (size_t i{0}; i<(rhs-1); ++i)
    {
        std::strcat(buff, lhs.str);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
*/
}
//repeat2
Mystring &operator*=(Mystring &lhs, int rhs)
{
    lhs = lhs * rhs;
    return lhs;
}
//Preincrement operator
Mystring &operator++(Mystring &lhs)
{
    char *buff = new char[std::strlen(lhs.str)+1];
    std::strcpy(buff, lhs.str);
    for (size_t i{0}; i<std::strlen(lhs.str); ++i)
    {
        lhs.str[i] = buff[std::strlen(lhs.str)-1-i];
    }
    return lhs;
}
//postincrement
Mystring operator++(Mystring &lhs, int)
{
    Mystring temp{lhs};
    operator++(lhs);
    return temp;
}









