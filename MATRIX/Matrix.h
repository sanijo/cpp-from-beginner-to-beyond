#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>
#include "I_Print.h"
//#include "Functions.h"

template<typename T>
class Matrix: public I_Print 
{
private:
    static constexpr const T defInit_ = 0;
    static constexpr const size_t defColSize_ = 1;
    static constexpr const size_t defRowSize_ = 1;
    std::vector<std::vector<T>> matrix_;
    size_t rowSize_;
    size_t colSize_;
public:
    template<typename U>
    friend U determinant(const Matrix<U> &obj);
    template<typename U>
    friend Matrix<U> cofactor(const Matrix<U> &obj);
    template<typename U>
    friend Matrix<U> adjugate(const Matrix<U> &obj);
    template<typename U>
    friend Matrix<U> inverse(const Matrix<U> &obj);
    template<typename U>
    friend void solveInverseMethod(const Matrix<U> &obj, const std::vector<U> &vec);

    //constructors
    Matrix(size_t rowSize_=defRowSize_, size_t colSize_=defColSize_, T init_=defInit_);
    Matrix(size_t rowSize_, size_t colSize_, const T *input);
    Matrix(size_t rowSize_, size_t colSize_, const std::vector<T> &input);
    Matrix(const std::vector<std::vector<T>> &input);
    Matrix(const char *fileName_, const char *delimiter);
    Matrix(const std::string &fileName_, const char delimiter=',');
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
    T &operator()(const size_t &row, const size_t &col);
    const T &operator()(const size_t &row, const size_t &col) const;

    //getters
    size_t getRows() const;
    size_t getCols() const;
    std::vector<std::vector<T>> getData() const;
    
    //setters 
    void set_element(size_t i, size_t j, T val);
    
    //virtual
    virtual void print(std::ostream &os) const override;

    //default destructor
    virtual ~Matrix() = default;


};

#include "Matrix.cpp"

#endif

