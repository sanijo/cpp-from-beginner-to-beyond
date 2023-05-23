#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance) 
    : Account {name, balance} {
}

bool Checking_Account::deposit(double amount) 
{
    return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount) 
{
    amount += fee;
    return Account::withdraw(amount);
}

void Checking_Account::print(std::ostream &os) const
{
    os << "[Checking_Account: " 
       << name 
       << ": " 
       << balance 
       << ": " 
       << fee 
       << "]";
}

bool Checking_Account::operator+=(double rhs)
{
    return this->Account::deposit(rhs);
}

bool Checking_Account::operator-=(double rhs)
{
    rhs -= fee;
    return this->Account::withdraw(rhs);
}
