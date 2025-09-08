#include "math_function.h"
#include <cmath>

double compute_square_root(double number) {
    if (number < 0) 
    {
        return -1; 
    }
    return std::sqrt(number);
}
