#ifndef _FUNCTIONS_CPP_
#define _FUNCTIONS_CPP_
#include "Functions.h"


template<typename T>
T determinant(const std::vector<std::vector<T>> &matrix)
{
    T det {0};
    if (matrix.size() == 1)
    {
        return matrix[0][0];
    }
    else if (matrix.size() == 2)
    {
        return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
    }
    else
    {
        for (size_t p{0}; p<matrix.size(); ++p)
        {
            std::vector<std::vector<T>> tmpMatrix;
            for (size_t i{1}; i<matrix.size(); ++i)
            {
                std::vector<T> tmpRow;
                for (size_t j{0}; j<matrix[0].size(); ++j)
                {
                    if (j != p)
                    {
                        tmpRow.push_back(matrix[i][j]);
                    }
                }
                if (tmpRow.size() > 0)
                    tmpMatrix.push_back(tmpRow);
            }
            det += (std::pow((-1), p % 2) * 
                    matrix[0][p] * 
                    determinant(tmpMatrix));
        }
        return det;
    }
}

#endif

