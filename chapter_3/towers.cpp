//
// Created by Raleigh Littles (raleigh) on 9/9/18 at 4:44 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "towers.h"



// Precondition: 1 <= n <= 64.
// Postcondition: The towers have been initialized with n rings on the first peg and no rings on the other two pegs.
// The diameters of the first peg's rings are from one inch (on the top) to n inches (on the bottom)
towers::towers(std::size_t n, std::size_t num_pegs)
{
    std::cout << "Initializing a tower with " << n << " rings on " << num_pegs << " pegs." << std::endl;

    Peg first_peg = Peg(n);
    pegs.push_back(first_peg);

    // first peg will always have n rings on it, so start from second peg
    for (int peg_num = 1; peg_num < num_pegs; ++peg_num)
    {
        Peg empty_peg = Peg(0);
        pegs.push_back(empty_peg);
    }
}

// Precondition: peg_number is 1, 2, or 3.
// Postcondition: The return value is the number of rings on the specified peg.
std::size_t towers::many_rings(int peg_number) const
{
    Peg desired_peg = pegs[peg_number];
    return desired_peg.num_rings();

}

// Precondition: peg_number is 1, 2, or 3.
// Postcondition: If many_rings(peg_number_ > 0, then the return value is the diameter of the top ring on the specified
// peg; otherwise the return value is 0.
std::size_t towers::top_diameter(int peg_number) const
{
    Peg desired_peg = pegs[peg_number];
    return desired_peg.diameter_of_top_ring();

}

// Precondition: start_peg is a peg number (1, 2, or 3), and many_rings(start_peg) > 0; end_peg is a different
// peg_number (not equal to start_peg), and top_diameter(end_peg) is eitehr 0 or more than top_diameter(start_peg).
// Postcondition: The top ring has been moved from start_peg to end_peg.
void towers::move(int start_peg, int end_peg)
{

    std::cout << "Moving peg from peg #" << start_peg << " to peg #" << end_peg << std::endl;

    Peg starting_peg = pegs[start_peg];

    Peg ending_peg = pegs[end_peg];

    std::cout << "Before moving.. Start peg size: " << starting_peg.num_rings() <<
    " End peg size: " << ending_peg.num_rings() << std::endl;

    std::size_t desired_ring_diameter = starting_peg.diameter_of_top_ring();

    std::cout << "The ring at the top of the starting peg has size: " << desired_ring_diameter << std::endl;

    std::size_t destination_peg_top_ring_diameter = ending_peg.diameter_of_top_ring();

    std::cout << "The ring on the top of the ending peg has size: " << destination_peg_top_ring_diameter << std::endl;

    if (destination_peg_top_ring_diameter != 0 )
    {
        assert(destination_peg_top_ring_diameter > desired_ring_diameter);
    }

    starting_peg.pop_ring();

    // add it to top of end_peg

    ending_peg.push_ring(desired_ring_diameter);

    std::cout << "The ring at the top of the ending peg has size: " << ending_peg.diameter_of_top_ring() << std::endl;

    std::cout << "After moving. Start peg size: " << starting_peg.num_rings() <<
              " End peg size: " << ending_peg.num_rings() << std::endl;

}
