#include<iostream>
#include<vector>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    int num{10};
    cout << "Value of num is: " << num << endl;
    cout << "Size of num is: " << sizeof num << endl;
    cout << "Adress of num is: " << &num << endl;

    int *p;
    cout << "\nValue of p is: " << p << endl;
    cout << "Adress of p is: " << &p << endl;
    cout << "Size of p is: " << sizeof p << endl;

    p = nullptr;
    cout << "\nValue of p is: " << p << endl;

    int *p1 {};
    cout << "\nValue of p1 is: " << p1 << endl;
    double *p2 {};
    unsigned long long *p3 {};
    vector<string> *p4 {};

    cout << "\nSize of p1 is: " << sizeof p1 << endl;
    cout << "Size of p2 is: " << sizeof p2 << endl;
    cout << "Size of p3 is: " << sizeof p3 << endl;
    cout << "Size of p4 is: " << sizeof p4 << endl;

    int score {10};
    double high_temperature{100.2};

    int *p_score {};
    p_score = &score;

    cout << "\nValue of score is: " << score << endl;
    cout << "Adress of score is: " << &score << endl;
    cout << "Value of p_score is: " << p_score << endl;
    cout << "Dereferencing pointer p_score: " << *p_score << endl;

    (&score == p_score) ? (cout << "\n&score == p_score") : (cout << "\n&score != p_score");
    cout << endl;
    
    *p_score = 88;
    cout << "\nValue of score is: " << score << endl;

    //p_score = &high_temperature; //compiler error - not same types

    //dereferencing
    double score_1 {99.9};
    double *p_score_1 {&score_1};

    cout << "\nscore_1 value: " << score_1 << endl;
    *p_score_1 = 87.4;

    cout << "score_1 value: " << score_1 << endl;

    cout << "\n----------------------------------" << endl;
    double up {178.4};
    double down {-89.1};
    double *p_up {&up};
    cout << "*p_up == up: " << *p_up << " == " << up << endl;

    p_up = &down;
    cout << "*p_up == down: " << *p_up << " == " << down << endl;

    *p_up = up;
    cout << "*p_up == down == up: " << *p_up << " == " << down << " == " 
         << up << endl;

    //pointer to vector
    cout << "\n----------------------------------" << endl;
    vector<string> names {"Ivo", "Marta", "Lisa"};
    vector<string> *p_vec {&names};

    //() VERY IMPORTANT to use in (*p_vec).at(0)
    cout << "First name in vector names: " << (*p_vec).at(0) << endl;

    for (auto name: *p_vec)
    {
        cout << "\n" << name;
    }
    cout << endl;
    












    return 0;
}
