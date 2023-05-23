#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num_items {};
    cout << "How many items do you have? ";
    cin >> num_items;

    vector<int> data {};

    for (int i {1}; i<=num_items; i++)
    {
        int data_item {};
        cout << "Enter data item " << i << ": ";
        cin >> data_item;
        data.push_back(data_item);
    }


    cout << "\nDisplaying Histogram" << endl;
    for (auto val: data)
    {    
        for (int i {1}; i<=val; i++ )
        {
            if (i % 5 == 0)
                cout << "X";
            else
                cout << "=";
        }
        cout << endl;
    }

    return 0;
}
