//
// Created by Raleigh Littles (raleigh) on 8/18/18 at 6:34 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include <string>

#ifndef CHAPTER_2_STATISTICIAN_H
#define CHAPTER_2_STATISTICIAN_H

class statistician {

    friend statistician operator+ (statistician const &s1, statistician const &s2);

public:

    statistician() : length(0), sum(0)
    {

    }

    void next_number(float new_number);

    int get_length() const { return length; }

    float get_sum() const { return sum; }

    float get_mean() const;

    float get_minimum() const;

    float get_maximum() const;

    void erase_sequence();

    void assert_not_empty() const;

private:

    int length;
    float sum;
    float mean;
    float minimum;
    float maximum;

};


#endif //CHAPTER_2_STATISTICIAN_H
