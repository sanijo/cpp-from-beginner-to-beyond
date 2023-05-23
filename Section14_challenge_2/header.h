#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include<iostream>

class Mystring
{
/********************SOLUTION**************************************************/    
    //Make lowercase
    friend Mystring operator-(const Mystring &obj);
    //Equality
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    //Not equal
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);
    //lhs less then rhs
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);
    //lhs greater then rhs
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);
    //Concatenation
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
    //Concatenation2
    friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);
    //Repeat
    friend Mystring operator*(const Mystring &lhs, int rhs);
    //Repeat2
    friend Mystring &operator*=(Mystring &lhs, int rhs);
    //preincrement
    friend Mystring &operator++(Mystring &lhs);
    //postincrement
    friend Mystring operator++(Mystring &lhs, int);
/********************SOLUTION*************************************************/    

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

};

#endif // _MYSTRING_H_
