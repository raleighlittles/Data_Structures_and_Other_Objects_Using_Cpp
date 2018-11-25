//
// Created by raleigh on 11/24/18.
//


#ifndef CHAPTER_10_NODE_H
#define CHAPTER_10_NODE_H

#include <memory>

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
        // empty constructor
    }

};

#endif //CHAPTER_10_NODE_H
