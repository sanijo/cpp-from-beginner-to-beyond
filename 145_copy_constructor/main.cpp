#include<iostream>
#include "header.h"

using std::cin;
using std::cout;
using std::endl;

void display_account(Account a)
{
    cout << "Name: " << a.get_name() << endl;
    cout << "Balance: " << a.get_balance() << endl;
}

int main()
{
    Account don{"Don Richer", 98447.5};
    Account new_don{don};

    display_account(new_don);

    
    return 0;
}
