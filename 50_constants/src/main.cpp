#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{

    cout << "\nWelcome to Frank's Carpet Cleaning Service\n" << endl;

    //Prompt the user to enter the number of rooms
    cout << "How many small rooms would you like cleaned? ";
    int number_of_small_rooms {0};
    cin >> number_of_small_rooms;
    cout << "How many large rooms would you like cleaned? ";
    int number_of_large_rooms {0};
    cin >> number_of_large_rooms;

    const double price_per_small_room {25.0};
    const double price_per_large_room {35.0};
    const double sales_tax {0.06};
    const int estimate_expiry {30};

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << number_of_small_rooms << endl;
    cout << "Number of large rooms: " << number_of_large_rooms << endl;
    cout << "Price per small room: $" << price_per_small_room << endl;
    cout << "Price per large room: $" << price_per_large_room << endl;
    cout << "Cost: $" 
         << (price_per_small_room*number_of_small_rooms)+
            (price_per_large_room*number_of_large_rooms) << endl;
    cout << "Tax: $" 
         << (price_per_small_room*number_of_small_rooms*sales_tax)+
            (price_per_large_room*number_of_large_rooms*sales_tax) << endl;
    cout << "=========================================" << endl;
    cout << "Total estimate: $" 
         << (price_per_small_room*number_of_small_rooms)+
            (price_per_small_room*number_of_small_rooms*sales_tax)+
            (price_per_large_room*number_of_large_rooms)+
            (price_per_large_room*number_of_large_rooms*sales_tax) << endl;
    cout << "This estimate is valid for " << estimate_expiry << " days."
         << endl;



    return 0;
}
