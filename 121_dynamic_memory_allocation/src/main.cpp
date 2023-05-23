#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    //memory allocation for single int
    int *p1 {nullptr};
    p1 = new int;
    cout << p1 << endl;
    delete p1;

    //memory allocation for array
    size_t size{0};
    double *p2 {nullptr};
    
    cout << "How many to allocate? ";
    cin >> size;

    p2 = new double[size];
    cout << p2 << endl;

    delete [] p2;

    
    return 0;
}
