// Simple Checking_Account 
#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"

class Checking_Account: public Account {
private:   
    static constexpr const char *def_name = "Unnamed Checking_Account";
    static constexpr double def_balance = 0.0;
protected:
    double fee {1.5};
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
    virtual bool operator+=(double rhs) override;
    virtual bool operator-=(double rhs) override;
    virtual ~Checking_Account(){};
};
#endif
