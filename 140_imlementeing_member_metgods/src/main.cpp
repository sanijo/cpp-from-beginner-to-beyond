#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Account
{
private:
    //atributes
    string name {"John Doe"};
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
    void set_name(string n);
    string get_name();

    bool deposit(double ammount);
    bool withdraw(double ammount);
};

void Account::set_name(string n)
{
    name = n;
}
string Account::get_name()
{
    return name;
}
bool Account::deposit(double ammount)
{
    balance += ammount;
    return true;
}
bool Account::withdraw(double ammount)
{
    if (balance-ammount >= 0)
    {
        balance -= ammount;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Account *jack = new Account();

    jack->set_name("Jack Reacher");
    cout << "Name: " << jack->get_name() << endl;
    jack->set_balance(4000.0);
    cout << "Balance: " << jack->get_balance() << endl;
    jack->deposit(300.0);
    cout << "Balance: " << jack->get_balance() << endl;
    jack->withdraw(40000.0);
    jack->withdraw(4000.0);
    cout << "Balance: " << jack->get_balance() << endl;

    delete jack;
    
    return 0;
}
