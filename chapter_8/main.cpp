#include "store_checkout.h"

#include <iostream>

int main()
{
    StoreCheckout costco = StoreCheckout(10, 100, 25);

    costco.simulate_passage_of_time(100);

    costco.print_lines_status();

}