#ifndef _MATRIX_CPP_
#define _MATRIX_CPP_
#include "Matrix.h"

/*****************************BEGIN CONSTRUCTORS*******************************/

//Parameters constructor
template<typename T>
Matrix<T>::Matrix(size_t rowSize_, size_t colSize_, T init_):
    rowSize_{rowSize_}, colSize_{colSize_}
{
    matrix_.resize(rowSize_);
    for (size_t i {0}; i<matrix_.size(); ++i)
    {
        matrix_[i].resize(colSize_, static_cast<T>(init_));
    }
}

//Construct from 1D array
template<typename T>
Matrix<T>::Matrix(size_t rowSize_, size_t colSize_, const T *input):
    rowSize_{rowSize_}, colSize_{colSize_}
{
    matrix_.resize(rowSize_);
    for (size_t i {0}; i<matrix_.size(); ++i)
    {
        matrix_[i].resize(colSize_);
    }
    size_t loc {0};
    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            matrix_[i][j] = input[loc];
            ++loc;
        }
    }
}

//Construct from 1D vector
template<typename T>
Matrix<T>::Matrix(size_t rowSize_, size_t colSize_, const std::vector<T> &input):
    rowSize_{rowSize_}, colSize_{colSize_}
{
    matrix_.resize(rowSize_);
    for (size_t i {0}; i<matrix_.size(); ++i)
    {
        matrix_[i].resize(colSize_);
    }
    size_t loc {0};
    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            matrix_[i][j] = input[loc];
            ++loc;
        }
    }
}

//Construct from 2D vector
template<typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>> &input):
    matrix_{input}
{
    rowSize_ = input.size();
    colSize_ = input[0].size();
}

//Read from file constructor - main with parameters version
template<typename T>
Matrix<T>::Matrix(const char *fileName_, const char *delimiter)
{
    std::ifstream file_(fileName_); 

    size_t cols {0};
    size_t rows {0};

    std::string line_ {};
    T element_ {};
    std::vector<T> vec {};

    if (file_.is_open() && file_.good())
    {
        std::cout << "File is opened" << std::endl;
        while(std::getline(file_, line_))
        {
            rows += 1;
            std::stringstream stream_(line_);
            cols = 0;
            while (std::getline(stream_, line_, *delimiter))
            {
                std::stringstream stream_(line_);
                ++cols;
                while (1)
                {
                    stream_ >> element_;
                    if (!stream_)
                        break;
                    vec.push_back(element_);
                }
            }
        }
    }
    else
    {
        std::cout << "Failed to open file" << std::endl;
    }

    int loc {0};
    matrix_.resize(rows);
    for (size_t i{0}; i<=matrix_.size(); ++i)
    {
        matrix_[i].resize(cols);
    }
    for (size_t i{0}; i<rows; ++i)
    {
        for (size_t j{0}; j<cols; ++j)
        {
            matrix_[i][j] = vec.at(loc);
            ++loc;
        }
    }
    colSize_ = cols;
    rowSize_ = rows;
}

//Read from file constructor - no parameters main version
template<typename T>
Matrix<T>::Matrix(const std::string &fileName_, const char delimiter)
{
    std::ifstream file_(fileName_); 

    size_t cols {0};
    size_t rows {0};

    std::string line_ {};
    T element_ {};
    std::vector<T> vec {};

    if (file_.is_open() && file_.good())
    {
        std::cout << "File is opened" << std::endl;
        while(std::getline(file_, line_))
        {
            rows += 1;
            std::stringstream stream_(line_);
            cols = 0;
            while (std::getline(stream_, line_, delimiter))
            {
                std::stringstream stream_(line_);
                ++cols;
                while (1)
                {
                    stream_ >> element_;
                    if (!stream_)
                        break;
                    vec.push_back(element_);
                }
            }
        }
    }
    else
    {
        std::cout << "Failed to open file" << std::endl;
    }

    int loc {0};
    matrix_.resize(rows);
    for (size_t i{0}; i<=matrix_.size(); ++i)
    {
        matrix_[i].resize(cols);
    }
    for (size_t i{0}; i<rows; ++i)
    {
        for (size_t j{0}; j<cols; ++j)
        {
            matrix_[i][j] = vec.at(loc);
            ++loc;
        }
    }
    colSize_ = cols;
    rowSize_ = rows;
}

//Copy constructor
template<typename T>
Matrix<T>::Matrix(const Matrix<T> &rhs):
    matrix_{rhs.matrix_},
    rowSize_{rhs.rowSize_},
    colSize_{rhs.colSize_}
{}

/******************************END CONSTRUCTORS********************************/


