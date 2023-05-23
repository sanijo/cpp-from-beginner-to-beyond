#ifndef _MATRIX_CPP_
#define _MATRIX_CPP_
#include "Matrix.h"

//Default constructor
template<typename T>
Matrix<T>::Matrix(){}

template<typename T>
Matrix<T>::Matrix(unsigned rowSize_, unsigned colSize_, const T &init_):
    rowSize_{rowSize_}, colSize_{colSize_}
{
    matrix_.resize(rowSize_);
    for (size_t i {0}; i<matrix_.size(); ++i)
    {
        matrix_[i].resize(colSize_, init_);
    }
}

//Read from file constructor
template<typename T>
Matrix<T>::Matrix(const char *fileName_)
{
    std::ifstream file_(fileName_); 

    unsigned cols {0};
    unsigned rows {0};

    std::string line_ {};
    int loc {0};
    T element_;
    T *vec {nullptr};
    //std::shared_ptr<T> vec;

    if (file_.is_open() && file_.good())
    {
        std::cout << "File is opened" << std::endl;
        while(std::getline(file_, line_))
        {
            ++rows;
            std::stringstream stream_(line_);
            cols = 0;
            while (1)
            {
                stream_ >> element_;
                if (!stream_)
                    break;
                ++cols;
                //std::shared_ptr<T> tmp = std::make_shared<T>(loc+1);
                T *tmp = new T[loc+1];
                //std::copy(vec, vec+loc, tmp);
                std::copy(vec, vec+loc, tmp);
                tmp[loc] = element_; 
                vec = tmp;
                ++loc;
                delete [] tmp;
            }
        }
    }
    else
    {
        std::cout << "Failed to open file" << std::endl;
    }
    loc = 0;
    matrix_.resize(rows);
    for (size_t i{0}; i<=matrix_.size(); ++i)
    {
        matrix_[i].resize(cols);
    }
    for (size_t i{0}; i<rows; ++i)
    {
        for (size_t j{0}; j<cols; ++j)
        {
            matrix_[i][j] = vec[loc];
            ++loc;
        }
    }
    colSize_ = cols;
    rowSize_ = rows;
    delete [] vec;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &rhs):
    matrix_{rhs.matrix_},
    rowSize_{rhs.rowSize_},
    colSize_{rhs.colSize_}
{}

template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &rhs) 
{
    if (this == &rhs)
        return *this;

    unsigned new_rows = rhs.getRows();
    unsigned new_cols = rhs.getCols();

    matrix_.resize(new_rows);
    for (size_t i{0}; i<matrix_.size(); ++i)
    {
        matrix_[i].resize(new_cols);
    }

    for (size_t i{0}; i<new_rows; ++i)
    {
        for (size_t j{0}; j<new_cols; ++j)
        {
           matrix_[i][j] = rhs(i,j);
        }
    }
    rowSize_ = new_rows;
    colSize_ = new_cols;

    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const
{
    Matrix result(rowSize_, colSize_, 0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for(size_t j{0}; j<colSize_; ++j)
        {
            result(i,j) = this->matrix_[i][j] + rhs(i,j);
        }
    }

    return result;
}

template<typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{
    *this = *this + rhs;
    return *this;
}


template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) const
{
    Matrix result(rowSize_, colSize_, 0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for(size_t j{0}; j<colSize_; ++j)
        {
            result(i,j) = this->matrix_[i][j] - rhs(i,j);
        }
    }

    return result;
}

template<typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)
{
    *this = *this - rhs;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) const
{
    unsigned rows = rhs.getRows();
    unsigned cols = rhs.getCols();
    Matrix result(rows, cols, 0);

    for (size_t i{0}; i<rows; ++i)
    {
        for (size_t j{0}; j<cols; ++j)
        {
            for (size_t k{0}; k<rows; ++k)
            {
                result(i,j) += this->matrix_[i][k] * rhs(k,j);
            }
        }
    }
    return result;
}

template<typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &rhs)
{
    *this = *this * rhs;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix result(colSize_, rowSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            result(j, i) = this->matrix_.at(i).at(j);
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const T &rhs)
{
    Matrix result(rowSize_, colSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            result(i,j) = this->matrix_[i][j] + rhs;
        }
    }

    return result;
}

template<typename T>
Matrix<T> &Matrix<T>::operator+=(const T &rhs)
{
    *this = *this + rhs;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T &rhs)
{
    Matrix result(rowSize_, colSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            result(i,j) = this->matrix_[i][j] - rhs;
        }
    }

    return result;
}

template<typename T>
Matrix<T> &Matrix<T>::operator-=(const T &rhs)
{
    *this = *this - rhs;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T &rhs)
{
    Matrix result(rowSize_, colSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            result(i,j) = this->matrix_[i][j] * rhs;
        }
    }

    return result;
}

template<typename T>
Matrix<T> &Matrix<T>::operator*=(const T &rhs)
{
    *this = *this * rhs;
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T &rhs)
{
    Matrix result(rowSize_, colSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            result(i,j) = this->matrix_[i][j] / rhs;
        }
    }

    return result;
}

template<typename T>
Matrix<T> &Matrix<T>::operator/=(const T &rhs)
{
    *this = *this / rhs;
    return *this;
}

template<typename T>
std::vector<T> Matrix<T>::operator*(const std::vector<T> &rhs)
{
    std::vector<T> result(rhs.size(), 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            result.at(i) = this->matrix_.at(i).at(j) * rhs.at(i);
        }
    }
    return result;
}

template<typename T>
std::vector<T> Matrix<T>::diagonal_vec()
{
    std::vector<T> result(rowSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        result.at(i) = this->matrix_.at(i).at(i);
    }
    return result;
}

template<typename T>
unsigned Matrix<T>::getRows() const
{
    return this->rowSize_;
}

template<typename T>
T &Matrix<T>::operator()(const unsigned &row, const unsigned &col)
{
    return this->matrix_.at(row).at(col);
}

template<typename T>
const T &Matrix<T>::operator()(const unsigned &row, const unsigned &col) const
{
    return this->matrix_.at(row).at(col);
}

template<typename T>
unsigned Matrix<T>::getCols() const
{
    return this->colSize_;
}

template<typename T>
void Matrix<T>::set_element(unsigned i, unsigned j, T val)
{
    this->matrix_.at(i).at(j) = val;
}

template<typename T>
void Matrix<T>::print(std::ostream &os) const
{    
    os << "==============Matrix==============" << std::endl;
    for (size_t i{0}; i<rowSize_; ++i) 
    {
        for (size_t j{0}; j<colSize_; ++j) 
        {
            os << matrix_.at(i).at(j) << " ";
                
        }
        os << std::endl;
    }
}


















#endif
