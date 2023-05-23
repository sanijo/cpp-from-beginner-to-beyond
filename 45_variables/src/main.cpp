#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int room_width {0};
    int room_length {0};
    int room_height {0};
   
    string name {"ivan"}; 
    cout << name << endl;

    cout << "Enter the width of the room: " << endl;
    cin >> room_width;

    cout << "Enter the length of the room: " << endl;
    cin >> room_length;

    cout << "Enter the height of the room: " << endl;
    cin >> room_height;

    cout << "The room volume is: " << room_height*room_length*room_width << endl;

    return 0;
}
