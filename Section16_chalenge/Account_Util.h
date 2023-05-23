#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"

// Utility helper functions 
void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);

void deposit_overloaded(std::vector<Account *> &accounts, double amount);
void withdraw_overloaded(std::vector<Account *> &accounts, double amount);

#endif
