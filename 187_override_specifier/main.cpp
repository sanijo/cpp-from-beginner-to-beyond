#include<iostream>

class Base
{
public:
    virtual void message() const
    {
        std::cout << "Base::message()" << std::endl;
    }

    virtual ~Base(){std::cout << "Base destructor" << std::endl;}
};

class Derived: public Base
{
public:
    virtual void message() const override
    {
        std::cout << "Derived::message()" << std::endl;
    }
    virtual ~Derived(){std::cout << "Derived destructor" << std::endl;}
};



int main()
{
    std::cout << "\n=========Pointers=========" << std::endl;
    Base *p1 = new Base();
    Derived *p2 = new Derived();
    Base *p3 = new Derived();

    p1->message();
    p2->message();
    p3->message();

    std::cout << "\n=========Cleanup=========" << std::endl;
    delete p1;
    delete p2;
    delete p3;
    
    return 0;
}
