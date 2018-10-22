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

class ExpressionParser {

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
    static double parse_postfix_expression(const std::string &expression)
    {
        //std::vector<std::string> splitted_results;

        ExpressionParser::possible_operators = {"+", "-", "/", "*"};

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

    static std::array<std::string, 4> possible_operators;
    static std::array<std::string, 3> possible_left_delimeters;
    static std::array<std::string, 3> possible_right_delimeters;


    /* Psuedo-code algorithm (Figure 7.11, page 382)
     * -----------------------------------------------
     * 1. Initialize a stack of characters to hold hte operation symbols and parentheses.
     * 2. do
     *      if (the next input is a left parenthesis)
     *          Read the left parenthesis and push it onto the stack
     *
     *      else if (the next input is a number or other operand)
     *          Read the operand and write it to the output
     *
     *      else if (the next input is one of the operation symbols)
     *          Read the operation symbol and push it onto the stack
     *
     *      else
     *      {   Read and discard the next input symbol (which should be a right parenthesis).
     *          There should be an operation symbol on the top of the stack, so write this symbol to the output and pop
     *          it from the stack. (If there is no such symbol, then print an
     *          error message indicating that there were too few operations in the infix expression,
     *          and halt.) After popping the operation symbol, there should be a left parenthesis on
     *          the top of the stack, so pop and discard this left parenthesis.
     *          (If there was no left parenthesis, then the input did not have balanced
     *          parenthesis so print an error message and halt.
     *      }
     */
    static std::string convert_infix_to_postfix(std::string& infix_expression)
    {
        std::string postfix_expression;

        ExpressionParser::possible_operators = {"+", "-", "/", "*"};

        ExpressionParser::possible_left_delimeters = {"(", "{", "["};

        ExpressionParser::possible_right_delimeters = {")", "}", "]"};

        std::stack<std::string> expression_stack;

        std::istringstream string_stream(infix_expression);

        for (std::string ch; string_stream >> ch;)
        {

            if (std::find(possible_left_delimeters.begin(), possible_left_delimeters.end(), ch) != possible_left_delimeters.end())
            {
                expression_stack.push(ch);
            }

            else if (std::all_of(ch.begin(), ch.end(), isdigit))
            {
                postfix_expression += ch;
            }

            else if (std::find(possible_operators.begin(), possible_operators.end(), ch) != possible_operators.end())
            {
                expression_stack.push(ch);
            }

            else
            {
                // next symbol should be a right parenthesis
                assert(std::find(possible_right_delimeters.begin(), possible_right_delimeters.end(), ch) != possible_right_delimeters.end());

                    // skip the current character
                    string_stream >> ch;

                    // operation symbol should be on the top of the stack!
                    assert(std::find(possible_operators.begin(), possible_operators.end(), expression_stack.top()) != possible_operators.end());

                    postfix_expression += ch;

                    expression_stack.pop();

                    // after the operation symbol got popped, there should be a left parenthesis on the top

                    assert(std::find(possible_left_delimeters.begin(), possible_left_delimeters.end(), expression_stack.top()));

                    expression_stack.pop();

            }

        }

        assert(expression_stack.size() == 0);

        return postfix_expression;

    }

};

#endif //CHAPTER_7_POSTFIX_PARSER_H
