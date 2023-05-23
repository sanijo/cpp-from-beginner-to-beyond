#include<iostream>
#include<vector>
#include "header.h"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

int main()
{
    cout << boolalpha << endl;
    Mystring larry("Larry");
//    Mystring moe("Moe");

    auto a = larry;
    a.display();



//    Mystring stooge = larry;
//    larry.display();
//    moe.display();
//
//    cout << (larry == moe) << endl;
//    cout << (larry == stooge) << endl;
//
//    Mystring larry2 = -larry;
//    larry2.display();
//
//    Mystring stooges = larry + "banana";
//    stooges.display();

    return 0;
}
