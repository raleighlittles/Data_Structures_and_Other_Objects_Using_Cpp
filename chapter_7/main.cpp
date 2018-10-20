#include <iostream>
#include "postfix_parser.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    const std::string my_expr = "5 3 2 * + 4 - 5 +";

    double result = PostfixParser::parse_postfix_expression(my_expr);
    
    std::cout << result << std::endl;

}
