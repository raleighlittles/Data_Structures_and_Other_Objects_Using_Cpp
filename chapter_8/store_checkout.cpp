//
// Created by raleigh on 11/4/18.
//


#include "store_checkout.h"

StoreCheckout::StoreCheckout(unsigned int num_of_lines,
                             unsigned int max_wait_per_customer)
   : MAX_WAIT_PER_CUSTOMER(max_wait_per_customer)
{
    std::queue<long> checkout_line;

    checkout_line.push(0L);

    for (unsigned int i = 0; i < num_of_lines; i++)
    {
        this->checkout_system.push_back(checkout_line);
    }

}

void StoreCheckout::simulate_passage_of_time(unsigned int seconds)
{
    for ()
}
