#include<iostream>
#include<cstring> // for c-style string functions
//#include<cctpye> // for character-based functions

using namespace std;

int main()
{
    //char first_name [20] {};
    //char last_name [20] {};
    //char full_name [50] {};
    //char temp [50];

    //cout << "Enter first name: ";
    //cin >> first_name;
    //cout << "------------------------" << endl;
    //cout << "Enter last name: ";
    //cin >> last_name;
    //cout << "------------------------" << endl;

    //cout << "Hello, " << first_name << " your first name has " 
    //     << strlen(first_name) << " characters," << endl;
    //cout << "and your last name, " << last_name << " has " 
    //     << strlen(last_name) << " characters." << endl;

    //strcpy(full_name, first_name);
    //strcat(full_name, " ");
    //strcat(full_name, last_name);
    //cout << "Your full name is " << full_name <<endl;

    char first_name [] {"Bjarne"};
    char last_name [] {"Stroustrup"};
    char whole_name [50] {};
    
    size_t first_name_length {strlen(first_name)};
    size_t last_name_length {strlen(last_name)};
    
    strcpy(whole_name, first_name);
    strcat(whole_name, last_name);
    
    size_t whole_name_length {strlen(whole_name)};
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << "The length of the first name, " << first_name << ", is " 
         << first_name_length 
         << " letters long and the length of the last name, " 
         << last_name << ", is " << last_name_length 
         << " letters long. This means that the length of the whole name must be " 
         << whole_name_length << " letters long.";

    return 0;
}
