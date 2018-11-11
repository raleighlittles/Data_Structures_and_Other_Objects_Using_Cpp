//
// Created by raleigh on 11/4/18.
//



#include "store_checkout.h"

StoreCheckout::StoreCheckout(unsigned int num_of_lines,
                             unsigned int max_wait_per_customer)
   : MAX_WAIT_PER_CUSTOMER(max_wait_per_customer)
{
    std::deque<long> checkout_line;

    checkout_line.push_back(0L);

    for (unsigned int i = 0; i < num_of_lines; i++)
    {
        this->checkout_system.push_back(checkout_line);
    }

}

void StoreCheckout::simulate_passage_of_time(unsigned int seconds)
{
    for (unsigned int i = 0; i < seconds; i++)
    {
        increment_all_times();
    }
}

void StoreCheckout::increment_all_times()
{
    for (auto qu : checkout_system)
    {

        // flip a coin to decide if the line should have moved a user at that time

        bool transaction_complete = get_random_boolean();

        if (transaction_complete == true)
        {
            qu.pop_front();
        }

        for (auto user : qu)
        {
            user++;
            if (user > this->MAX_WAIT_PER_CUSTOMER)
            { // user gets frustrated and leaves the store
                qu.erase(std::find(qu.begin(), qu.end(), user));
            }
        }
    }
}

bool StoreCheckout::get_random_boolean()
{
    // pick a random number, then use that as the seed for the classic Mersenne Twister psuedo-random number generator with a period of 2^(19937)-1
    std::mt19937 random_number_generator;
    random_number_generator.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> boolean(0,1);

    return static_cast<bool>(boolean(random_number_generator));
}

void StoreCheckout::print_lines_status()
{
    std::cout << "Printing report of " << checkout_system.size() << " lines." << std::endl;
    for (unsigned int queue_number = 0; queue_number < checkout_system.size(); queue_number++)
    {
        std::cout << "Current queue (#" << queue_number << ") has size : " << checkout_system.at(queue_number).size() << std::endl;
        
    }
}