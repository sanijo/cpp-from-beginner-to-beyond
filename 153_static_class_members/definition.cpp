#include "header.h"

//static parameter initialization - do it here
int Account::num_acc {0};

//constructor
Account::Account(std::string name_val, double balance_val)
    :name{name_val},balance{balance_val}
{
    ++num_acc;
}
//Copy constructor - 1st line with initialization, 2nd with delegating
Account::Account(const Account &source)
    //:name{source.name}, balance{source.balance}
    :Account{source.name, source.balance}
{
    cout << "Copy constructor - made copy of " << source.name << endl;
}
Account::~Account()
{
    --num_acc;
}

double Account::get_balance ()
{
    return balance;
}
std::string Account::get_name()
{
    return name;
}
int Account::get_num_acc()
{
    return num_acc;
}
