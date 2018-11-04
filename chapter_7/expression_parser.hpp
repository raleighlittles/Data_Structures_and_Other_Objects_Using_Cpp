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
#include <map>

class ExpressionParser {

public:
    /* See: Figure 7.10, page 380 */
    static double parse_postfix_expression(const std::string &expression)
    {
        //std::vector<std::string> splitted_results;

        std::array<std::string, 4> possible_operators = {"+", "-", "/", "*"};

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

    /* See: Figure 7.11, page 382 */
    static std::string convert_parenthesized_infix_to_postfix(const std::string& parenthesized_infix_expression)
    {
        std::string postfix_expression;

        std::array<std::string, 4> possible_operators = {"/","*","-","+"};

        std::array<std::string, 3> possible_left_delimeters = {"(", "{", "["};

        std::array<std::string, 3> possible_right_delimeters = {")", "}", "]"};

        std::stack<std::string> expression_stack;

        std::istringstream string_stream(parenthesized_infix_expression);

        for (std::string ch; string_stream >> ch;)
        {

            if (std::find(possible_left_delimeters.begin(), possible_left_delimeters.end(), ch) != possible_left_delimeters.end())
            {
                expression_stack.push(ch);
            }

            else if (std::all_of(ch.begin(), ch.end(), ::isalnum))
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

                    // operation symbol should be on the top of the stack!
                    assert(std::find(possible_operators.begin(), possible_operators.end(), expression_stack.top()) != possible_operators.end());

                    postfix_expression += expression_stack.top();

                    expression_stack.pop();

                    // after the operation symbol got popped, there should be a left parenthesis on the top
                    assert(std::find(possible_left_delimeters.begin(), possible_left_delimeters.end(), expression_stack.top()) != possible_left_delimeters.end());

                    expression_stack.pop();
            }
        }
        assert(expression_stack.size() == 0);

        return postfix_expression;

    }


    /* See: Figure 7.12, page 385 */
    static std::string convert_general_infix_to_postfix(const std::string& infix_expression)
    {
        std::string postfix_expression;

        std::array<std::string, 4> possible_operators = {"/","*","-","+"};

        std::stack<std::string> expression_stack;

        std::istringstream string_stream(infix_expression);

        for (std::string ch; string_stream >> ch; )
        {

            if (is_left_delimeter(ch))
            {
                expression_stack.push(ch);
            }

            else if (std::all_of(ch.begin(), ch.end(), ::isalnum))
            {
                postfix_expression += ch;
            }

            else if (is_operator(ch))
            {

                do
                {
                    postfix_expression += expression_stack.top();
                    expression_stack.pop();
                }

                while (!expression_stack.empty() |
                is_left_delimeter(expression_stack.top()) |
                ( is_operator(expression_stack.top()) &&  is_lower_precedence(expression_stack.top(), ch)))


                expression_stack.push(ch);

            }

            else
            {
                assert(is_right_delimeter(ch));

                postfix_expression += expression_stack.top();

                expression_stack.pop();

                bool lparenthensis_seen = false;

                if (!is_left_delimeter(expression_stack.top()))
                {
                    postfix_expression += expression_stack.top();
                    expression_stack.pop();
                }

                else
                {
                    lparenthensis_seen = true;

                }

                // you should have seen a left parenthesis by now
                assert(lparenthensis_seen == true);

                // now that you've seen the left parenthesis, pop it

                expression_stack.pop();

            }


    }


    // print and pop any remaining operations on the stack. There should be no remaining left parenthesesis

    }

   static std::map<std::string, int> operators;

    static std::array<std::string, 3> possible_right_delimeters;

    static std::array<std::string, 3> possible_left_delimeters;

    static bool is_right_delimeter(std::string character)
    {
        ExpressionParser::possible_right_delimeters = {")", "}", "]"};

        return (std::find(possible_right_delimeters.begin(), possible_right_delimeters.end(), character) != possible_right_delimeters.end());
    }


     static bool is_left_delimeter(std::string character)
    {
        ExpressionParser::possible_left_delimeters = {"(", "{", "["};

        return (std::find(possible_left_delimeters.begin(), possible_left_delimeters.end(), character) != possible_left_delimeters.end());
    }

    /* TODO: Combine this and the method below into one method */
    static bool is_operator(std::string character)
    {
        std::array<std::string, 4> operators = {"+", "-", "/", "*"};
        return (std::find(operators.begin(), operators.end(), character) != operators.end());
    }

    /* Is operator 1 a lower precedence than the 2nd operator? */
    static bool is_lower_precedence(std::string operator1, std::string operator2)
    {
         ExpressionParser::operators = {{"+", 1}, {"-", 1}, {"*", 2},{ "/", 2}};
         return (operators.find(operator1)->second < operators.find(operator2)->second);
    }

};

#endif //CHAPTER_7_POSTFIX_PARSER_H
