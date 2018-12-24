#include <iostream>
#include <list>

#include "tree_projects.cpp"


int main() {
    // test expression tree?

     const std::string sample_postfix_expression =  "10 2 8 * + 3 -";

    ExpressionTree<std::string> et = ExpressionTree<std::string>(sample_postfix_expression);

    assert(et.root_node != nullptr);

    std::cout << "Expression tree result " << et.evaluate(et.root_node) << std::endl;

    // test BST/LL

    BinarySearchTree<int> bst = BinarySearchTree<int>(10);

    //bst.add_node(Node<int>(10));

    bst.add_node(Node<int>(12));

    bst.add_node(Node<int>(15));

    bst.add_node(Node<int>(25));

    bst.add_node(Node<int>(30));

    bst.add_node(Node<int>(36));

   std::list<int> ll;
   ll = Trees::convert_BST_to_LL(bst);

   std::cout << "This should now be a sorted list of " << ll.size() << " eleemnts." << std::endl;

   for (auto el : ll)
   {
       std::cout << el << std::endl;
   }



}