//
// Created by Raleigh Littles (raleigh) on 10/7/18 at 12:29 AM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//


#include "linked_digit_list.h"

Number::Number(long starting_number) {
    add_node(starting_number);
}

long Number::compute_number() const {

    std::string number_as_string = to_string();

    return stol(number_as_string);

}

std::string Number::to_string() const {
    // iterate over the list backwards, (but still print the elements in correct order
    std::string my_number_as_string;
    for (auto iter = this->number.begin(); iter != this->number.end(); ++iter) {

        std::string current_node = std::to_string(*iter);

        if (current_node.length() < MAX_NUMBER_LENGTH) {
            // prepend zeros
            std::string prepended_zeros = std::string(MAX_NUMBER_LENGTH - current_node.length(), '0');

            current_node.insert(0, prepended_zeros);

        }
        my_number_as_string += current_node;
    }

    return my_number_as_string;

}

void Number::add_node(long number) {

    if (number <= max_node_number()) {
        std::cout << "Added the number " << (number) << std::endl;
        this->number.push_back(number);
    } else {
        std::string number_as_string = std::to_string(number);
        for (unsigned int index = 0; index < number_as_string.length(); index += MAX_NUMBER_LENGTH) {
            // needed to ensure each node number length meets the specified requirements
            if (number_as_string.length() - index >= MAX_NUMBER_LENGTH) {
                std::string current_node = number_as_string.substr(index, MAX_NUMBER_LENGTH);
                assert(current_node.length() == MAX_NUMBER_LENGTH);
                this->number.push_back(stoi(current_node));
                std::cout << "Added the number " << stoi(current_node) << std::endl;
            } else {
                // do the prepended zeros strategy
                std::string prepended_zeros = std::string(MAX_NUMBER_LENGTH - (number_as_string.length() - index), '0');
                std::string current_node =
                        prepended_zeros + number_as_string.substr(index, number_as_string.length() - index);
                assert(current_node.length() == MAX_NUMBER_LENGTH);
                this->number.push_back(stol(current_node));
                std::cout << "Added the number " << stoi(current_node) << std::endl;
            }
        }
    }

}

Number Number::operator+(const Number &number) const {

    return Number(this->compute_number() + number.compute_number());

}

Number Number::operator-(const Number &number) const {
    // Negative number subtraction is incompatible with the specifications of the problem
    assert(this->compute_number() - number.compute_number() > 0);

    return Number(this->compute_number() - number.compute_number());
}

Number Number::operator*(const Number &number) const {

    return Number(this->compute_number() * number.compute_number());
}

Number Number::operator/(const Number &number) const {
    // The problem specifies whole number arithmetic, which disallows floating point numbers
    assert(this->compute_number() / number.compute_number() != 0);

    return Number(this->compute_number() * number.compute_number());
}
