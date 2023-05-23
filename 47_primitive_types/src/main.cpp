#include<iostream>
#include<climits>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    char middle_initial {'J'};
    cout << "Middle name: " << middle_initial << endl;

    unsigned short int exam_score {65};
    cout << "Exam score: " << exam_score << endl;

    int countries_represented {45};
    cout << "Countries represented: " << countries_represented << endl;

    long people_in_ny {20610000};
    cout << "People in NY: " << people_in_ny  << endl;

    long long people_on_earth {7'600'000'000};
    cout << "People on Earth: " << people_on_earth <<endl;

    long long distance_to_alpha_centauri {9'461'000'000'000};
    cout << "Distance to Alpha Centauri: " << distance_to_alpha_centauri << endl;

    float car_payment {401.23};
    cout << "Car payment: " << car_payment << endl;

    double pi {3.14159};
    cout << "Pi: " << pi << endl;

    long double large_ammount {2.7e118};
    cout << "Large number: " << large_ammount << endl;

    bool flag {false};
    cout << "Bool: " << flag << endl;

    //Overflow example
    //short v1 {30000};
    //short v2 {1000};
    //short product {v1 * v2};

    //cout << "The product of " << v1 << " and " << v2 << " is " << product << endl;

    //sizeof() operator example
    cout << "===================================" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of large_ammount: " << sizeof(large_ammount) << " bytes" << endl;
    cout << "Size of car_payment: " << sizeof(car_payment) << " bytes" << endl;

    //use values defined in <climits>
    cout << "===================================" << endl;
    cout << "Minimum values:" << endl;
    cout << "char: " << CHAR_MIN << endl;
    cout << "int: " << INT_MIN << endl;
    cout << "short: " << SHRT_MIN << endl;
    cout << "long: " << LONG_MIN << endl;
    cout << "long long: " << LLONG_MIN << endl;
    
    cout << "===================================" << endl;
    cout << "Maximum values:" << endl;
    cout << "char: " << CHAR_MAX << endl;
    cout << "int: " << INT_MAX << endl;
    cout << "short: " << SHRT_MAX << endl;
    cout << "long: " << LONG_MAX << endl;
    cout << "long long: " << LLONG_MAX << endl;

    return 0;
}
