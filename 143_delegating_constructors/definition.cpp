#include "header.h"


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
