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
    Mystring larry("LARRY");
    larry.display();

    larry = -larry;
    larry.display();

    Mystring moe {"Moe"};
    Mystring stooge = larry;

    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;

    Mystring stooges = larry + "banana";
    stooges.display();

    return 0;
}
