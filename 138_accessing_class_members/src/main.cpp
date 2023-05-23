#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Player
{
public:
    //atributes
    string name {"Player"};
    int health {100};
    int xp {0};

    //methods
    void talk(string text_to_say)
    {
        cout << name << " says " << text_to_say << endl;
    }
    bool is_dead();
};
class Account
{
public:
    string name {"Account"};
    double balance {0.0};

    //methods
    void deposit(double bal)
    {
        balance += bal;
        cout << "In deposit" << endl;
    }
    void withdraw(double bal)
    {
        balance -= bal;
        cout << "In withdraw" << endl;
    }
};

int main()
{
    Account frank_account;
    Account jim_account;

    frank_account.balance = 1000.0;
    frank_account.withdraw(100.0);

    Player frank;
    Player hero;

    frank.name = "Frank";
    cout << frank.health << endl;
    frank.health = 90;
    cout << frank.health << endl;
    frank.xp = 12;

    frank.talk("go fuck yourself!");

    Player *enemy = new Player;
    enemy -> name = "Jurica";
    (*enemy).xp = 0;
    enemy -> talk("something stupid...");

    delete enemy;
    
    return 0;
}
