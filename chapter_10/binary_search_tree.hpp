//
// Created by raleigh on 11/23/18.
//

#ifndef CHAPTER_10_BST_H
#define CHAPTER_10_BST_H

#include <memory>
#include <iostream>
#include <vector>

#include "node.hpp"

template <class Type>
class BinarySearchTree
{
public:
    std::shared_ptr<Node<Type>> root_node;
    unsigned int nodes_count = 0;

     void add_node(Node<Type> node)
    {
        nodes_count++;

        if (this->root_node)
        {
            std::cout << "Attempting to add node with value : " << node.node_value << std::endl;
            auto res = add_node_recursive(std::make_shared<Node<Type>>(node), node.node_value);
        }


        else
        {
            std::cout << "Empty tree, currently adding node with value " << node.node_value << std::endl;
            this->root_node = std::make_shared<Node<Type>>(node.node_value);
        }

    }

    std::shared_ptr<Node<Type>> insert(std::shared_ptr<Node<Type>> node_to_insert_at, Type value_to_insert)
    {
        if (!node_to_insert_at)
        {
            return std::make_shared<Node<Type>>(Node(value_to_insert));
        }

        if (value_to_insert < node_to_insert_at->node_value)
        {
            node_to_insert_at->left_node = insert(node_to_insert_at->left_node, value_to_insert);

        }

        else if (value_to_insert > node_to_insert_at->node_value)
        {
            node_to_insert_at->right_node = insert(node_to_insert_at->right_node, value_to_insert);
        }

        return node_to_insert_at;
    }


    std::shared_ptr<Node<Type>> add_node_recursive(std::shared_ptr<Node<Type>> new_node, Type node_value)
    {

        if (node_value < new_node->node_value)
        {
            new_node->left_node = add_node_recursive(new_node->left_node, node_value);
        }

        else if (node_value > new_node->node_value)
        {
            new_node->right_node = add_node_recursive(new_node->right_node, node_value);
        }

         return new_node;
    }

    void print_nodes_recursive(std::shared_ptr<Node<Type>> root_node)
    {
        if (root_node == nullptr)
        {
            return;
        }

        print_nodes_recursive(root_node->left_node);
        std::cout << "Value : " << root_node->node_value << " ";
        print_nodes_recursive(root_node->right_node);
    }

    void delete_value_recursive(std::shared_ptr<Node<Type>> parent_node, std::shared_ptr<Node<Type>> current_node, Type value_to_delete)
    {
        if (current_node == false)
        {
            if (current_node->node_value == value_to_delete)
            {
                if ((current_node->left_node == nullptr) or (current_node->right_node == nullptr))
                {
                    std::shared_ptr<Node<Type>> temporary = current_node->left_node;
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
                    std::shared_ptr<Node<Type>> substitute = current_node->right_node;
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

    void print_nodes()
    {
        print_nodes_recursive(root_node);
    }

    void delete_value(Type value)
    {
        return delete_value_recursive(nullptr, this->root_node, value);
    }

    explicit BinarySearchTree<Type>(const Type initial_value)
    {
        std::cout << "BST constructor called with " << initial_value << std::endl;
        // this->root_node = std::make_shared<Node<Type>>(Node<Type>(initial_value));

        // add_node(Node(initial_value));

        this->root_node = std::make_shared<Node<Type>>(Node<Type>(initial_value));
    }

    explicit BinarySearchTree<Type>(const BinarySearchTree<Type>&  bst)
    { // copy constructor

        if (bst.root_node == nullptr)
        {
            root_node = nullptr;
        }

        else
        {
            copy_tree(this->root_node, bst.root_node);
        }

        this->nodes_count = bst.nodes_count;
    }

    void copy_tree(std::shared_ptr<Node<Type>> new_root, std::shared_ptr<Node<Type>> existing_root)
    {
        if (existing_root == nullptr)
        {
            new_root = nullptr;
        }

        else
        {
            new_root->node_value = existing_root->node_value;
            copy_tree(new_root->left_node, existing_root->left_node);
            copy_tree(new_root->right_node, existing_root->right_node);
        }
    }


};

#endif // CHAPTER_10_BST_H