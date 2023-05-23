#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <iterator> 
#include "Matrix.h"

template<typename U>
T determinant(const std::vector<std::vector<T>> &matrix);

#include "Functions.cpp"

#endif

