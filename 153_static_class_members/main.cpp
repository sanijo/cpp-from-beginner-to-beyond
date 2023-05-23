#include<iostream>
#include "header.h"

using std::cin;
using std::cout;
using std::endl;

void display_active_accounts()
{
    cout << "Active accounts: " << Account::get_num_acc() << endl;
}

int main()
{
    display_active_accounts();
    Account jack;
    Account rick;
    display_active_accounts();
    {
        Account gaga;
        display_active_accounts();
    }
    display_active_accounts();

    Account *mirko = new Account{"Mirko", 1000.0};
    display_active_accounts();
    delete mirko;
    display_active_accounts();

    return 0;
}
