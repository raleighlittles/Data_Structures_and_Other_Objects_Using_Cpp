//
// Created by raleigh on 11/4/18.
//

#ifndef CHAPTER_8_STORE_QUEUE_H
#define CHAPTER_8_STORE_QUEUE_H

#include <deque>
#include <random>
#include <algorithm>
#include <random>
#include <iostream>

class StoreCheckout
{
    // Problem description
    /*
     * Write a simulation program of the lines at a
grocery store. The program will be similar to
the car wash simulation, except that there
are multiple queues instead of one. You might use a
vector of queues to simulate the lines. Assume that
there are five cashier lines at the grocery store. Cus-
available line is chosen. Each transaction takes a
random amount of time to complete.
tomers enter randomly to check out, and then enter
the shortest line. If the lines are equal, then the first
For additional work, expand the grocery line pro-
gram to allow shoppers to:
• Avoid a line if all lines are a certain length
• Leave a line if they have waited beyond a cer-
tain time
• Check if another line is shorter at specified
time intervals
• Switch lines if another line is shorter
     */

public:
    StoreCheckout(unsigned int num_of_lines,
            unsigned int max_wait_per_customer);

    void simulate_passage_of_time(unsigned int seconds);

private:
    //void switch_line(unsigned int starting_line, unsigned int ending_line);

    // use a deque only because it supports iteration, while regular queues do not
    std::vector <std::deque<long>> checkout_system;
    const unsigned int MAX_WAIT_PER_CUSTOMER;

    void increment_all_times();

    bool get_random_boolean();

    void print_lines_status();
};

#endif //CHAPTER_8_STORE_QUEUE_H
