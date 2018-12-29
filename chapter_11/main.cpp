#include <iostream>

int main() {
    double base = 10;
    double number = 832;
    double result = TreeProjects::logb(base, number);
    std::cout << result << std::endl;
    // prints: 2.92012
}