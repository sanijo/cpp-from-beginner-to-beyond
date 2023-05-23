#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Move 
{
private:
    int *data;
public:
    void set_data_value(int d){*data=d;}
    int get_data_value(){return *data;}
    int *get_data_adress(){return data;};
    //constructor
    Move(int d);
    //Copy constructor
    //Move(const Move &source);
    //Move constructor
    Move(Move &&source) noexcept;
    //destructor
    ~Move();
};

Move::Move(int d)
{
    data = new int;
    *data = d;
    cout << "Regular constructor invoked for " << *data << endl;
}

//different than shallow copy constructor
//Move::Move(const Move &source):data{source.data}
//{
//    cout << "Copy constructor - move copy" << endl;
//}

////Copy constructor
//Move::Move(const Move &source):Move{*source.data}
//{
//    cout << "Copy constructor - move copy for " << *source.data << endl;
//}

////Move constructor
Move::Move(Move &&source) noexcept:data{source.data}
{
    source.data = nullptr;
    cout << "Move constructor - moving resource" << endl;
}

Move::~Move()
{
    if (data != nullptr)
    {
        cout << "Destructor freeing data for: " << *data << endl;
    }
    else
    {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}

void display_move(Move s)
{
    cout << "Data value: " << s.get_data_value() << endl;
    cout << "Data adress: " << s.get_data_adress() << endl;
}

int main()
{
    vector<Move> vec;
    //temporary object - rvalue
    vec.push_back(Move{10});
    
    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});

    return 0;
}
