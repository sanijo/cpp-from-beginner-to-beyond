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
    const Account don{"Don Richer", 98447.5};
    display_account(don);

    return 0;
}
