#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    //vector <char> vowels; //empty
    //vector <char> vowels (5); //5 initialized to 0
    vector <char> vowels {'a', 'e', 'i', 'o', 'u'};

    cout << vowels[0] << endl;
    cout << vowels[4] << endl;

    //vector <int> num (3); //elements all init at 0
    //vector <int> num (3, 100); //3 elements init at 100
    vector <int> num {100, 98, 97}; //3 elements with coresponding values
    cout << "\nElements of num vector: " << endl;
    cout << num.at(0) << endl;
    cout << num.at(1) << endl;
    cout << num.at(2) << endl;
    cout << "There are " << num.size() << " scores in the vector num." << endl;

    cout << "\nEnter number to add to num vector:";
    int to_add {0};
    cin >> to_add;
    num.push_back(to_add);
    cout << "\nEnter number to add to num vector:";
    cin >> to_add;
    num.push_back(to_add);

    cout << "\nElements of vector num now are: ";
    for (long unsigned int i=0; i<=num.size()-1; i++)
    {
        cout << "\nIndex: " << i << " Value: " << num.at(i);
    }
    cout << "\nThere are " << num.size() << " scores in the vector num." << endl;

    //cout << "\nThis should cause exception: " << num.at(10);

    //2D vector
    vector <vector<int>> two_d
    {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "\nArray method two_d[i][j]";
    for (int i=0; i<=1; i++) 
    {
        for (int j=0; j<=2; j++)
        {
            cout << "\nRow: " << i << " Col: " << j << " Value: " 
                 << two_d[i][j];
        }
    }
    //vector style .at method
    cout << "\nVector method two_d.at(i).at(j)";
    for (int i=0; i<=1; i++) 
    {
        for (int j=0; j<=2; j++)
        {
            cout << "\nRow: " << i << " Col: " << j << " Value: " 
                 << two_d.at(i).at(j);
        }
    }

    return 0;
}
