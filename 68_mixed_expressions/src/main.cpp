#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int total {};
    int num1 {}, num2 {}, num3 {};
    const int count {3};

    cout << "\nEnter 3 int separated by spaces: "; 
    cin >> num1 >> num2 >> num3;

    total = num1 + num2 + num3;

    double average {0.0};
    average = total / count;

    cout << "\nThe 3 numbers are: " << num1 << ", " << num2 << ", " << num3;
    cout << "\nThe sum of the numbers is: " << total;
    cout << "\nThe average (non cast) is: " << average;

    average = static_cast<double> (total) / count;

    cout << "\nThe average (cast) is: " << average << endl;

    return 0;
}
