#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include<iostream>

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment
    
    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;

/********************SOLUTION**************************************************/    
    //Make lowercase
    Mystring operator-() const;
    //Equality
    bool operator==(const Mystring &rhs) const;
    //Not equal
    bool operator!=(const Mystring &rhs) const;
    //lhs less then rhs
    bool operator<(const Mystring &rhs) const;
    //lhs greater then rhs
    bool operator>(const Mystring &rhs) const;
    //Concatenation
    Mystring operator+(const Mystring &rhs) const;
    //Concatenation2
    Mystring &operator+=(const Mystring &rhs);
    //Repeat
    Mystring operator*(int rhs) const;
    //Repeat2
    Mystring &operator*=(int rhs);
    //preincrement
    Mystring &operator++();
    //postincrement
    Mystring operator++(int);
};

#endif // _MYSTRING_H_
