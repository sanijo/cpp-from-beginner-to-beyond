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
    //atributes
    string name {"Player"};
    int health {100};
    int xp {0};

    //methods
    void talk(string);
    bool is_dead();
};
class Account
{
    string name {"Account"};
    double balance {0.0};

    //methods
    bool deposit(double);
    bool withdraw(double);
};

int main()
{
    Account frank_account;
    Account jim_account;

    Player frank;
    Player hero;

    Player players [] {frank, hero};
    vector<Player> player_vec {frank};
    player_vec.push_back(hero);

    Player *enemy {nullptr};
    enemy = new Player;

    delete enemy;
    
    return 0;
}
