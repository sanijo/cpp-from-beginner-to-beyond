#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    //Define tipe Direction
    enum Direction
    {
        left, right, up, down
    };

    Direction heading {left};

    switch (heading)
    {
        case left:
            cout << "\nGoing left.";
            break;
        case right:
            cout << "\nGoing right.";
            break;
        default:
            cout << "\nOK";
    }
    
    return 0;
}
