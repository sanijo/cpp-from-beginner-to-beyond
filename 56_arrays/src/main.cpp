#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    char vowels [] {'a', 'e', 'i', '0', 'u'};
    cout << "\nThe first vovel is: " << vowels[0] << endl;
    cout << "\nThe last vovel is: " << vowels[4] << endl;

    double hi_temps [] {30.1, 56.6, 78.6, 99};
    cout << "\nThe last high temperature is: " << hi_temps[3] << endl;
    cout << "Enter new last high temperature: ";
    cin >> hi_temps[3];
    cout << "The new last high temperature is: " << hi_temps[3] << endl;

    //to initialize all to 0 add curly brackets
    int score1 [5];
    cout << "\n\nUninitialized array";
    for (int i=0; i<=4; i++) 
    {
        cout << "\nIndex: " << i << " Value: " << score1[i];
    }

    cout << "\n\nInitialized array";
    int score2 [5] {};
    for (int i=0; i<=4; i++) 
    {
        cout << "\nIndex: " << i << " Value: " << score2[i];
    }

    //multidimensional array
    const int rows {2};
    const int cols {3};
    int movie_rating [rows][cols]
    {
        {1, 2, 3},
        {3, 4, 5}
    };
    for (int i=0; i<=1; i++) 
    {
        for (int j=0; j<=2; j++)
        {
            cout << "\nRow: " << i << " Col: " << j << " Value: " 
                 << movie_rating[i][j];
        }
    }

    return 0;
}
