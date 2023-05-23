#include <fstream> // for file access
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cmath> // For Absolute function
#include "Matrix.h" // Matrix Class
#include <omp.h>

//int main(int argc, char *argv[]) {
//    
//    {
//    if (argc > 1)
//    {
//        std::cout << "argv[1] = " << argv[1] << std::endl;
//        std::cout << "argv[2] = " << argv[2] << std::endl;
//    }
//    else
//    {
//        std::cout << "No file name entered. Abort! Abort!";
//        return -1;
//    }
//    
//    //----------------------------------//
//    
//    // Initialization of A matrix
//     Matrix<double> A(argv[1], argv[2]);
//     std::cout << A << std::endl;
//    
//
//    
//    }
int main(){

//   std::cout << std::setprecision(3);
//   int a [] = {1,2,3,4,5,6,7,8,9};
//   Matrix<int> MA{3,3,a};

//    double a [] = {1,2,3,4,3,6,7,4,9,10,11,12,13,14,15,16,17,18,19,20,41,22,25,24,25};
//    Matrix<double> MA{5,5,a};
//
//   int a [] = {1,2,3,4};
//   Matrix<int> MA{2,2,a};
//    std::cout << MA << std::endl;
//
//    auto cof = cofactor(MA);
//    std::cout << cof << std::endl;
//    auto adj = adjugate(MA);
//    std::cout << adj << std::endl;
//    
//    auto inv = inverse(MA);
//    std::cout << inv << std::endl;
//    std::cout << std::fixed << MA * inv << std::endl;
    
    //solution: 108.32464864864865, 59.01610810810811, 83.67037837837837
    std::vector<double> vec {117.57,3.544,0};
    double m [] = {1.25,-0.125,-0.125,-0.75,2.5,-0.75,-0.5,-0.5,1};
    Matrix<double> MATRIX_A {3,3,m};
    solveInverseMethod(MATRIX_A, vec);
    
//    auto d = determinant(MA);
//    std::cout << d << std::endl;

//    std::string fn {"input.txt"};
//
//    Matrix<double> A(fn, ' ');
//    auto d = determinant(A);
//    std::cout << d << std::endl;

//    std::vector<double> v {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
//    Matrix<double> MV{2,3,v};
//    std::cout << MV << std::endl;

//    std::string fn {"input.txt"};
//
//    Matrix<double> A(fn, ' ');
//    std::cout << A << std::endl;
//    Matrix<double> B {A}; 
//
//    std::cout << (A *= 2) << std::endl;
//    std::cout << (A /= 2) << std::endl;
//    std::cout << (A -= 2) << std::endl;
//    std::cout << (A += 2) << std::endl;
//    
//    Matrix<double> C = A + B; 
//    
//    std::cout << (C *= A) << std::endl;
//    std::cout << (C -= B) << std::endl;
//    std::cout << (C += A) << std::endl;
//    
//    Matrix<int> X(3,3);
//    std::cout << X << std::endl;
//
//    Matrix<int> Y(3,3,2);
//    std::cout << Y << std::endl;



//    Matrix<double> A(3,3,1);
//    Matrix<double> B(3,3,1);
//
//    std::cout << A << std::endl;
//    std::cout << B << std::end;
//
//    A.set_element(0,0,1);
//    A.set_element(0,1,2);
//    A.set_element(0,2,3);
//    A.set_element(1,0,4);
//    A.set_element(1,1,5);
//    A.set_element(1,2,6);
//
//    std::cout << A << std::endl;
//
//    Matrix C = A + B;
//    std::cout << C << std::endl;
//    C = C + B;
//    std::cout << C << std::endl;
//    C = C + B;
//    std::cout << C << std::endl;
//
//    C = A.transpose();
//
//    std::cout << C << std::endl;
//
//    C = A + B;
//    std::cout << C << std::endl;
//
//    C += 1;
//    std::cout << C << std::endl;
//
//    C *= 2;
//    std::cout << C << std::endl;
//
//    C /= 2;
//    std::cout << C << std::endl;
//
//    C += B;
//    std::cout << C << std::endl;
//
//    C = A * B;
//    std::cout << C << std::endl;
//
//    C *= B;
//    std::cout << C << std::endl;
//
//    C = A - B;
//    std::cout << C << std::endl;
//
//    std::vector<double> v = C.diagonal_vec();
//    for (auto const &c: v)
//        std::cout << c << std::endl;


    return 0;
}
