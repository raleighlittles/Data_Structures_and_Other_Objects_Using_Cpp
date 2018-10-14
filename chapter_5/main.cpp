#include <iostream>
#include "linked_digit_list.h"

int main() {
    Number n1 = Number(23);
    n1.add_node(7);
    n1.add_node(999);
    n1.add_node(0);

    std::cout << n1.to_string() << std::endl;
    std::cout << n1.compute_number() << std::endl;

    Number n2 = Number(45);
    n2.add_node(6);
    n2.add_node(210);
    n2.add_node(3);

    std::cout << n2.to_string() << std::endl;
    std::cout << n2.compute_number() << std::endl;

    Number n3 = n1 + n2;

    std::cout << n3.compute_number() << std::endl;
}
