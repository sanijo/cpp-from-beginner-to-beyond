#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class Deep 
{
private:
    int *data{nullptr};
public:
    void set_data_value(int d){*data=d;}
    int get_data_value(){return *data;}
    int *get_data_adress(){return data;};
    //constructor
    Deep(int d);
    //Copy constructor
    Deep(const Deep &source);
    //destructor
    ~Deep();
};

Deep::Deep(int d)
{
    data = new int;
    *data = d;
    cout << "Regular constructor invoked" << endl;
}

//different than shallow copy constructor
//Deep::Deep(const Deep &source):data{source.data}
//{
//    cout << "Copy constructor - deep copy" << endl;
//}
Deep::Deep(const Deep &source):Deep{*source.data}
{
    cout << "Copy constructor - deep copy" << endl;
}
////or
//Deep::Deep(const Deep &source)
//{
//    data = new int;
//    *data = *source.data,
//    cout << "Copy constructor - deep copy" << endl;
//}

Deep::~Deep()
{
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_deep(Deep s)
{
    cout << "Data value: " << s.get_data_value() << endl;
    cout << "Data adress: " << s.get_data_adress() << endl;
}

int main()
{
    Deep obj1 {100};
    display_deep(obj1);
    
    Deep obj2{obj1};
    obj2.set_data_value(1000);
    display_deep(obj2);
    
    return 0;
}
