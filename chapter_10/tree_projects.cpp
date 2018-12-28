//
// Created by raleigh on 11/23/18.
//
#include "binary_search_tree.hpp"

#include <list>
#include <stack>
// Problem #8
// Write a function that takes a binary search
// tree as input and produces a linked list of
// the entries, with the entries sorted (smallest
// entries at the front of the list and largest entries at the
//        back). Hint: use in-order traversal.

namespace Trees
{
    template <typename Type>
    std::list<Type> convert_BST_to_LL(BinarySearchTree<Type>& input)
    {
        std::list<Type> result;

        std::stack<std::shared_ptr<Node<Type>>> stack;

        std::shared_ptr<Node<Type>> current = input.root_node;

        while ((current != nullptr) or (stack.empty() == false))
        {
            while (current != nullptr)
            {
                stack.push(current);
                current = current->left_node;
            }

            assert(current == nullptr);

            current = stack.top();

            stack.pop();

            result.push_back(current->node_value);

            current = current->right_node;

        }

        return result;
    }

}