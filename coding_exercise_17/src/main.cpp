#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{

    vector<int> vec {1, 2, 3, 4, 5};

    int result {};
    
    cout << "\n===============================\n";

    if (vec.size()<=1)
    {
        result = 0;
    }
    else
    {
        for (size_t i {0}; i<vec.size()-1; i++)
        {
            for (size_t j {1+i}; j<vec.size(); j++)
            {
                result += vec.at(i) * vec.at(j);
                cout << "\n" << vec.at(i) << " * " << vec.at(j) << " = " 
                     << (vec.at(i) * vec.at(j));
            }
        }
    }
    cout << "\n\nSum: " << result << endl;
    cout << "\n===============================\n";

    return 0;
}
