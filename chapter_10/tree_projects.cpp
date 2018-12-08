//
// Created by raleigh on 11/23/18.
//
#include "binary_search_tree.hpp"
#include "expression_tree.hpp"

#include <list>
namespace Trees
{
    template <typename Type>
    std::list<Type> convert_BST_to_LL(BinarySearchTree<Type> input)
    {
        // Do an in-order traversal of the BST, and append it to a list
        std::list<Type> result;

        Node current_node = input.root_node;

        while (current_node != nullptr)
        {
            current_node = current_node.left_node;

            result.push_back(current_node.node_value);

            current_node = current_node.right_node;
        }

        return result;
    }


}