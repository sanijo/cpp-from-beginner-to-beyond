#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class Shallow 
{
private:
    int *data{nullptr};
public:
    void set_data_value(int d){*data=d;}
    int get_data_value(){return *data;}
    int *get_data_adress(){return data;};
    //constructor
    Shallow(int d);
    //Copy constructor
    Shallow(const Shallow &source);
    //destructor
    ~Shallow();
};

Shallow::Shallow(int d)
{
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow &source):data{source.data}
{
    cout << "Copy constructor - shallow copy" << endl;
}

Shallow::~Shallow()
{
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_deep(Shallow s)
{
    cout << "Data value: " << s.get_data_value() << endl;
    cout << "Data adress: " << s.get_data_adress() << endl;
}

int main()
{
    Shallow obj1 {100};
    display_shallow(obj1);
    
    Shallow obj2{obj1};
    obj2.set_data_value(1000);
    
    return 0;
}
