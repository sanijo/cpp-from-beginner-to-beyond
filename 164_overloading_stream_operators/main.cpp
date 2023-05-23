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
    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    Mystring curly;

    cout << "Enter the third stooge's first name: ";
    cin >> curly;

    cout << "Three stooges are " << larry << ", " << moe << " and " 
         << curly << endl;

    cout << "\nEnter the three stooges names separated by a space: ";
    cin >> larry >> moe >> curly;

    cout << "Three stooges are " << larry << ", " << moe << " and " 
         << curly << endl;

    return 0;
}
