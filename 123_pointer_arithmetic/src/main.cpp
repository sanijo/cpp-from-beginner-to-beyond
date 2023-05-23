#include<iostream>
#include<string>

using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int scores [] {1, 23, 98, 22, -1};
    int *p {scores};

    while (*p != -1) 
    {
        cout << *p << endl;
        p++;
    }

    cout << "\n---------------------" << endl;
    p = scores;
    while (*p != -1) 
    {
        cout << *p++ << endl;
    }

    cout << "\n---------------------" << endl;
    string s1 {"Frank"}, s2 {"Frank"}, s3 {"Pepe"};
    string *p1 {&s1}, *p2 {&s2}, *p3 {&s1};

    cout << boolalpha;
    cout << p1 << "==" << p2 << ":" << (p1==p2) << endl;
    cout << p1 << "==" << p3 << ":" << (p1==p3) << endl;

    cout << *p1 << "==" << *p2 << ":" << (*p1==*p2) << endl;
    cout << *p1 << "==" << *p3 << ":" << (*p1==*p3) << endl;

    p3 = &s3;
    cout << *p1 << "==" << *p3 << ":" << (*p1==*p3) << endl;


    return 0;
}
