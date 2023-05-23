#include <iostream>
#include <string>
#include <vector>

template <class T>
class Item
{
private:
    std::string name_;
    T value_;
public:
    Item(std::string name_, T value_):
        name_{name_}, value_{value_}
    {}
    std::string get_name() const {return name_;};
    T get_value(){return value_;};
};

template <class T1, class T2>
struct My_pair
{
    T1 firs;
    T2 second;
};


int main() 
{
    Item<double> item1{"Frank", 102.5};
    std::cout << item1.get_name() << std::endl;
    
    Item<std::string> item2{"Frank", "boss"};
    std::cout << item2.get_value() << std::endl;

    Item<Item<std::string>> item3 {"Mirjana", {"C++", "Professor"}};
    std::cout << item3.get_name() << " " 
              << item3.get_value().get_name() << " "
              << item3.get_value().get_value() << std::endl;

    std::cout << "\n========Items========" << std::endl;
    std::vector<Item<double>> vec {};
    vec.push_back(Item<double>("X", 99.4));
    vec.push_back(Item<double>("Y", 49.3));
    vec.push_back(Item<double>("Z", 73.1));

    for (const auto &item: vec)
    {
        std::cout << item.get_name() << std::endl;
    }


    My_pair <std::string, int> p1 {"Dora", 10};
    My_pair <int, int> p2 {69, 13};



    return 0;
}
