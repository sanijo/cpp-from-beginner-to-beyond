#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Player
{
    private:
        //atributes
        string name {"Player"};
        int healtx {100};
        int xp {3};
    public:
        //methods
        void talk (string text)
        {
            cout << name << " says " << text << endl;
        }
        void set_name(string new_name)
        {
             name = new_name;
        }
        bool is_dead();
};

int main()
{
    Player frank;
    frank.talk("something");
    frank.set_name("Miho");
    frank.talk("something else..");

    Player *marrie = new Player;
    marrie->talk("hi!");
    marrie->set_name("Marrie");
    marrie->talk("hi again!");
    delete marrie;
    
    return 0;
}
