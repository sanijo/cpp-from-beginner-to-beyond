#include<iostream>
#include "header.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Account *jack = new Account();

    jack->set_name("Jack Reacher");
    cout << "Name: " << jack->get_name() << endl;
    jack->set_balance(4000.0);
    cout << "Balance: " << jack->get_balance() << endl;
    jack->deposit(300.0);
    cout << "Balance: " << jack->get_balance() << endl;
    jack->withdraw(40000.0);
    jack->withdraw(4000.0);
    cout << "Balance: " << jack->get_balance() << endl;

    delete jack;
    
    return 0;
}
