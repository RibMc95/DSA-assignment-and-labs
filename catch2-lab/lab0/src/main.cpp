#include <iostream>
#include "math_function.h"

int main()
{
    double num = 25.0;
    double results = compute_square_root(num);
    if (results != -1) {
        std::cout << "The square root of " << num << " is " << results << std::endl;
    } else {
        std::cout << "Invalid input. Please enter a non-negative number." << std::endl;
    }
    return 0;
}