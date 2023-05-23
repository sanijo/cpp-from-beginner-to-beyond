#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class Base 
{
private:
    int value;
public:
    Base(): value{0} {cout << "Base no-args constructor" << endl;}
    Base(int x): value{x} {cout << "Base (int) overloaded constructor" << endl;}
    ~Base() {cout << "Base destructor" << endl;}
};

class Derived: public Base
{
private:
    int double_value;
public:
    Derived(): Base(), double_value{0} 
    {
        cout << "Double no-args constructor" << endl;
    }
    Derived(int x): Base(x), double_value{2*x} 
    {
        cout << "Double (int) overloaded constructor" << endl;
    }
    ~Derived() {cout << "Derived destructor" << endl;}
};

int main()
{
    Base b;
    Base bb(100);
    Derived d;
    Derived dd{100};

    return 0;
}
