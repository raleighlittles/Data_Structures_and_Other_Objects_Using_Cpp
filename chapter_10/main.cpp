#include <iostream>
#include <list>

#include "tree_projects.cpp"
#include "expression_tree.hpp"

int main() {
    // test expression tree

     const std::string sample_postfix_expression =  "10 2 8 * + 3 -";

    ExpressionTree<std::string> et = ExpressionTree<std::string>(sample_postfix_expression);

    assert(et.root_node != nullptr);

    std::cout << "Expression tree result " << et.evaluate(et.root_node) << std::endl;

    // test BST/LL

    BinarySearchTree<int> bst = BinarySearchTree<int>(10);

   bst.insert(bst.root_node, 12);

   bst.insert(bst.root_node, 15);

   bst.insert(bst.root_node, 25);

   bst.insert(bst.root_node, 30);

   bst.insert(bst.root_node, 36);

   std::list<int> ll;

   std::cout << "Beginning to convert BST to List." << std::endl;

   ll = Trees::convert_BST_to_LL(bst);

   std::cout << "This should now be a sorted list of " << bst.nodes_count << " eleemnts." << std::endl;

   for (auto el : ll)
   {
       std::cout << el << std::endl;
   }


}