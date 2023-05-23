#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;
using std::string;

int main()
{
    
    string s0;
    string s1 {"apple"};
    string s2 {"banana"};
    string s3 {"kiwi"};
    string s4 {"Apple"};
    string s5 {s1};
    string s6 {s1, 0, 3};
    string s7 (10, 'X');

    //initialization
    cout << "\nInitialization:" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s4: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;
    cout << "s6: " << s6 << endl;
    cout << "s7: " << s7 << endl;

    //comparison
    cout << boolalpha;
    cout << "\nComparison:" << endl;
    cout << s1 << " == " << s5 << ": " << (s1 == s5) << endl;
    cout << s1 << " == " << s2 << ": " << (s1 == s2) << endl;
    cout << s1 << " != " << s2 << ": " << (s1 != s2) << endl;
    cout << s1 << " < " << s2 << ": " << (s1 < s2) << endl;

    //assignment
    cout << "\nAssignment:" << endl;
    s1 = "watermelon";
    cout << "s1 is now: " << s1 << endl;
    s2 = s1;
    cout << "s2 is now: " << s2 << endl;
    s3[0] = 'M';
    cout << "s3 is now: " << s3 << endl;

    //concatenation
    s3 = s2 + " and " + s4;
    cout << "\nConcatenation: " << endl;
    cout << "s3 is now: " << s3 << endl;

    //looping
    cout << "\nLooping:" << endl;
    for (size_t i {0}; i < s3.length(); ++i)
    {
        cout << "Element " << i << " of " << s3 << " is:" << s3.at(i) << endl;  
    }
    cout << "\nRange based looping:" << endl;
    for (char i: s3)
    {
        cout << "Element " << i << endl;  
    }
    
    //substring
    cout << "\nSubstring:" << endl;
    s1 = "This is a test";
    cout << s1.substr(0,4) << endl;
    cout << s1.substr(5,2) << endl;
    cout << s1.substr(10,4) << endl;

    //erase
    cout << "\nErase:" << endl;
    s1.erase(0,5);
    cout << "This is s1 now: " <<  s1 << endl;

    //getline
    cout << "\nGetline:" << endl;
    string full_name {};
    cout << "Enter your full name: ";
    getline(cin, full_name);
    cout << "You entered: " << full_name << endl;

    //find
    s1 = "The secret word is Boo";
    string word {};

    cout << "Enter the word you want to find: ";
    getline(cin, word);

    size_t position = s1.find(word);
    if (position != string::npos)
        cout << "Found " << word << " at position " << position << endl;
    else
        cout << "Sorry, " << word << " not found." << endl;

    return 0;
}
