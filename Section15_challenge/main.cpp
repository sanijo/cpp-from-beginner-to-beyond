// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
   // vector<Account> accounts;
   // accounts.push_back(Account {});
   // accounts.push_back(Account {"Larry"});
   // accounts.push_back(Account {"Moe", 2000} );
   // accounts.push_back(Account {"Curly", 5000} );
   // 
   // display(accounts);
   // deposit(accounts, 1000);
   // withdraw(accounts,2000);
   // 
   // // Savings 

   // vector<Savings_Account> sav_accounts;
   // sav_accounts.push_back(Savings_Account {} );
   // sav_accounts.push_back(Savings_Account {"Superman"} );
   // sav_accounts.push_back(Savings_Account {"Batman", 2000} );
   // sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

   // display(sav_accounts);
   // deposit(sav_accounts, 1000);
   // withdraw(sav_accounts, 2000);
    
    // Checking Accounts
   // vector<Checking_Account> ch_accounts;
   // ch_accounts.push_back(Checking_Account {});
   // ch_accounts.push_back(Checking_Account {"Mijo"});
   // ch_accounts.push_back(Checking_Account {"Danko", 2000} );
   // ch_accounts.push_back(Checking_Account {"Karl", 5000} );
   // 
   // display(ch_accounts);
   // deposit(ch_accounts, 1000);
   // withdraw(ch_accounts,2000);

    // Trust Accounts
   // vector<Trust_Account> tr_accounts;
   // tr_accounts.push_back(Trust_Account {"X"});
   // tr_accounts.push_back(Trust_Account {"Y", 2000} );
   // tr_accounts.push_back(Trust_Account {"Z", 5000} );
   // 
   // display(tr_accounts);
   // deposit(tr_accounts, 5000);
   // //withdraw(tr_accounts,2000);
   //// Withdraw 5 times from each trust account
   // // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
   // for (int i=1; i<=8; i++)
   //     withdraw(tr_accounts, 100);

    // Overloaded += and -= Accounts
   // vector<Account> accounts2;
   // accounts2.push_back(Account {"Ll"});
   // accounts2.push_back(Account {"Mm", 2000} );
   // accounts2.push_back(Account {"Cc", 5000} );
   // 
   // display(accounts2);
   // deposit_overloaded(accounts2, 1000);
   // withdraw_overloaded(accounts2,2000);

    // Overloaded += and -= Accounts
    vector<Savings_Account> accounts3;
    accounts3.push_back(Savings_Account {"xx"});
    accounts3.push_back(Savings_Account {"yy", 2000} );
    accounts3.push_back(Savings_Account {"zz", 5000} );
    
    display(accounts3);
    deposit_overloaded(accounts3, 1000);
    withdraw_overloaded(accounts3,2000);

    return 0;
}

