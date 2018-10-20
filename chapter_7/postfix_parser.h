//
// Created by Raleigh Littles (raleigh) on 10/20/18 at 2:41 AM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//


#ifndef CHAPTER_7_POSTFIX_PARSER_H

#define CHAPTER_7_POSTFIX_PARSER_H

#include <string>
#include <stack>
#include <vector>
#include <array>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cassert>

class PostfixParser {

public:

    /* Psuedo-code algorithm (Figure 7.10, page 380)
         * ----------------------------------------------
         * 1. Initialize a stack of double numbers
         * 2. do
         *      if (the next input is a number)
         *          read the next input and push it into the stack
         *
         *      else
         *          read the next character, which is an operation symbol
         *          use top() and pop() to get the two numbers off the stack
         *          combine these two numbers with the operation (using the second number popped as the left operand),
         *          and push the result onto the stack
         *
         *   while (there is more of the expression to read)
         *
         * 3. at this point, the stack contains one number, which is the value of the expression
         * */
    static double parse_postfix_expression(const std::string &expression) {
        std::vector<std::string> splitted_results;

        std::array<std::string, 4> possible_operators = {"+", "-", "*", "/"};

        std::stack<double> expression_stack;

        std::istringstream string_stream(expression);

        for (std::string ch; string_stream >> ch;) {
            if (std::find(possible_operators.begin(), possible_operators.end(), ch) != possible_operators.end()) {
                // all operators are binary operators, so they require two operands

                if (expression_stack.size() >= 2) {

                    double operand1 = expression_stack.top();
                    expression_stack.pop();

                    double operand2 = expression_stack.top();
                    expression_stack.pop();

                    // C++ doesn't have reflection, which would make this a lot easier, and case statements don't support strings..

                    double result;

                    if (ch == "+") {
                        result = operand2 + operand1;

                    } else if (ch == "*") {
                        result = operand2 * operand1;
                    } else if (ch == "-") {
                        result = operand2 - operand1;
                    } else if (ch == "/") {
                        result = operand2 / operand1;
                    } else {
                        std::cout << "The operation you entered ( " << ch << ") is not supported." << std::endl;
                        exit(1);
                    }

                    expression_stack.push(result);
                }
            } else {
                expression_stack.push(std::stod(ch));
            }
        }

        assert(expression_stack.size() == 1);

        return expression_stack.top();
    }

};

#endif //CHAPTER_7_POSTFIX_PARSER_H
