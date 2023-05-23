#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    ////Example 1
    //int number {};
    //cout << "Enter an integer less than 100: ";
    //cin >> number;

    //while (number >= 100)
    //{
    //    cout << "Enter an integer less than 100: ";
    //    cin >> number;
    //}

    //cout << "Thanks!" << endl;

    ////Example 2
    //bool done {false};
    //int number {0};

    //while (!done)
    //{
    //    cout << !done << endl;
    //    cout << "Enter an integer between 1 and 10: ";
    //    cin >> number;
    //    if (number <= 1 || number >= 10)
    //        cout << "Out of range, try again." << endl;
    //    else
    //    {
    //        cout << "Thanks!" << endl;
    //        done = true;
    //    }
    //}

    //Example 3
    int count {};
    long unsigned int i {};
    vector<int> vec {1, 2, 3, -99};

    //while (i < vec.size())
    //{
    //    if (vec.at(i) == -99)
    //        break;
    //    count += 1;
    //    i++;
    //}
    while (i < vec.size() && vec.at(i) != -99)
    {
        count++;
        i++;
    }
    cout << "Integers before -99: " << count << endl;

    return 0;
}
