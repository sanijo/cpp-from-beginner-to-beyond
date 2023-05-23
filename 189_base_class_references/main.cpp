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

void do_withdraw(Account &acc, double amount)
{
    acc.withdraw(amount);
}


int main()
{
    Account a;
    Account &ref = a;
    ref.withdraw(1000.0);

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(500.0);

    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;

    do_withdraw(a1, 100.0);
    do_withdraw(a2, 33.3);
    do_withdraw(a3, 456.5);
    do_withdraw(a4, 1.1);

    return 0;
}
