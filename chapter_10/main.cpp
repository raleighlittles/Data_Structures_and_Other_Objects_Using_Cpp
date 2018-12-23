#include <iostream>
#include "expression_tree.hpp"


int main() {
    // test expression tree?

     const std::string sample_postfix_expression =  "10 2 8 * + 3 -";

    ExpressionTree<std::string> et = ExpressionTree<std::string>(sample_postfix_expression);

    assert(et.root_node != nullptr);

    std::cout << "Expression tree result " << et.evaluate(et.root_node) << std::endl;


}