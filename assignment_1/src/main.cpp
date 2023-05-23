#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    //Get input
    string in {};
    cout << "Enter your string: ";
    getline(cin, in);
    
    //Main for loop - output for every row
    for(size_t line {1}; line <= in.length(); ++line)
    {
        //Display leading spaces for each row using string variable
        string tmp(in.length()-line, ' ');
        cout << tmp;
        //Check if input is 1 symbol, if yes, print only that symbol
        if (in.length() <= 1)
        {
            cout << in;
        }
        //if input > 1 symbol
        else 
        {
            //for loop used for printing symbols in each line
            for(size_t i {0}, j {line-1}; i < ((2*line)-1); ++i)
            {
                //print in.at(i) if index i < line index, otherwise print in 
                //reverse order
                if (i < line)
                {
                    cout << in.at(i);
                }
                else
                {
                    --j;
                    cout << in.at(j); 
                }
            }
        }
        cout << endl;
    }

    return 0;
}