/***************************BEGIN MEMBER FUNCTIONS*****************************/
//operator = overloading
template<typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &rhs) 
{
    if (this == &rhs)
        return *this;

    size_t new_rows = rhs.getRows();
    size_t new_cols = rhs.getCols();

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


/*************************MATRIX OPERATOR OVERLOADING**************************/
//Operator +
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const
{
    Matrix<T> result(rowSize_, colSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for(size_t j{0}; j<colSize_; ++j)
        {
            result(i,j) = this->matrix_[i][j] + rhs(i,j);
        }
    }

    return result;
}

//Operator +=
template<typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{
    *this = *this + rhs;
    return *this;
}

//Operator -
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) const
{
    Matrix<T> result(rowSize_, colSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for(size_t j{0}; j<colSize_; ++j)
        {
            result(i,j) = this->matrix_[i][j] - rhs(i,j);
        }
    }

    return result;
}

//Operator -=
template<typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)
{
    *this = *this - rhs;
    return *this;
}

//Operator *
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) const
{
    size_t rows = rhs.getRows();
    size_t cols = rhs.getCols();
    Matrix<T> result(rows, cols, 0.0);

    if (this->colSize_ == rhs.getRows())
    {
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
    else
        throw "Columns number of matrix A is not equal to row numbers of B";
}

//Operator *=
template<typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &rhs)
{
    *this = *this * rhs;
    return *this;
}
/*************************MATRIX OPERATOR OVERLOADING**************************/

/****************************MANIPULATION FUNCTIONS****************************/
//Matrix transpose
template<typename T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix<T> result(colSize_, rowSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            result(j, i) = this->matrix_.at(i).at(j);
        }
    }
    return result;
}
/****************************MANIPULATION FUNCTIONS****************************/

/*********************MATRIX/SCALAR OPERATOR OVERLOADING***********************/
//Operator +
template<typename T>
Matrix<T> Matrix<T>::operator+(const T &rhs)
{
    Matrix<T> result(rowSize_, colSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            result(i,j) = this->matrix_[i][j] + rhs;
        }
    }

    return result;
}

//Operator +=
template<typename T>
Matrix<T> &Matrix<T>::operator+=(const T &rhs)
{
    *this = *this + rhs;
    return *this;
}

//Operator -
template<typename T>
Matrix<T> Matrix<T>::operator-(const T &rhs)
{
    Matrix<T> result(rowSize_, colSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            result(i,j) = this->matrix_[i][j] - rhs;
        }
    }

    return result;
}

//Operator -=
template<typename T>
Matrix<T> &Matrix<T>::operator-=(const T &rhs)
{
    *this = *this - rhs;
    return *this;
}

//Operator *
template<typename T>
Matrix<T> Matrix<T>::operator*(const T &rhs)
{
    Matrix<T> result(rowSize_, colSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            result(i,j) = this->matrix_[i][j] * rhs;
        }
    }

    return result;
}

//Operator *=
template<typename T>
Matrix<T> &Matrix<T>::operator*=(const T &rhs)
{
    *this = *this * rhs;
    return *this;
}

//operator /
template<typename T>
Matrix<T> Matrix<T>::operator/(const T &rhs)
{
    Matrix<T> result(rowSize_, colSize_, 0.0);

    for (size_t i{0}; i<rowSize_; ++i)
    {
        for (size_t j{0}; j<colSize_; ++j)
        {
            result(i,j) = this->matrix_[i][j] / rhs;
        }
    }

    return result;
}

//Operator /=
template<typename T>
Matrix<T> &Matrix<T>::operator/=(const T &rhs)
{
    *this = *this / rhs;
    return *this;
}
/*********************MATRIX/SCALAR OPERATOR OVERLOADING***********************/


/*******************MATRIX/VECTOR OPERATORS AND FUNCTIONS**********************/
//Operator *
template<typename T>
std::vector<T> Matrix<T>::operator*(const std::vector<T> &rhs)
{
    if (colSize_ == rhs.size())
    {
        std::vector<T> result(rhs.size(), 0.0);

        for (size_t i{0}; i<rowSize_; ++i)
        {
            for (size_t j{0}; j<colSize_; ++j)
            {
                result.at(i) += this->matrix_.at(i).at(j) * rhs.at(j);
            }
        }
        return result;
    }
    else
        throw "Columns number of matrix A is not equal to row numbers of v";
}

//Get matrix diagonal vector
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
/*******************MATRIX/VECTOR OPERATORS AND FUNCTIONS**********************/

/********************************GET FUNCTIONS*********************************/
//Get nuber of matrix rows
template<typename T>
size_t Matrix<T>::getRows() const
{
    return this->rowSize_;
}

//Get number of matrix columns
template<typename T>
size_t Matrix<T>::getCols() const
{
    return this->colSize_;
}

//Access individual elements 1
template<typename T>
T &Matrix<T>::operator()(const size_t &row, const size_t &col)
{
    return this->matrix_.at(row).at(col);
}

//Access individual elements 1
template<typename T>
const T &Matrix<T>::operator()(const size_t &row, const size_t &col) const
{
    return this->matrix_.at(row).at(col);
}

