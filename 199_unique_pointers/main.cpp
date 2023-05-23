// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include <memory>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
    
    Checking_Account frank {"Frank", 5000};
    cout << frank << endl;
    
    Account *trust = new Trust_Account("James");
    cout << *trust << endl;
    
    std::unique_ptr<Account> p1 {new Checking_Account("Larry", 10000)};
    std::unique_ptr<Account> p2 = std::make_unique<Savings_Account>("Moe", 1000);
    std::unique_ptr<Account> p3 {new Trust_Account("Curly")};
    
    std::vector<std::unique_ptr<Account>> accounts;
    accounts.push_back(std::make_unique<Checking_Account>("Joe", 10000));
    accounts.push_back(std::make_unique<Checking_Account>("Moe", 8000));
    accounts.push_back(std::make_unique<Checking_Account>("Xavi", 4000));
    
    for (const auto &acc: accounts)
    {
        std::cout << *acc << std::endl;
    }
    
    delete trust;

    return 0;
}

