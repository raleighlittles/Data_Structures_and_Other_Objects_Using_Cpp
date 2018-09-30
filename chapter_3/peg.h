//
// Created by Raleigh Littles (raleigh) on 9/22/18 at 12:28 AM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

/* This class was defined in Problem 12 of Chapter 13, and is used as a helper class for Problem 13 (Towers).
 *
 *
 */



#ifndef CHAPTER_3_PEG_H
#define CHAPTER_3_PEG_H

#include <cstdio>
#include <vector>
#include <iostream>

class Peg {

public:
    // (a)
    Peg(std::size_t rings = 64);

    // (b)
    std::size_t num_rings() const;

    // (c)
    std::size_t diameter_of_top_ring() const;

    // (d)
    void push_ring(std::size_t ring_diameter);

    // (e)
    void pop_ring();

    // (f)
    // an overloaded output function that prints some clever representatino of the peg and its rings


private:
    std::vector<std::size_t> ring_diameters;



};


#endif //CHAPTER_3_PEG_HPP