template<typename T>
std::vector<std::vector<T>> Matrix<T>::getData() const
{
    return this->matrix_;
}
/********************************GET FUNCTIONS*********************************/

/********************************SET FUNCTIONS*********************************/
//Set element to some value
template<typename T>
void Matrix<T>::set_element(size_t i, size_t j, T val)
{
    this->matrix_.at(i).at(j) = val;
}
/********************************SET FUNCTIONS*********************************/

/********************************OVERLOADED <<*********************************/
//Overloaded <<
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
/********************************OVERLOADED <<*********************************/

/******************************FRIEND FUNCTIONS********************************/
template<typename T>
T determinant(const Matrix<T> &obj)
{
    if (obj.rowSize_ == obj.colSize_)
    {
        T det {0};
        if (obj.matrix_.size() == 1)
        {
            return obj.matrix_[0][0];
        }
        else if (obj.matrix_.size() == 2)
        {
            return (obj.matrix_[0][0] * obj.matrix_[1][1] -
                    obj.matrix_[1][0] * obj.matrix_[0][1]);
        }
        else
        {
            for (size_t p{0}; p<obj.matrix_.size(); ++p)
            {
                std::vector<std::vector<T>> tmpMatrix;
                for (size_t i{1}; i<obj.matrix_.size(); ++i)
                {
                    std::vector<T> tmpRow;
                    for (size_t j{0}; j<obj.matrix_[0].size(); ++j)
                    {
                        if (j != p)
                        {
                            tmpRow.push_back(obj.matrix_[i][j]);
                        }
                    }
                    if (tmpRow.size() > 0)
                        tmpMatrix.push_back(tmpRow);
                }
                Matrix tmpMatrixObj {tmpMatrix};
                det += (std::pow((-1), p % 2) * 
                        obj.matrix_[0][p] * 
                        determinant(tmpMatrixObj));
            }
            return det;
        }
    } 
    else
        throw "Row size != column size";
}

//Calculate cofactor matrix C
template<typename T>
Matrix<T> cofactor(const Matrix<T> &obj)
{
    if (obj.rowSize_ == obj.colSize_)
    {
        if (obj.matrix_.size() == 1)
        {
            if (obj.matrix_[0][0] == 0)
            {
                T var [] = {0};
                Matrix<T> cof {1,1, var};
                return cof;
            }
            else
            {
                T var [] = {1};
                Matrix<T> cof {1,1, var};
                return cof;
            }
        }
        else if (obj.matrix_.size() == 2)
        {
            T var [] = {obj.matrix_[1][1], -obj.matrix_[0][1],
                        -obj.matrix_[1][0], obj.matrix_[0][0]};
            Matrix<T> cof {2,2,var};
            return cof;
        }
        else
        {
            Matrix tmpMatrix {obj};
            T cofEl {0};
            std::vector<T> cofactors;
            for (size_t i{0}; i<obj.matrix_.size(); ++i)
            {
                for (size_t j{0}; j<obj.matrix_.size(); ++j)
                {
                    tmpMatrix.matrix_.erase(tmpMatrix.matrix_.begin()+i);
                    for (auto &row: tmpMatrix.matrix_)
                    {
                        row.erase(row.begin() + j);
                    }
//                    std::cout << "\n";                                                      
//                    for (auto &v: tmpMatrix.matrix_)                                                      
//                    {                                                                       
//                        for (auto &vv: v)                                                   
//                        {                                                                   
//                            std::cout << vv << " ";                                         
//                        }                                                                   
//                        std::cout << std::endl;                                             
//                    }
                    cofEl = std::pow((-1), (i+j))  * determinant(tmpMatrix);
//                    std::cout << cofEl << std::endl;
                    cofactors.push_back(cofEl);
                    tmpMatrix = obj;
                }
            }

            Matrix<T> cof {obj.rowSize_, obj.colSize_, cofactors};

            return cof;
        }
    } 
    else
        throw "Row size != column size";
}

//Calculate adjugate matrix adj(A) = C^T
template<typename T>
Matrix<T> adjugate(const Matrix<T> &obj)
{
    auto adj = cofactor(obj);

    return adj.transpose();
}

//Calculate inverse matrix A^-1=(1/det(A))*adj(A)
template<typename T>
Matrix<T> inverse(const Matrix<T> &obj)
{
    auto det = determinant(obj);
    if (det != 0)
    {
        auto inv = adjugate(obj) * (1/det);

        return inv;
    }
    else
        throw "Matrix determinant =0";

}

template<typename T>
void solveInverseMethod(const Matrix<T> &obj,const std::vector<T> &vec)
{
    auto solution = inverse(obj) * vec;

    for (size_t i{0}; i<solution.size(); ++i)
    {
        std::cout << "x" << (i+1) << " = " << solution[i] << " ";
    }
    std::cout << std::endl;
}
/******************************FRIEND FUNCTIONS********************************/




















/****************************END MEMBER FUNCTIONS******************************/
#endif
