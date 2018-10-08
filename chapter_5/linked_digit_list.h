//
// Created by Raleigh Littles (raleigh) on 10/7/18 at 12:09 AM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#ifndef CHAPTER_5_LINKED_DIGIT_LIST_H
#define CHAPTER_5_LINKED_DIGIT_LIST_H

#include <string>
#include <list>
#include <iostream>


class Number {

public:
    Number(int starting_number);

    // TODO: implement operator overloads for addition, subtraction, and division?

    std::string to_string();


    void add_node(int number);



private:
    std::list<std::string> number;
    int16_t MAX_NUMBER_LENGTH=3;

};

#endif //CHAPTER_5_LINKED_DIGIT_LIST_H
