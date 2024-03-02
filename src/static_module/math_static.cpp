#include "math_static.hpp"

#include <stdexcept>
#include <string>


int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (0 == b) {
        const std::string err = "Cannot divide by 0. Input: divide(" + std::to_string(a) + ", " + std::to_string(b) + ")";
        throw std::invalid_argument(err);
    }

    return static_cast<int>(a / b);
}