#include <iostream>
#include "radix_sorter.hpp"


int main() {   // only works on equal-length strings
    std::vector<std::string> v = {"ccc", "bbb", "aaa", "dfd"};

    Sorter::radix_sort(v);

    std::cout << v.size() << std::endl;

    for (std::string word : v)
    {
        std::cout << " " << word;
    }

}
