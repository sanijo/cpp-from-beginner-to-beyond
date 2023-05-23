#include<iostream>
#include "header.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Mystring empty; //no args constructor
    Mystring larry("Larry"); //overloaded constructor
    Mystring stooge(larry); //copy constructor

    empty.display();
    larry.display();
    stooge.display();
    
    return 0;
}
