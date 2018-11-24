//
// Created by raleigh on 11/23/18.
//

#include <memory>
#include <iostream>

template <class NodeType>
class Node
{
private:
    NodeType node_value;
    std::unique_ptr<Node> left_node;
    std::unique_ptr<Node> right_node;

    //https://gist.github.com/mgechev/5911348

    explicit Node(NodeType value, Node<NodeType> left = nullptr, Node<NodeType> right = nullptr)
    :
    node_value(value),
    left_node(left),
    right_node(right)
    {
        // empty constructur
    }

};

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

    }


};
