#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>
#include <memory>
#include "I_Print.h"

template<typename T>
class Matrix: public I_Print 
{
    unsigned rowSize_;
    unsigned colSize_;
    std::vector<std::vector<T>> matrix_;
public:
    //constructors
    Matrix();
    Matrix(unsigned rowSize_, unsigned colSize_, const T &init_);
    Matrix(const char *fileName_);
    Matrix(const Matrix<T> &obj);
    
    /****member functions****/
    Matrix<T> &operator=(const Matrix<T> &rhs);
    //Matrix operators overloading
    Matrix<T> operator+(const Matrix<T> &rhs) const;
    Matrix<T> &operator+=(const Matrix<T> &rhs);
    Matrix<T> operator-(const Matrix<T> &rhs) const;
    Matrix<T> &operator-=(const Matrix<T> &rhs);
    Matrix<T> operator*(const Matrix<T> &rhs) const;
    Matrix<T> &operator*=(const Matrix<T> &rhs);
    //Transpose function
    Matrix<T> transpose();
    //Scalar operators overloading
    Matrix<T> operator+(const T &rhs);
    Matrix<T> &operator+=(const T &rhs);
    Matrix<T> operator-(const T &rhs);
    Matrix<T> &operator-=(const T &rhs);
    Matrix<T> operator*(const T &rhs);
    Matrix<T> &operator*=(const T &rhs);
    Matrix<T> operator/(const T &rhs);
    Matrix<T> &operator/=(const T &rhs);
    //Matrix/vector operators
    std::vector<T> operator*(const std::vector<T> &rhs);
    std::vector<T> diagonal_vec();

    //Access the individual elements of a matrix
    T &operator()(const unsigned &row, const unsigned &col);
    const T &operator()(const unsigned &row, const unsigned &col) const;

    //getters
    unsigned getRows() const;
    unsigned getCols() const;
    //setters 
    void set_element(unsigned i, unsigned j, T val);
    //virtual
    virtual void print(std::ostream &os) const override;

    //default destructor
    virtual ~Matrix() = default;


};

#include "Matrix.cpp"

#endif

