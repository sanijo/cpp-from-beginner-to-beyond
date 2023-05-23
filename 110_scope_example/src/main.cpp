#include<iostream>

using std::cin;
using std::cout;
using std::endl;

void static_local()
{
    static int num {10}; //local to static_local static - retains it value between calls
    cout << "\nLocal static num is: " << num << " in static_local -start" 
         << endl;
    num += 10;
    cout << "Local static num is: " << num << " in static_local - end" << endl;
}

int main()
{
    int num {100};
    int num1 {400};

    cout << "Local num is: " << num << " in main" << endl;

    {//creates a new level of scope
        int num {200};
        cout << "Local num is: " << num << " in inner block in main" << endl;
        cout << "Inner block in main can see out - num1 is: " << num1 << endl;
    }
    
    cout << "Local num is: " << num << " in main" << endl;

    cout << "\nstatic_local() first call:";
    static_local();
    cout << "\nstatic_local() second call:";
    static_local();

    return 0;
}
