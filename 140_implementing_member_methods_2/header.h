#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<string>

class Account
{
private:
    //atributes
    std::string name {"John Doe"};
    double balance {0.0};
public:
    //methods declared inline
    void set_balance (double bal)
    {
        balance = bal;
    }
    double get_balance ()
    {
        return balance;
    }
    //methods declared outside the class declaration
    void set_name(std::string n);
    std::string get_name();

    bool deposit(double ammount);
    bool withdraw(double ammount);
};

#endif // _ACCOUNT_H_
