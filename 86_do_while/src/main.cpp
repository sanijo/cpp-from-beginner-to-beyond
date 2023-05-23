#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    char selection {};

    do
    {
        cout << "\n============================" << endl;
        cout << "1. Do this." << endl;
        cout << "2. Do that." << endl;
        cout << "3. Do something else." << endl;
        cout << "Q. Do Quit." << endl;
        cout << "\nEnter your selection: ";
        cin >> selection;
        
        switch (selection)
        {
            case '1':
                cout << "Option 1: copy" << endl;
                break;
            case '2':
                cout << "Option 2: paste" << endl;
                break;
            case '3':
                cout << "Option 1: merge" << endl;
                break;
            case 'q':
            case 'Q':
                cout << "Closing loop. Goodbye!" << endl;
                break;
            default:
                cout << "Sorry not a valid option!" << endl;
                break;
        }
    }
    while (selection != 'q' && selection != 'Q');
    
    return 0;
}
