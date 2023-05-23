#include<iostream>
#include<string>
#include<vector>

using namespace std;

void pass_by_ref1(int &num);
void pass_by_ref2(string &s);
void pass_by_ref3(vector<string> &v);
void print_vec(const vector<string> &v);


void pass_by_ref1(int &num)
{
    num = 100;
}

void pass_by_ref2(string &s)
{
    s = "Changed";
}

void pass_by_ref3(vector<string> &v)
{
    v.clear();
}

void print_vec(const vector<string> &v)
{
    for (auto s: v)
    {
        cout << s << " ";
    }
    cout << endl;
}

int main()
{
    int num {10};

    cout << "num before calling pass_by_ref1: " << num << endl;
    pass_by_ref1(num);
    cout << "num after calling pass_by_ref1: " << num << endl;

    string name {"Donald"};

    cout << "name before calling pass_by_ref2: " << name << endl;
    pass_by_ref2(name);
    cout << "name after calling pass_by_ref2: " << name << endl;

    vector<string> names {"Larry", "Joe", "Don"};

    cout << "names before calling pass_by_ref3: " << endl;
    print_vec(names);
    pass_by_ref3(names);
    cout << "names after calling pass_by_ref3: " << endl;
    print_vec(names);

    return 0;
}
