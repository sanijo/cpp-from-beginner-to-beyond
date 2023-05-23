#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class Base 
{
    //friends of Base have acess to all
public:
    int a{0};
    void display()
    {
        cout << a << ", " << b << ", " << c << endl; //member method has access to all
    }
protected:
    int b {0};
private:
    int c {0};
};

class Derived: public Base
{
public:
    void access_base_members()
    {
        a = 100; //OK
        b = 200; //OK
        //c = 300; //not accessible
    }
};

int main()
{
    cout << "**********Base member access from base objects***********" << endl;
    Base base;
    base.a = 100; //OK
    //base.b = 500; //Compiler error
    //base.c = 454; //Compiler error

    cout << "**********Base member access from derived objects***********" << endl;
    Derived d;
    d.a = 100;
    //d.b = 200; //Compiler error
    //d.c = 333; //Compiler error
    

    return 0;
}
