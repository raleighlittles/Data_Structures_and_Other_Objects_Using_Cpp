//
// Created by Raleigh Littles (raleigh) on 8/18/18 at 11:16 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "statistician.h"
#include <assert.h>
#include <string>
#include <iostream>
#include <algorithm>


void statistician::next_number(float new_number) {

    (this->length)++;

    this->sum += new_number;


    if (this->length > 1)
    {
        if (this->maximum < new_number) {
            this->maximum = new_number;
        }

        if (this->minimum > new_number) {
            this->minimum = new_number;
        }

    }

    else
    {
        this->maximum = new_number;
        this->minimum = new_number;
    }

    this->mean = sum / length;

}

float statistician::get_mean() const
{

    statistician::assert_not_empty();

    return this->mean;
}

float statistician::get_maximum() const
{

    statistician::assert_not_empty();

    return this->maximum;
}

float statistician::get_minimum() const {

    statistician::assert_not_empty();

    return this->minimum;
}

void statistician::erase_sequence() {

    std::cout << "Erasing sequence." << std::endl;

    this->length = 0;
    this->sum = 0;
}

void statistician::assert_not_empty() const {

    assert(this->length != 0);
}

statistician operator+(statistician const &s1, statistician const &s2) {

    statistician s3;

    s3.minimum = std::min(s1.minimum, s2.minimum);
    s3.maximum = std::max(s1.maximum, s2.maximum);

    s3.length = s1.length + s2.length;
    s3.sum = s1.sum + s2.sum;
    s3.mean = (s1.mean + s2.mean) / (s3.length);

    return s3;

}
