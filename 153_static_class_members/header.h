#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<string>
#include<iostream>

using std::cout;
using std::endl;

class Account
{
private:
    static int num_acc;
    //atributes
    std::string name;
    double balance;
public:
    //methods declared outside the class declaration
    double get_balance ();
    std::string get_name();
    static int get_num_acc();

    //Delegated constructors
    Account(std::string name_val="None", double balance_val=0.0);
    //Copy constructor
    Account(const Account &source);

    ~Account();
};

#endif // _ACCOUNT_H_
