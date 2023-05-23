#include<iostream>

using std::cin;
using std::cout;
using std::endl;

const double  pi {3.14159};

//Function prototypes-enables you not to worry about the function definition
//order
double calc_area_circle(double);
double calc_volume_cylinder(double, double);
void circle_area();
void cylinder_volume();

int main()
{
    circle_area();
    cylinder_volume();

    return 0;
}

double calc_area_circle(double r)
{
    return pi * r * r;
}

double calc_volume_cylinder(double r, double h)
{
    return calc_area_circle(r) * h;
}

void circle_area()
{
    double r {};
    cout << "\nEnter the radius of the circle in meters: ";
    cin >> r;

    cout << "The area of the circle with r = " << r 
         << "m is " << calc_area_circle(r) << "m^2" << endl;
}

void cylinder_volume()
{
    double r {}, h {};
    cout << "\nEnter the radius and height of the cylinder in meters: ";
    cin >> r >> h;

    cout << "The volume of the cylinder with r = " << r 
         << "m and h = " << h << "m is " << calc_volume_cylinder(r, h) 
         << "m^3" << endl;
}

