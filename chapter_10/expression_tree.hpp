//
// Created by raleigh on 11/24/18.
//


#ifndef CHAPTER_10_EXPRESSION_TREE_H
#define CHAPTER_10_EXPRESSION_TREE_H

#include "node.hpp"
#include <string>
#include <array>
#include <stack>

/*
 *
 * This project deals with a simple kind of
expression tree, where there are two kinds of
nodes:
(a) Leaf nodes, which contain a real number as
their entry;
(b) Nonleaf nodes, which contain either the char-
acter + or the character * as their entry, and have ex-
actly two children.
1
For this project, implement a class for expression
trees, including operations for building expression
trees. Also include a recursive function to “evalu-
ate” a non-empty expression tree using these rules:
(a) If the tree has only one node (which must be
a leaf), then the evaluation of the tree returns the real
number that is the node’s entry;Programming Projects
(b) If the tree has more than one node, and the
root contains +, then first evaluate the left subtree,
then evaluate the right subtree, and add the results.
If the root contains *, then evaluate the two subtrees
and multiply the results.
For example, consid-
'*'
er the small expression
tree shown to the right.
The left subtree evalu-
'+'
14
ates to 3+7, which is 10.
The right subtree evalu-
3
7
ates to 14. So the entire
tree evaluates to 10*14,
which is 140.
 */
//template <class Type>
class ExpressionTree
{
private:
    std::array<std::string, 10> possible_operators;
    bool is_operator(std::string string_to_check);

public:

    // returns the root node of an expression tree
    ExpressionTree(std::string postfix_expression)
    {
         // reference: https://www.geeksforgeeks.org/expression-tree/
           std::stack<int> expression_stack;
           std::unique_ptr<Node<std::string>> node1;
           std::unique_ptr<Node<std::string>> node2;
           std::unique_ptr<Node<std::string>> node3;

           // split string on spaces!!

           for (unsigned int index = 0; index < postfix_expression.length(); index++)
           {
               if (is_operator()
           }


    }



};

#endif //CHAPTER_10_EXPRESSION_TREE_H
