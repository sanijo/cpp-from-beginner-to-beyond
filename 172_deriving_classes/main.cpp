#include<iostream>
#include "Account.h"
#include "Savings_Account.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    //Use the Account class
    Account acc;
    acc.deposit(2000.0);
    acc.withdraw(400.0);

    cout << endl;

    Account *p {nullptr};
    p = new Account();
    p->deposit(400.3);
    p->withdraw(324.0);
    delete p;

    cout << "\n******SAVINGS ACCOUNT********" << endl;
    //Use the Account class
    Savings_Account sav_acc;
    sav_acc.deposit(2000.0);
    sav_acc.withdraw(400.0);

    cout << endl;

    Savings_Account *ps {nullptr};
    ps = new Savings_Account();
    ps->deposit(400.3);
    ps->withdraw(324.0);
    delete ps;
    
    return 0;
}
