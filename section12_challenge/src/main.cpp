#include<iostream>
#include<string>
#include<vector>

using std::vector;
using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int *apply_all(const int *const array1, size_t size1, const int *const array2, size_t size2);
void print(const int *const array, size_t size);

int *apply_all(const int *const array1, size_t size1, const int *const array2, size_t size2)
{
    int *new_array {nullptr};
    size_t new_size {size1*size2};
    new_array = new int[new_size];
    size_t i{0};
    for (size_t j {0}; j<size2; ++j)
    {
        for (size_t k {0}; k<size1; ++k)
        {
            *(new_array+i) = *(array2+j) * *(array1+k);
            //new_array[i] = array2[j] * array1[k];
            ++i;
        }
    }
    return new_array;
}
void print(const int *const array, size_t size)
{
    cout << "[";
    for (size_t i{0}; i<size;  ++i)
    {
        if (i == (size-1))
        {
            cout << array[i];
        }
        else
        {
            cout << array[i] << " ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    int array1 [] {1,2,3,4,5};
    int array2 [] {10,20,30};
    const size_t size1 {5};
    const size_t size2 {3};
    int *results {nullptr};

    cout << "Array 1: ";
    print(array1, size1);

    cout << "Array 2: ";
    print(array2, size2);

    results = apply_all(array1, size1, array2, size2);
    cout << "Result: ";
    print(results, 15);
    delete [] results;

    return 0;
}
