#include<iostream>
#include "header.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    {
    Account dan;
    dan.set_name("Dan");
    }

    {
    Account marie("Marie", 1000.0);
    cout << marie.get_name() << endl;
    }

    {
    Account lucile("Lucile", 3000.0);
    cout << lucile.get_name() << endl;
    Account jura;
    Account pero;
    pero.set_name("Pero");
    }


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
