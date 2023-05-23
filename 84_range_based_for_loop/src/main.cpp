#include<iostream>
#include<vector>
#include<iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::setprecision;
using std::fixed;

int main()
{
    ////Example 1
    //int scores[] {10,20,30};

    //for (auto score: scores)
    //    cout << score << endl;

    ////Example 2
    //vector<double> temperatures {87.9, 89.0, 95.3};
    //double avg_temp {};
    //double total {};

    //for (auto temp: temperatures)
    //    total += temp;

    //if (temperatures.size() != 0)
    //    avg_temp = total / temperatures.size();
    //
    //cout << fixed << setprecision(1);
    //cout << "Average temperature is: " << avg_temp << endl;

    ////Example 3
    //for (auto val: {1,2,3,4,5})
    //    cout << val << endl;

    ////Example 4
    //for (auto c: "This is a test")
    //    if(c != ' ')
    //    cout << c;

    ////Example 5
    //for (auto c: "This is a test")
    //    if (c == ' ')
    //        cout << "\t";
    //    else
    //        cout << c;

    //Example 6
    vector<int> vec {1,3,5,15,16,17,
                    18,19,20,21,25,
                    26,27,30,50,55,
                    56,58,100,200,
                    300,400,500,600,700};
    
    int count {};
    for (auto v: vec)
    {
        if (v % 3 == 0 || v % 5 == 0)
            count += 1;
    }
    cout << count << " elements evenly divisible by either 3 or 5." << endl;


    return 0;
}
