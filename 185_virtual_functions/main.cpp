#include<iostream>
#include<vector>

class Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Account::Withdraw" << std::endl;
    }

    virtual ~Account(){std::cout << "Account destructor" << std::endl;}
};

class Checking: public Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Checking::Withdraw" << std::endl;
    }
    virtual ~Checking(){std::cout << "Checking destructor" << std::endl;}
};

class Savings: public Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Savings::Withdraw" << std::endl;
    }
    virtual ~Savings(){std::cout << "Savings destructor" << std::endl;}
};

class Trust: public Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Trust::Withdraw" << std::endl;
    }
    virtual ~Trust(){std::cout << "Trust destructor" << std::endl;}
};


int main()
{
    std::cout << "\n=========Pointers=========" << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Checking();
    Account *p3 = new Savings();
    Account *p4 = new Trust();

    p1->withdraw(100.0);
    p2->withdraw(100.0);
    p3->withdraw(100.0);
    p4->withdraw(100.0);

    std::cout << "\n=========Pointers inside vector=========" << std::endl;
    std::vector<Account *> vec = {p1, p2, p3, p4};
    for (auto v: vec)
    {
        v->withdraw(1000.0);
    }


    std::cout << "\n=========Cleanup=========" << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    
    return 0;
}
