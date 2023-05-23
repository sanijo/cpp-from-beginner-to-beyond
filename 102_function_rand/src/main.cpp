#include<iostream>
#include<cstdlib>
#include<ctime>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int rand_num {};
    size_t count {10};
    int min {1};
    int max {6};

    //seed the rand number generator
    //if not the generator will get the same sequence every time

    cout << "RAND_MAX on my system: " << RAND_MAX << endl;
    srand(time(nullptr)); //seed random number

    for (size_t i {1}; i<=count; ++i)
    {
        //generate ran num [min, max]
        rand_num = rand() % max + min;
        cout << rand_num << endl;
    }
    
    return 0;
}
