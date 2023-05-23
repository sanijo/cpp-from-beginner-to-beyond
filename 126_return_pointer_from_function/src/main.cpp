#include<iostream>
#include<string>
#include<vector>

using std::vector;
using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int *create_array(size_t size, int init_value=0);
void display(const int *const array, size_t size);

int *create_array(size_t size, int init_value)
{
    int *new_storage {nullptr};
    new_storage = new int[size];
    for (size_t i {0}; i<size; ++i)
    {
        //*(new_storage+i) = init_value;
        new_storage[i] = init_value;
    }
    return new_storage;
}
void display(const int *const array, size_t size)
{
    for (size_t i{0}; i<size;  ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int *my_array {nullptr};
    size_t size;
    int init_value {};

    cout << "\nHow many integers to allocate? ";
    cin >> size;
    cout << "\nValue to initialize the elements? ";
    cin >> init_value;

    my_array = create_array(size, init_value);
    
    cout << "\n------------------------------" << endl;
    display(my_array, size);
    delete [] my_array;

    return 0;
}
