//
// Created by raleigh on 11/24/18.
//


#ifndef CHAPTER_10_NODE_H
#define CHAPTER_10_NODE_H

#include <memory>

template <class NodeType>
class Node
{
public:
    NodeType node_value;
    std::shared_ptr<Node> left_node;
    std::shared_ptr<Node> right_node;

    explicit Node(NodeType value)
            :
            node_value(value)
    {
        // empty constructor
    }

    Node(NodeType value, Node<NodeType> left, Node<NodeType> right)
        :
        node_value(value),
        left_node(std::make_shared<Node<NodeType>>(left)),
        right_node(std::make_shared<Node<NodeType>>(right))
    {

    }

    // copy constructor
    Node(const Node &copy)
    :
        node_value(copy.node_value),
        left_node(copy.left_node),
        right_node(copy.right_node)
    {
         // empty constructor
    }

    // assignment operator
    Node& operator=(const Node &node)
    {
        this->node_value = node.node_value;
        this->left_node = node.left_node;
        this->right_node = node.right_node;

        return *this; // so you can "chain" assignments
    }

};

#endif //CHAPTER_10_NODE_H
