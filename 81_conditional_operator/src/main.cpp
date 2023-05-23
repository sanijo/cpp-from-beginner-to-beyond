#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num {};

    cout << "\nEnter an intefer: ";
    cin >> num;

    if (num % 2 == 0)
        cout << num << " is even";
    else
        cout << num << " is odd";

    cout << "\n" << num << " is " << ((num % 2 == 0) ? "even" : "odd");

    //for (int i {1}; i<=15; i++)
    //{
    //    if (i % 2 != 0)
    //        num += i;
    //    cout <<  num <<endl;
    //}
    
    return 0;
}
