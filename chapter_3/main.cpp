//
// Created by Raleigh Littles (raleigh) on 9/28/18 at 11:58 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "towers.h"


int main()
{
    std::size_t initial_pegs_number = 3;
    std::size_t initial_rings_number = 3;

    towers vietnam = towers(3, 3);

    std::cout << "At game start..." << std::endl;

    for (std::size_t i = 0; i < initial_pegs_number; i++)
    {
        std::cout << "Peg #" << i << " has " << vietnam.many_rings(i) << " rings on it." << std::endl;
    }

    vietnam.move(0, 1);


}