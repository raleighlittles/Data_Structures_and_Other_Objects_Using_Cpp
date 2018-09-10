//
// Created by Raleigh Littles (raleigh) on 9/9/18 at 4:44 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "tower.h"
#include <cstdio>


// Precondition: 1 <= n <= 64.
// Postcondition: The twoers have been initialized with n rings on the first peg and no rings on the other two pegs.
// The diameters of the first peg's rings are from one inch (on the top) to n inches (on the bottom)
tower::towers(std::size_t n = 64)
{

}

// Precondition: peg_number is 1, 2, or 3.
// Postcondition: The return value is the number of rings on the specified peg.
std::size_t towers::many_rings(int peg_number) const
{

}

// Precondition: peg_number is 1, 2, or 3.
// Postcondition: If many_rings(peg_number_ > 0, then the return value is the diameter of the top ring on the specified
// peg; otherwise the return value is 0.
std::size_t towers::top_diameter(int peg_number) const
{

}

// Precondition: start_peg is a peg number (1, 2, or 3), and many_rings(start_peg) > 0; end_peg is a different
// peg_number (not equal to start_peg), and top_diameter(end_peg) is eitehr 0 or more than top_diameter(start_peg).
// Postcondition: The top ring has been moved from start_peg to end_peg.
std::size_t towers::move(int start_peg, int end_peg)
{

}