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
#include "Illegal_balance_exception.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
    
    try
    {
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -10.0);
        std::cout << *moes_account << std::endl;
    }
    catch (const IllegalBalanceException &rex)
    {
        std::cerr << "Couldn't create account - negative balance!" << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    

    return 0;
}

