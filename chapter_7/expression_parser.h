//
// Created by raleigh on 11/4/18.
//

#ifndef CHAPTER_7_EXPRESSION_PARSER_H
#define CHAPTER_7_EXPRESSION_PARSER_H

#include <string>
#include <stack>
#include <vector>
#include <array>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <map>

class ExpressionParser {

public:

    static std::map<std::string, int> operators;

    static std::array<std::string, 3> possible_right_delimeters;

    static std::array<std::string, 3> possible_left_delimeters;

    static bool is_right_delimeter( std::string character);

    static bool is_left_delimeter( std::string character);

    /* TODO: Combine this and the method below into one method */
    static bool is_operator( std::string character);

    /* Is operator 1 a lower precedence than the 2nd operator? */
    static bool is_lower_precedence(const std::string &operator1, const std::string &operator2);

    /* See: Figure 7.10, page 380 */
    static double parse_postfix_expression(const std::string &expression);

    /* See: Figure 7.11, page 382 */
    static std::string convert_parenthesized_infix_to_postfix(const std::string &parenthesized_infix_expression);


    /* See: Figure 7.12, page 385 */
    static std::string convert_general_infix_to_postfix(const std::string &infix_expression);

};


#endif //CHAPTER_7_EXPRESSION_PARSER_H
