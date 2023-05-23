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
    //Delegated constructors
    Account(std::string name_val="None", double balance_val=0.0);
    //Copy constructor
    Account(const Account &source);

    //methods declared outside the class declaration
    void set_balance (double bal);
    double get_balance () const;
    void set_name(std::string n);
    std::string get_name() const;
    bool deposit(double ammount);
    bool withdraw(double ammount);

    ~Account()
    {
        cout << "Destructor called for " << name << endl;
    }
};

#endif // _ACCOUNT_H_
