#include <iostream>
#include "expression_parser.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    const std::string my_expr = "5 3 2 * + 4 - 5 +";

    double result = ExpressionParser::parse_postfix_expression(my_expr);

    std::cout << result << std::endl;


    const std::string example_infix_expression = 

}
