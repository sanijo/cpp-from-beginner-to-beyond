#include<iostream>
#include<string>
#include<vector>

using std::vector;
using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void double_data(int *int_ptr);
void swap(int *a, int *b);
void display(const vector<string> *const v);

void display(const vector<string> *const v)
{
    for (auto str: *v)
    {
        cout << str << " ";
    }
    cout << endl;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void double_data(int *int_ptr)
{
    *int_ptr *= 2;
}

int main()
{
    int value {10};
    int *int_ptr {nullptr};

    cout << "Value: " << value << endl;
    double_data(&value);
    cout << "Value: " << value << endl;

    cout << "\n-----------------------" << endl;
    int_ptr = &value;
    double_data(int_ptr);
    cout << "Value: " << value << endl;

    int x {100}, y {200};

    cout << "\n-----------------------" << endl;
    cout << "x: " << x << " and y: " << y << endl;

    swap(&x, &y);
    cout << "x: " << x << " and y: " << y << endl;

    cout << "\n-----------------------" << endl;
    vector<string> names {"Larry", "Don", "Diks"};

    display(&names);



    return 0;
}
