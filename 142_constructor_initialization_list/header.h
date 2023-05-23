#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<string>
#include<iostream>

using std::cout;
using std::endl;

class Account
{
private:
    //atributes
    std::string name {"John Doe"};
    double balance {0.0};
public:
    Account():name {"Ivan Horvat"}, balance {10.0}
    {
        cout << "No args constructor called." << endl;
    }
    Account(std::string name_val):name {name_val}
    {
        cout << "String arg constructor called." << endl;
    }
    Account(double balance_val):balance {balance_val}
    {
        cout << "Double arg constructor called." << endl;
    }
    Account(std::string name_val, double balance_val):name{name_val},balance{balance_val}
    {
        cout << "String and double args constructor called." << endl;
    }
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

    ~Account()
    {
        cout << "Destructor called for " << name << endl;
    }
};

#endif // _ACCOUNT_H_
