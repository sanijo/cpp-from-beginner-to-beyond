#include <iostream>
#include <string>
#include <vector>

template <typename T, int N>
class Array
{
    int size_ {N};
    T values_ [N];

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr)
    {
        os << "[ ";
        for (const auto &val: arr.values_)
        {
            os << val << " ";
        }
        os << "]" << std::endl;
        return os;
    }
public:
    Array(){};
    Array(T init_val)
    {
        for (auto &item: values_)
            item = init_val;
    }
    void fill(T val)
    {
        for (auto &item: values_)
            item = val;
    }
    int get_size() const
    {
        return size_;
    }
    //overloaded subscript operator for easy use
    T &operator[](int index)
    {
        return values_[index];
    }

    ~Array(){};
};


int main() 
{
    Array<int,5> nums{0};
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;
    nums.fill(69);
    std::cout << nums << std::endl;
    nums[1] = 55;
    std::cout << nums << std::endl;

    Array<int,20> nums2{3};
    std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl;

    Array<std::string,10> nums3{"A"};
    std::cout << "The size of nums3 is: " << nums3.get_size() << std::endl;
    std::cout << nums3 << std::endl;
    nums3.fill("ABD");
    std::cout << nums3 << std::endl;


    return 0;
}
