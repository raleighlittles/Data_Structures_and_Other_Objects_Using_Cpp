//
// Created by Raleigh Littles (raleigh) on 8/26/18 at 9:21 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include <iostream>
#include "statistician.h"


int main() {

    statistician ss;
    ss.next_number(1);
    ss.next_number(2);
    ss.next_number(3);

    std::cout << "Length: " << ss.get_length() << std::endl;
    std::cout << "Mean: " << ss.get_mean() << std::endl;
    std::cout << "Sum: " << ss.get_sum() << std::endl;
    std::cout << "Min/Max" << ss.get_minimum() << "/" << ss.get_maximum() << std::endl;

}