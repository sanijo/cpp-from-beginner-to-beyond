#include <fstream> // for file access
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cmath> // For Absolute function
#include "Matrix.h" // Matrix Class

int main(int argc, char *argv[]) {

    {
    if (argc >= 1)
    {
        std::cout << "argv[1] = " << argv[1] << std::endl;
    }
    else
    {
        std::cout << "No file name entered. Abort! Abort!";
        return -1;
    }
    
    //----------------------------------//
    
    // Initialization of A matrix
    Matrix<double> A(argv[1]);
    std::cout << A << std::endl;
    int row = A.getRows();
    
    

    
    }
   // Matrix<double> A(3,3,1);

   // Matrix<double> B(3,3,1);

   // std::cout << A << std::endl;
   // std::cout << B << std::endl;

   // A.set_element(0,0,1);
   // A.set_element(0,1,2);
   // A.set_element(0,2,3);
   // A.set_element(1,0,4);
   // A.set_element(1,1,5);
   // A.set_element(1,2,6);

   // std::cout << A << std::endl;

   // Matrix C = A + B;
   // std::cout << C << std::endl;
   // C = C + B;
   // std::cout << C << std::endl;
   // C = C + B;
   // std::cout << C << std::endl;

   // Matrix C = A.transpose();

   // std::cout << C << std::endl;

   // C = A + B;
   // std::cout << C << std::endl;

   // C += 1;
   // std::cout << C << std::endl;

   // C *= 2;
   // std::cout << C << std::endl;

   // C /= 2;
   // std::cout << C << std::endl;

   // C += B;
   // std::cout << C << std::endl;

   // C = A * B;
   // std::cout << C << std::endl;

   // C *= B;
   // std::cout << C << std::endl;

   // C = A - B;
   // std::cout << C << std::endl;

    return 0;
}
