#include<iostream>
#include "Savings_Account.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "\n******ACCOUNT CLASS********" << endl;
    Account a1(1000.0);
    cout << a1 << endl;

    a1.deposit(100.0);
    cout << a1 << endl;

    a1.withdraw(1000.0);
    cout << a1 << endl;

    a1.withdraw(1000.0);
    cout << a1 << endl;

    cout << "\n******SAVINGS ACCOUNT CLASS********" << endl;

    Account *p {nullptr};
    p = new Savings_Account(2500.7, 3.0);
    cout << *p << endl;
    
    p->deposit(400.3);
    cout << *p << endl;

    p->withdraw(324.0);
    cout << *p << endl;
    delete p;

    Savings_Account a2(1566.1, 2);
    cout << a2 << endl;

    return 0;
}
