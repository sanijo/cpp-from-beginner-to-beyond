#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void print_menu();
void selection_modify(char &s);
void case_p(const vector<int> &vec);
void case_a(vector<int> &vec);
void case_m(const vector<int> &vec);
void case_s(const vector<int> &vec);
void case_l(const vector<int> &vec);
void case_c(vector<int> &vec);
void case_q();
void case_default();
void switch_cases(char &s, vector<int> &vec);
void if_else_cases(char &s, vector<int> &vec);

void if_else_cases(char &s, vector<int> &vec)
{
   if (s == 'P')
   {
       case_p(vec);
   }
   else if (s == 'A')
   {
       case_a(vec);
   }
   else if (s == 'M')
   {
       case_m(vec);
   }
   else if (s == 'S')
   {
       case_s(vec);
   }
   else if (s == 'L')
   {
       case_l(vec);
   }
   else if (s == 'C')
   {
       case_c(vec);
   }
   else if (s == 'Q')
   {
       case_q();
   }
   else
   {
       case_default();
   }
}

void switch_cases(char &s, vector<int> &vec)
{
    switch (s)
    {
        case 'P':
        {
            case_p(vec);
            break;
        }
        case 'A':
        {
            case_a(vec);
            break;
        }
        case 'M':
        {
            case_m(vec);
            break;
        }
        case 'S':
        {
            case_s(vec);
            break;
        }
        case 'L':
        {
            case_l(vec);
            break;
        }
        case 'C':
        {
            case_c(vec);
            break;
        }
        case 'Q':
            case_q();
            break;
        default:
            case_default();
            break;
    }
}

void case_default()
{
    cout << "Not a valid option. Try again." << endl;
}

void case_q()
{
    cout << "Closing loop. Goodbye!" << endl;
}

void case_c(vector<int> &vec)
{
    cout << "Setting list to empty..." << endl;
    vec.clear();
}

void case_l(const vector<int> &vec)
{
    if (vec.size() == 0)
    {
        cout << "Unable to determine the largest number - empyt list." 
             << endl;
    }
    else if (vec.size() == 1)
    {
        cout << "Largest number in the list is: " << vec.at(0) << endl;
    }
    else
    {
    int large {};
    for (size_t i {}; i<vec.size(); i++)
    {
        if (i == 0)
        {
            (vec.at(i) < vec.at(i+1)) ? large=vec.at(i+1) : large=vec.at(i);
        }
        else
        {
            (vec.at(i) > large) ? large=vec.at(i) : large=large;
        }
    }
    cout << "Largest number in the list is: " << large << endl;
    }
}

void case_s(const vector<int> &vec)
{
    if (vec.size() == 0)
    {
        cout << "Unable to determine the smallest number - empyt list." 
             << endl;
    }
    else if (vec.size() == 1)
    {
        cout << "Smallest number in the list is: " << vec.at(0) << endl;
    }
    else
    {
    int small {};
    for (size_t i {}; i<vec.size(); i++)
    {
        if (i == 0)
        {
            (vec.at(i) < vec.at(i+1)) ? small=vec.at(i) : small=vec.at(i+1);
        }
        else
        {
            (vec.at(i) < small) ? small=vec.at(i) : small=small;
        }
    }
    cout << "Smallest number in the list is: " << small << endl;
    }
}

void case_m(const vector<int> &vec)
{
    if (vec.size() == 0)
    {
        cout << "Unable to calculate the mean - empyt list." 
             << endl;
    }
    else
    {
    int sum {};
    double mean {};
    for (auto v: vec)
    {
        sum += v;
    }
    mean = static_cast<double> (sum) / vec.size();
    cout << "Mean average of the elements: " << mean;
    }
}

void case_a(vector<int> &vec)
{
    int num {};
    cout << "Enter a number you want to add to the list: ";
    cin >> num;
    vec.push_back(num);
    cout << "Number " << num << " added to the list." << endl;
}

void case_p(const vector<int> &vec)
{
    cout << "\nElements of the list:" << endl;
    if (vec.size() == 0)
    {
        cout << "[] - the list is empty" << endl;
    }
    else
    {
        cout << "[";
        for (size_t i {}; i<vec.size(); i++)
        {
            if (i == vec.size()-1)
            {
                cout << vec.at(i);
            }
            else
            {
                cout << vec.at(i) << " ";
            }
        }
        cout << "]" << endl;
    }
}

void change_selection(char &s)
{
    char pom {};
    cout << "\nEnter your selection: ";
    cin >> pom;
    s = toupper(pom);
}

void print_menu()
{
    cout << "\n============================" << endl;
    cout << "P - print numbers" << endl;
    cout << "A - add numbers" << endl;
    cout << "M - display mean of the numbers" << endl;
    cout << "S - display the smallest number" << endl;
    cout << "L - display the largest number" << endl;
    cout << "C - clear list" << endl;
    cout << "Q - quit." << endl;
}


int main()
{
    char selection {};
    vector<int> vec {99,2,4,77};

    do
    {
        print_menu();
        change_selection(selection);
        //switch_cases(selection, vec);
        if_else_cases(selection, vec);
    }
    while (selection != 'Q');

    return 0;
}
