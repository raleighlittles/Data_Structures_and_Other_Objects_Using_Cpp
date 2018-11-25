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

    //https://gist.github.com/mgechev/5911348

    explicit Node(NodeType value, Node<NodeType> left = nullptr, Node<NodeType> right = nullptr)
            :
            node_value(value),
            left_node(left),
            right_node(right)
    {
        // empty constructor
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
