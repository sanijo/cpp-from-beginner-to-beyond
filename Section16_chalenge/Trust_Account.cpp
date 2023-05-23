#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate) 
    : Savings_Account {name, balance, int_rate}, count {0} {
}

bool Trust_Account::deposit(double amount) 
{
    if (amount >= bonus_treshold)
        amount += (amount * (int_rate/100)) + bonus;
    else
        amount += amount * (int_rate/100);
    return Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) 
{
    if (count >= max_withdrawals || (amount > (balance * max_withdraw_percent)))
    {
        if (count >= max_withdrawals)
            count = 0;
        return false;
    } else
    {
        ++count;
        return Savings_Account::withdraw(amount);
    }
}

void Trust_Account::print(std::ostream &os) const
{
    os << "[Trust_Account: " 
       << name 
       << ": " 
       << balance 
       << ": " 
       << int_rate 
       << "%: " 
       << bonus 
       << " number of withdrawals: "
       << count
       << "]";
}

bool Trust_Account::operator+=(double rhs)
{
    if (rhs >= bonus_treshold)
        rhs += (rhs * (int_rate/100)) + bonus;
    else
        rhs += rhs * (int_rate/100);
    return this->Account::deposit(rhs);
}

bool Trust_Account::operator-=(double rhs)
{
    if (count >= max_withdrawals || (rhs > (balance * max_withdraw_percent)))
    {
        if (count >= max_withdrawals)
            count = 0;
        return false;
    } else
    {
        ++count;
        return this->Savings_Account::withdraw(rhs);
    }
}
