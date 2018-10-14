//
// Created by Raleigh Littles (raleigh) on 10/7/18 at 12:29 AM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//


#include "linked_digit_list.h"

Number::Number(long starting_number)
{
    // Starting with a specified number, seperate it into groups of X digits starting from the left -- then add those X-digit-long sequences as nodes in the list, where X is the maximum digit length.

    // In the case where the group of digits is less than X-characters long, prepend 0s to the digit to ensure all digit sequences in the list have the same digit length

    /*
    std::string starting_number_as_string = std::to_string(starting_number);

    for (std::size_t index = starting_number_as_string.length(); index > 0; index -= MAX_NUMBER_LENGTH)
    {
        std::string current_node = starting_number_as_string.substr(index-2, MAX_NUMBER_LENGTH);

        if (current_node.length() != 3)
        {
            std::string prepended_zeros = std::string(current_node.length() - MAX_NUMBER_LENGTH, '0');
            current_node.insert(0, prepended_zeros);
        }
        this->number.push_back(current_node);
    }
*/
    add_node(starting_number);


    std::cout << "Created list of nodes, having size: " << this->number.size() << std::endl;

}

long Number::compute_number() const {

    long number = 0;

    std::string number_as_string = to_string();

    return stol(number_as_string);

}

std::string Number::to_string()
{
    // iterate over the list backwards, (but still print the elements in correct order
    std::string my_number_as_string;
   for (auto iter = this->number.rbegin(); iter != this->number.rend(); ++iter)
   {

        std::string current_node = std::to_string(*iter);

        if (current_node.length() < MAX_NUMBER_LENGTH)
        {
            // prepend zeros
            std::string prepended_zeros = std::string(MAX_NUMBER_LENGTH - current_node.length(), '0');

            current_node.insert(0, prepended_zeros);

        }

        my_number_as_string += current_node;



   }

   return my_number_as_string;

}

void Number::add_node(int number) {

    std::string number_as_string = std::to_string(number);

    if (number_as_string.length() < MAX_NUMBER_LENGTH)
    {
            this->number.push_back(number);
    }

    else
    {
        std::cout << "Unable to add number to node. Maximum number permitted in list is " << max_node_length() << std::endl;
    }

}


Number Number::operator+(const Number &number) const
{

    return Number(this->compute_number() + number.compute_number());

}

Number Number::operator-(const Number &number) const
{


}