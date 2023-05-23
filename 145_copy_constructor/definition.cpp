#include "header.h"

//constructor
Account::Account(std::string name_val, double balance_val)
    :name{name_val},balance{balance_val}{cout << "2 args constr" << endl;}
//Copy constructor - 1st line with initialization, 2nd with delegating
Account::Account(const Account &source)
    //:name{source.name}, balance{source.balance}
    :Account{source.name, source.balance}
{
    cout << "Copy constructor - made copy of " << source.name << endl;
}

void Account::set_balance (double bal)
{
    balance = bal;
}
double Account::get_balance ()
{
    return balance;
}
void Account::set_name(std::string n)
{
    name = n;
}
std::string Account::get_name()
{
    return name;
}
bool Account::deposit(double ammount)
{
    balance += ammount;
    return true;
}
bool Account::withdraw(double ammount)
{
    if (balance-ammount >= 0)
    {
        balance -= ammount;
        return true;
    }
    else
    {
        return false;
    }
}
