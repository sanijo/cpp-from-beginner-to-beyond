#include <iostream>
#include <string>

template <class T>
T min (T a, T b)
{
    return (a<b) ? a:b;
}

template <class T>
T max (T a, T b)
{
    return (a>b) ? a:b;
}

template <typename T1, typename T2>
void fn(T1 a, T2 b)
{
    std::cout << "a: " << a << "  " << "b: " << b << std::endl;
}

struct Person
{
    std::string name;
    int age;

    bool operator<(const Person &rhs)
    {
        return this->age < rhs.age;
    }
    bool operator>(const Person &rhs)
    {
        return this->age > rhs.age;
    }
    
};

std::ostream &operator<<(std::ostream &os, const Person &rhs)
{
    os << rhs.name; 
    return os;
}

template <typename T>
void my_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main() 
{
    std::cout << min<int>(2,3) << std::endl;
    std::cout << min(2,3) << std::endl;
    std::cout << min('A','B') << std::endl;
    std::cout << min(12.3,3.3) << std::endl;
    std::cout << min(2+2,3+7) << std::endl;

    fn<int,double>(2,4.10);
    fn("A", 10);

    Person p1 {"Xara", 41};
    Person p2 {"Jovica", 15};

    Person p3 = min(p1,p2);
    Person p4 = max(p1,p2);
    std::cout << p3.name << " is younger than " << p4.name << std::endl;

    fn(p1, p2);

    int a {32}; 
    int b {54};
    std::cout << "a:" << a << "  " << "b:" << b << std::endl;
    my_swap(a,b);
    std::cout << "a:" << a << "  " << "b:" << b << std::endl;

    std::cout << p1 << "  " << p2 << std::endl;
    my_swap(p1,p2);
    std::cout << p1 << "  " << p2 << std::endl;

    

    return 0;
}
