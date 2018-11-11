//
// Created by raleigh on 11/4/18.
//



#include "store_checkout.h"

StoreCheckout::StoreCheckout(unsigned int num_of_lines,
                             unsigned int max_wait_per_customer,
                             unsigned int starting_customers_per_line)
        : MAX_WAIT_PER_CUSTOMER(max_wait_per_customer) {


    for (unsigned int i = 0; i < num_of_lines; i++) {
        std::deque<long> checkout_line;

        for (unsigned int j = 0; j < starting_customers_per_line; j++) {
            checkout_line.push_back(0L);
        }
        checkout_system.push_back(checkout_line);
    }

}

void StoreCheckout::simulate_passage_of_time(unsigned int seconds) {
    for (unsigned int i = 0; i < seconds; i++) {
        unsigned int users_popped = 0;
        unsigned int users_added = 0;
        unsigned int users_left = 0;

        // Since we want to access original objects and modify them, you must use the address-of operator!
        for (auto &qu : checkout_system) {

            // flip a coin to decide if the line should have moved a user at that time

            bool transaction_complete = get_random_boolean();

            if (transaction_complete) {
                users_popped++;
                qu.pop_front();
            }

            // flip a coin to decide if a user has entered the line since the last moment of time
            bool user_arrived = get_random_boolean();

            if (user_arrived) {
                users_added++;
                qu.push_back(0L);
            }

            for (auto &user : qu) {
                user++;
                if (user > this->MAX_WAIT_PER_CUSTOMER) { // user gets frustrated and leaves the store
                    users_left++;
                    qu.erase(std::find(qu.begin(), qu.end(), user));
                }
            }

            qu.shrink_to_fit();
        }
    }
}

bool StoreCheckout::get_random_boolean() {
    // pick a random number, then use that as the seed for the classic Mersenne Twister psuedo-random number generator with a period of 2^(19937)-1
    std::mt19937 random_number_generator;
    random_number_generator.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> boolean(0, 1);

    return static_cast<bool>(boolean(random_number_generator));
}

void StoreCheckout::print_lines_status() {
    std::cout << "Printing report of " << checkout_system.size() << " lines." << std::endl;
    for (unsigned int queue_number = 0; queue_number < checkout_system.size(); queue_number++) {
        std::cout << "Current queue (#" << queue_number << ") has size : " << checkout_system[queue_number].size()
                  << std::endl;

    }
}