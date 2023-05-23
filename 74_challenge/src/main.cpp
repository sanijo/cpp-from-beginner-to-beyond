#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int number_of_cents {};
    bool flag = false;
    while (flag==false)
    {
        cout << "\nEnter an integer representing the number of cents: ";
        cin >> number_of_cents;
        if (number_of_cents>=0)
        {
            flag = true;
            break;
        }
        else
        {
            cout << "\nYou entered negative number.";
        }
    }
    cout << "\nNumber of cents entered: " << number_of_cents;

    int dollars {}, quarters {}, dimes {}, nickles {}, pennies {}, residue {};
    const int dol {100}, qua {25}, dim {10}, nic {5}, pen {1};

    ////Solution 1
    //if (number_of_cents>=dol)
    //{
    //    dollars = number_of_cents / dol;
    //    residue = number_of_cents % dol;
    //    cout << "\nresidue dol: " << residue;
    //    if (residue>=qua)
    //    {
    //        quarters = residue / qua;
    //        residue = residue % qua;
    //    }
    //    cout << "\nresidue qua: " << residue;
    //    if(residue>=dim)
    //    {
    //        dimes = residue / dim;
    //        residue = residue % dim;
    //    }
    //    cout << "\nresidue dim: " << residue;
    //    if(residue>=nic)
    //    {
    //        nickles = residue / nic;
    //        residue = residue % nic;
    //    }
    //    cout << "\nresidue nic: " << residue;
    //    pennies = residue / pen;
    //}

    //if (number_of_cents<dol)
    //{
    //    quarters = number_of_cents / qua;
    //    residue = number_of_cents % qua;
    //    cout << "\nresidue qua: " << residue;
    //    if(residue>=dim)
    //    {
    //        dimes = residue / dim;
    //        residue = residue % dim;
    //        cout << "\nresidue dim: " << residue;
    //    }
    //    if(residue>=nic)
    //    {
    //        nickles = residue / nic;
    //        residue = residue % nic;
    //        cout << "\nresidue nic: " << residue;
    //    }
    //    pennies = residue / pen;
    //}

    ////Solution 2

    dollars = number_of_cents / dol;
    residue = number_of_cents % dol;

    quarters = residue / qua;
    residue %= qua;

    dimes = residue / dim;
    residue %= dim;

    nickles = residue / nic;
    residue %= nic;

    pennies = residue;

    cout << "\n==========================================";
    cout << "\ndollars: " << dollars 
         << "\nquarters: " << quarters 
         << "\ndimes:   " << dimes
         << "\nnickles: " << nickles
         << "\npennies: " << pennies;
    cout << "\n==========================================" << endl;

    return 0;
}
