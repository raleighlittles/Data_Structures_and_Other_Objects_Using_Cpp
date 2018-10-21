//
// Created by Raleigh Littles (raleigh) on 10/20/18 at 2:43 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#ifndef CHAPTER_7_INFIX_PARSER_H


#define CHAPTER_7_INFIX_PARSER_H

#include <string>

class InfixParser {

public:

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
    static double convert_infix_to_postfix(std::string& expression)
    {

    }

};

#endif //CHAPTER_7_INFIX_PARSER_H
