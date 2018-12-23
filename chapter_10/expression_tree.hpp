//
// Created by raleigh on 11/24/18.
//


#ifndef CHAPTER_10_EXPRESSION_TREE_H
#define CHAPTER_10_EXPRESSION_TREE_H

#include "node.hpp"

#include <string>
#include <array>
#include <stack>
#include <algorithm>
#include <sstream>
#include <cmath>

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

    bool is_operator(std::string string_to_check)
    {
        return (std::find(possible_operators.begin(), possible_operators.end(), string_to_check) != possible_operators.end());
    }

    template <class Type>
    bool is_leaf_node(const Node<Type>& node)
    {
        return ((node.left_node == nullptr) and (node.right_node == nullptr));
    }

public:

    std::shared_ptr<Node<std::string>> root_node;

    // returns the root node of an expression tree
    explicit ExpressionTree(const std::string &postfix_expression)
    {
         // reference: https://www.geeksforgeeks.org/expression-tree/
           std::stack<std::shared_ptr<Node<std::string>>> expression_stack;
           std::shared_ptr<Node<std::string>> node1;
           std::shared_ptr<Node<std::string>> node2;
           std::shared_ptr<Node<std::string>> node3;

           std::istringstream stringstream(postfix_expression);

           for (std::string character; stringstream >> character; )
           {

               if (is_operator(character) == false)

               {
                  node1 = Node(character);
                    expression_stack.push(node1);
               }

               else
               {
                  node1 = Node(character);

                  node2 = expression_stack.top();
                    expression_stack.pop();

                  node3 = expression_stack.top();
                  expression_stack.pop();

                  node1->right_node = node2;

                  node2->left_node = node3;

                  expression_stack.push(node1);

               }

           }


       node1 = expression_stack.top();
       expression_stack.pop();

       this->root_node = node1;
    }

    // Nodes in the tree will be any combination of strings for operators,
    // or any numeric type for operands
    template <class Type>
    double evaluate(Node<Type> root_node)
    { // does an in-order evaluation of the
        /*
        if (root_node == nullptr)
        { // change to assert
            return 0.0;
        }

        if (is_leaf_node(*root_node))
        {
            return std::stod(root_node->node_value);
        }

        Node<Type> current_node = Node(&root_node);

        while (current_node != nullptr)
        {

            current_node = current_node.left_node;

            if (current_node.node_value == "+")
            {

            }

        }

        */

        // https://www.geeksforgeeks.org/evaluation-of-expression-tree/

        if (root_node == nullptr)
        {
            // throw an exception
            return 0.0;
        }

        if (is_leaf_node(root_node))
        {
            return std::stod(root_node.node_value);
        }

        double left_value = evaluate(root_node.left_node);
        double right_value = evaluate(root_node.right_node);

        switch (root_node.node_value)
        { // check for each operator
            case "+" : return left_value + right_value;
            case "-" : return left_value - right_value;
            case "/" : return left_value / right_value;
            case "*" : return left_value * right_value;
            default  : return 0.0;
        }

    }



};

#endif //CHAPTER_10_EXPRESSION_TREE_H
