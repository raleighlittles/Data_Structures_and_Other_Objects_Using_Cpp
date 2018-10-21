
//
// Created by Raleigh Littles (raleigh) on 10/7/18 at 12:09 AM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#ifndef CHAPTER_5_LINKED_DIGIT_LIST_H
#define CHAPTER_5_LINKED_DIGIT_LIST_H

#include <string>
#include <list>
#include <iostream>
#include <iterator>
#include <cassert>

class Number {

public:
    explicit Number(long starting_number);

    // TODO: implement operator overloads for addition, subtraction, and division?

    std::string to_string() const;

    void add_node(long number);

    long compute_number() const;

    Number operator+(const Number &number) const;

    Number operator-(const Number &number) const;

    Number operator/(const Number &number) const;

    Number operator*(const Number &number) const;


private:
    //std::list<std::string> number;
    std::list<long> number;
    static const unsigned int MAX_NUMBER_LENGTH = 3;


    int max_node_number() { // if the maximum length of any node is X, then the largest possible node
        // in a number is obviously just X (d-1)'s where d is the base of the number system
        return (std::stoi(std::string(Number::MAX_NUMBER_LENGTH, '9')));
    };

};

#endif //CHAPTER_5_LINKED_DIGIT_LIST_H