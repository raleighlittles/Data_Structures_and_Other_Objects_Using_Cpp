//
// Created by Raleigh Littles (raleigh) on 9/9/18 at 4:44 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include <cstdio>

#ifndef CHAPTER_3_TOWER_H
#define CHAPTER_3_TOWER_H

class towers {

public:
    towers(std::size_t n = 64);

    std::size_t many_rings(int peg_number) const;

    std::size_t top_diameter(int peg_number) const;

    std::size_t move(int start_peg, int end_peg);


};

#endif //CHAPTER_3_TOWER_H
