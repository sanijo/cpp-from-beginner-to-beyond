#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>
#include <string>

class Person 
{
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
        :name(name), age(age) {}
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

void find_test()
{
    std::cout << "\n===========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5};

    auto loc = std::find(std::begin(vec), std::end(vec), 8);

    if (loc != std::end(vec))
        std::cout << "Found the number " << *loc << std::endl;
    else
        std::cout << "Couldn't find the number" << std::endl;

    std::list<Person> players
    {
        {"Moe", 21},
        {"Joe", 32},
        {"Ike", 62}
    };

    auto loc1 = std::find(players.begin(), players.end(), Person{"Ike", 62});

    if (loc1 != players.end())
        std::cout << "Found the person " << std::endl;
    else
        std::cout << "Couldn't find the person" << std::endl;
}

void count_test()
{
    std::cout << "\n===========================" << std::endl;

    std::vector<int> vec {1,2,1,3,5,6,2,1,2,1,3,4,5};

    auto num = std::count(std::begin(vec), std::end(vec), 1);

    std::cout << num << " occurences found" << std::endl;

}

void count_if_test()
{
    std::cout << "\n===========================" << std::endl;

    std::vector<int> vec {1,2,1,3,5,6,2,1,2,1,3,4,5};

    auto num = std::count_if(std::begin(vec), std::end(vec), [](int x){return x%2 == 0;});
    std::cout << num << " even numbers found" << std::endl;

    auto num1 = std::count_if(std::begin(vec), std::end(vec), [](int x){return x%2 != 0;});
    std::cout << num1 << " odd numbers found" << std::endl;

    auto num2 = std::count_if(std::begin(vec), std::end(vec), [](int x){return x >= 5;});
    std::cout << num2 << " >=5 numbers found" << std::endl;

}

void replace_test()
{
    std::cout << "\n===========================" << std::endl;

    std::vector<int> vec {1,2,1,3,5,6,2,1,2,1,3,4,5};
    for (auto &v:vec)
        std::cout << v << " ";
    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto &v:vec)
        std::cout << v << " ";
    std::cout << std::endl;
}

void all_of_test()
{
    std::cout << "\n===========================" << std::endl;

    std::vector<int> vec {1,2,1,3,5,6,2,1,2,1,3,4,5};

    if (std::all_of(vec.begin(), vec.end(), [](int x) {return x>10;}))
        std::cout << "All elements are > 10" << std::endl;
    else
        std::cout << "Not all elements are > 10" << std::endl;

    if (std::all_of(vec.begin(), vec.end(), [](int x) {return x<10;}))
        std::cout << "All elements are < 10" << std::endl;
    else
        std::cout << "Not all elements are < 10" << std::endl;
}

void string_format_test()
{
    std::cout << "\n===========================" << std::endl;

    std::string str1 {"This is a test"};

    std::cout << "Before transform: " << str1 << std::endl;

    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);

    std::cout << "After transform: " << str1 << std::endl;
}

int main()
{
    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_format_test();

    return 0;
}
