#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate) 
    : Savings_Account {name, balance, int_rate}, count {0} {
}

bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_treshold)
        amount += (amount * (int_rate/100)) + bonus;
    else
        amount += amount * (int_rate/100);
    return Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if (count >= max_withdrawals || (amount > (balance * max_withdraw_percent))) {
        if (count >= max_withdrawals)
            count = 0;
        return false;
    } else
    {
        ++count;
        return Savings_Account::withdraw(amount);
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " 
       << account.name 
       << ": " 
       << account.balance 
       << ": " 
       << account.int_rate 
       << ": " 
       << account.bonus 
       << "]";
    return os;
}
