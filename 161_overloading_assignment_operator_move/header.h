#ifndef _HEADER_H_
#define _HEADER_H_

class Mystring
{
private:
    char *str; //holds pointer to a char[]
public:
    //No args constructor
    Mystring();
    //Overloaded constructor
    Mystring(const char *s);
    //Copy constructor
    Mystring(const Mystring &source);
    //Move constructor
    Mystring(Mystring &&source);
    //Destructor
    ~Mystring();

    //Overloaded operator = copy assignment
    Mystring &operator=(const Mystring &rhs);
    //Overloaded operator = move assignment
    Mystring &operator=(Mystring &&rhs);

    //getters
    int get_length() const;
    const char *get_str() const;

    //Display method
    void display() const;


};

#endif // _HEADER_H_
