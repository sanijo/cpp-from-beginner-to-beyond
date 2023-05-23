#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    char selection {};
    vector<int> vec {99,2,4,77};

    do
    {
        cout << "\n============================" << endl;
        cout << "P - print numbers" << endl;
        cout << "A - add numbers" << endl;
        cout << "M - display mean of the numbers" << endl;
        cout << "S - display the smallest number" << endl;
        cout << "L - display the largest number" << endl;
        cout << "C - clear list" << endl;
        cout << "Q - quit." << endl;
        cout << "\nEnter your selection: ";
        cin >> selection;
        
        switch (selection)
        {
            case 'p':
            case 'P':
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
                break;
            }
            case 'a':
            case 'A':
            {
                int num {};
                cout << "Enter a number you want to add to the list: ";
                cin >> num;
                vec.push_back(num);
                cout << "Number " << num << " added to the list." << endl;
                break;
            }
            case 'm':
            case 'M':
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
                break;
            }
            case 's':
            case 'S':
            {
                if (vec.size() == 0)
                {
                    cout << "Unable to determine the smallest number - empyt list." 
                         << endl;
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
                break;
            }
            case 'l':
            case 'L':
            {
                if (vec.size() == 0)
                {
                    cout << "Unable to determine the largest number - empyt list." 
                         << endl;
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
                break;
            }
            case 'c':
            case 'C':
            {
                cout << "Setting list to empty..." << endl;
                vec.clear();
                break;
            }
            case 'q':
            case 'Q':
                cout << "Closing loop. Goodbye!" << endl;
                break;
            default:
                cout << "Sorry not a valid option!" << endl;
                break;
        }
    }
    while (selection != 'q' && selection != 'Q');

    return 0;
}
