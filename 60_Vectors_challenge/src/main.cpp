#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector <int> v1; //empty
    vector <int> v2; //empty

    v1.push_back(10);
    v1.push_back(20);

    cout << "========================================";
    cout << "\nVector v1 elements";

    for (long unsigned int i=0; i<=v1.size()-1; i++) 
    {
        cout << "\nIndex: " << i << " Value: " << v1.at(i);
    }
    cout << "\nSize of v1: " << v1.size() << endl;

    v2.push_back(100);
    v2.push_back(100);
    v2.push_back(200);

    cout << "========================================";
    cout << "\nVector v2 elements";

    for (long unsigned int i=0; i<=v2.size()-1; i++) 
    {
        cout << "\nIndex: " << i << " Value: " << v2.at(i);
    }
    cout << "\nSize of v1: " << v2.size() << endl;

    //2D vector
    vector <vector<int>> two_d;
    vector <vector<int>> two_d_copy;

    two_d.push_back(v1);
    two_d.push_back(v2);

    //3D vector
    vector <vector <vector<int>>> three_d;
    two_d_copy.push_back(v1);
    two_d_copy.push_back(v2);
    three_d.push_back(two_d);
    three_d.push_back(two_d_copy);

    //vector style .at method
    cout << "========================================";
    cout << "\nVector method two_d.at(i).at(j)";
    for (long unsigned int i=0; i<=two_d.size()-1; i++) 
    {
        for (long unsigned int j=0; j<=two_d.at(i).size()-1; j++)
        {
            cout << "\nRow: " << i << " Col: " << j << " Value: " 
                 << two_d.at(i).at(j);
        }
    }

    v1.at(0) = 1000;
    cout << "\n========================================";
    cout << "\nVector method two_d.at(i).at(j) after v1.at(0)=1000";
    for (long unsigned int i=0; i<=two_d.size()-1; i++) 
    {
        for (long unsigned int j=0; j<=two_d.at(i).size()-1; j++)
        {
            cout << "\nRow: " << i << " Col: " << j << " Value: " 
                 << two_d.at(i).at(j);
        }
    }
    
    //vector style .at method
    cout << "\n========================================";
    cout << "\nVector method two_d.at(i).at(j).at(k) -3D vector";
    for (long unsigned int i=0; i<=three_d.size()-1; i++) 
    {
        for (long unsigned int j=0; j<=three_d.at(i).size()-1; j++)
        {
            for (long unsigned int k=0; k<=three_d.at(i).at(j).size()-1; k++)
            {
                cout << "\n2D_vec: " << i << " Row: " << j << " Col: " 
                     << k << " Value: " 
                     << three_d.at(i).at(j).at(k);
            }
        }
    }

    return 0;
}
