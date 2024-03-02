#include <iostream>
#include <string>

#include "../src/static_module/math_static.hpp"
#include "../src/dynamic_module/math_dynamic.hpp"


std::string print_function(int a, int b, std::string type) {
    std::string to_print = type;
    int result = 0;

    to_print = type + "(" + std::to_string(a) + ", " + std::to_string(b) + ") == ";
    if ("SUM" == type) {
        result = sum(a, b);
    }
    else if ("SUBSTRACT" == type) { 
        result = substract(a, b);
    }
    else if ("MULTIPLY" == type) { 
        result = multiply(a, b);
    }
    else if ("DIVIDE" == type) {
        result = divide(a, b);
    }
    to_print += std::to_string(result);

    return to_print;
}

int runTests(){
    try { std::cout << print_function(1, 2, "SUM") << std::endl; } catch(std::exception e) { return -1; }
    try { std::cout << print_function(2, 3, "SUBSTRACT") << std::endl; } catch(std::exception e) { return -1; }
    try { std::cout << print_function(4, 5, "MULTIPLY") << std::endl; } catch(std::exception e) { return -1; }
    try { std::cout << print_function(6, 7, "DIVIDE") << std::endl; } catch(std::exception e) { return -1; }
    try { std::cout << print_function(1, 0, "DIVIDE") << std::endl; } catch(std::exception e) { return -1; }
    return 0;
}


int main() {
    return runTests();
}