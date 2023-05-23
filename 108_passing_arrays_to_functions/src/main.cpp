#include<iostream>

using std::cin;
using std::cout;
using std::endl;

void print_array(const int arr[], size_t size);
void set_array(int arr[], size_t size, int value);

void print_array(const int arr[], size_t size)
{
    for (size_t i{0}; i<size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void set_array(int arr[], size_t size, int value)
{
    for (size_t i{0}; i<size; ++i)
    {
        arr[i] = value;
    }
}

int main()
{
    int scores[] {100, 58, 98, 48};

    print_array(scores, 4);
    set_array(scores, 4, 69);
    print_array(scores, 4);

    
    return 0;
}
