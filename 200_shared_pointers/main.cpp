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
    
    std::shared_ptr<Account> p1 {new Checking_Account("Larry", 10000)};
    //creating shared_ptr more efficient using make_shared
    std::shared_ptr<Account> p2 = std::make_shared<Savings_Account>("Moe", 1000);
    std::shared_ptr<Account> p3 = std::make_shared<Trust_Account>("Curly", 9875);
    
    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(p1);
    accounts.push_back(p2);
    accounts.push_back(p3);
    
    for (const auto &acc: accounts)
    {
        std::cout << *acc << std::endl;
    }
    
    delete trust;

    return 0;
}

