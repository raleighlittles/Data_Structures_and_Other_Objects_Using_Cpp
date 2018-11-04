#include <iostream>
#include "expression_parser.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    const std::string my_expr = "5 3 2 * + 4 - 5 +";

    double result = ExpressionParser::parse_postfix_expression(my_expr);

    std::cout << result << std::endl;

    std::cout << "----------------------" << std::endl;

    const std::string example_infix_expression = "( ( ( A + 7 ) * ( B / C ) ) - ( 2 * D ) )";

    std::string postfix_expression = ExpressionParser::convert_parenthesized_infix_to_postfix(example_infix_expression);

    std::cout << postfix_expression << std::endl;

    std::cout << "----------------------" << std::endl;

    const std::string example_general_infix_expression = "3 * X + ( Y - 12 ) - Z";

    postfix_expression = ExpressionParser::convert_general_infix_to_postfix(example_general_infix_expression);

    std::cout << postfix_expression << std::endl;

}

