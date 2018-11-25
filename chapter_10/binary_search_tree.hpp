//
// Created by raleigh on 11/23/18.
//

#include <memory>
#include <iostream>
#include "node.hpp"

template <class Type>
class BinarySearchTree
        // A generic, basic implementation of a Binary Search Tree in C++17.
{
private:
    std::unique_ptr<Node<Type>> root_node;
    unsigned int nodes_count = 0;

    void add_node_recursive(std::unique_ptr<Node<Type>> root_node, Type node_value)
    {
        if (root_node->node_value > node_value)
        {
            if (!root_node->left_node)
            {
                root_node->left_node = std::make_unique(Node(node_value));
            }

            else
            {
                add_node_recursive(root_node->left_node, node_value);
            }
        }

        else
        {
            if (root_node.right_node == false)
            {
                //root_node.right_node = Node(node_value);
                root_node->left_node = std::make_unique(Node(node_value));
            }

            else
            {
                add_node_recursive(root_node.right_node, node_value);
            }
        }
    }

    void print_nodes_recursive(std::unique_ptr<Node<Type>> root_node)
    {
        if (root_node == false)
        {
            return;
        }

        print_nodes_recursive(root_node->left_node);
        std::cout << "Value : " << root_node->node_value << " ";
        print_nodes_recursive(root_node->right_node);
    }

    void delete_value_recursive(std::unique_ptr<Node<Type>> parent_node, std::unique_ptr<Node<Type>> current_node, Type value_to_delete)
    {
        if (current_node == false)
        {
            if (current_node->node_value == value_to_delete)
            {
                if ((current_node->left_node == nullptr) or (current_node->right_node == nullptr))
                {
                    std::unique_ptr<Node<Type>> temporary = current_node->left_node;
                    if (current_node->right_node)
                    {
                        temporary = current_node->right_node;
                    }

                    if (parent_node)
                    {
                        if (parent_node->left == current_node)
                        {
                            parent_node->left = temporary;
                        }

                        else
                        {
                            parent_node->right_node = temporary;
                        }
                    }

                    else
                        {
                        this->root_node = temporary;
                    }
                }

                else
                {
                    std::unique_ptr<Node<Type>> substitute = current_node->right_node;
                    while (substitute->left_node)
                    {
                        substitute = substitute->left_node;
                    }

                    Type temporary_value = current_node->value;
                    current_node->value = substitute->node_value,
                    substitute->node_value = temporary_value;
                    return delete_value_recursive(current_node, current_node->right_node, temporary_value);
                }

            }
        }
    }

public:
    void add_node(Node<Type> node)
    {
        if (root_node)
        {
            add_node_recursive(root_node, node.node_value);
        }
    }

    void print_nodes()
    {
        print_nodes_recursive(root_node);
    }

    void delete_value(Type value)
    {
        return delete_value_recursive(nullptr, this->root_node, value);
    }


};
