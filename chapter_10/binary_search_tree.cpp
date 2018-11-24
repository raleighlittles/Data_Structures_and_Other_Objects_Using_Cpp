//
// Created by raleigh on 11/23/18.
//

#include <memory>

template <class Type>
class Node
{
private:
    Type node_value;
    std::unique_ptr<Node> left_node;
    std::unique_ptr<Node> right_node;

    //https://gist.github.com/mgechev/5911348

    Node(Type value, Node<Type> left, Node<Type> right)
    :
    node_value(value),
    left_node(left),
    right_node(right)
    {
        // empty constructur
    }

};

class Tree
{

};
