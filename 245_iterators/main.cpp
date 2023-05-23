#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

//display any vector of integers
void display(const std::vector<int> &vec)
{
    std::cout << "[" << std::endl;
    for (auto const &v: vec)
    {
        std::cout << v << " ";
    }
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "\n***********************" << std::endl;
    std::vector<int> nums1 {1,2,3,4,5};

    auto it = nums1.begin(); //point to 1

    std::cout << *it << std::endl;
    it++; //point to 2
    std::cout << *it << std::endl;
    it += 2; //points to 4
    std::cout << *it << std::endl;
    it -= 2; //points to 2
    std::cout << *it << std::endl;
    it = nums1.end() - 1; //points to 5
    std::cout << *it << std::endl;
    *it = 0;
    std::cout << *it << std::endl;
}

void test2()
{
    std::cout << "\n***********************" << std::endl;
    std::vector<int> nums1 {1,2,3,4,5};

    auto it = nums1.begin(); //point to 1

    while (it != nums1.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    it = nums1.begin(); //point to 1
    while (it != nums1.end())
    {
        *it = 0;
        std::cout << *it << " ";
        it++;
    }

}

void test3()
{
    std::cout << "\n***********************" << std::endl;
    std::vector<int> nums1 {1,2,3,4,5};

    auto it = nums1.cbegin(); //const iterator
    while (it != nums1.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

void test4()
{
    std::cout << "\n***********************" << std::endl;
    std::vector<int> nums1 {1,2,3,4,5};

    auto it = nums1.crbegin(); //const iterator
    while (it != nums1.crend())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    std::list<std::string> name {"joe", "moe", "ana"};
    for (auto it{name.begin()}; it != name.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::map<std::string, std::string> favorites 
    {
        {"Frank", "C++"},
        {"Joe", "Python"},
        {"Moe", "Java"}
    };
    for (auto it{favorites.crbegin()}; it != favorites.crend(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void test5()
{
    std::cout << "\n***********************" << std::endl;
    std::vector<int> nums1 {1,2,3,4,5,6,7,8,9,10};

    auto start = nums1.begin() + 3;
    auto finish = nums1.end() - 2;

    while (start != finish)
    {
        std::cout << *start << " ";
        start++;
    }
}

int main()
{
//    test1();
//    test2();
//    test3();
//    test4();
    test5();

    return 0;
}
