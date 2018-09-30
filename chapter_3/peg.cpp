//
// Created by Raleigh Littles (raleigh) on 9/29/18 at 12:17 AM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "peg.h"


Peg::Peg(std::size_t rings)
{
    for (std::size_t ring = 0; ring < rings; ring++)
    {
        ring_diameters.push_back(ring+1);
    }

    std::cout << "Peg initialized with " << ring_diameters.size() << " rings on it. " << std::endl;
}

std::size_t Peg::num_rings() const
{
    return ring_diameters.size();
}

std::size_t Peg::diameter_of_top_ring() const
{
    if (ring_diameters.size() > 0)
    {
        return ring_diameters.back();
    }

    else if (ring_diameters.size() == 0)
    {
        return 0;
    }
}

void Peg::push_ring(std::size_t ring_diameter)
{
    std::cout << "Adding ring to peg." << std::endl;
    ring_diameters.push_back(ring_diameter);
    std::cout << "The current peg now has size: " << ring_diameters.size() << std::endl;
}

void Peg::pop_ring()
{
    std::cout << "Deleting ring from top of peg." << std::endl;
    ring_diameters.pop_back();
    std::cout << "Peg size is now: " << ring_diameters.size() << std::endl;
}