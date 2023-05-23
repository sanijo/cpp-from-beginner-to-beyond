#include<iostream>
#include<vector>
#include "header.h"

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
   // Mystring a{"Hello"}; //overloaded constructor
   // a = Mystring("Hola"); //Overloaded constructor then move assignment
   // a = "Bonjour"; // Overloaded constructor then move assignment

    vector<Mystring> vec;
    vec.push_back("Joe");
    vec.push_back("Don");
    vec.push_back("Rick");
    vec.push_back("Halid");

    for (auto &v: vec)
        v = "Samson";

   // for (auto const &v: vec)
   //     v.display();

    return 0;
}
