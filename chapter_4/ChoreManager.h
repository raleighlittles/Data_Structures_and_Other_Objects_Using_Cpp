//
// Created by Raleigh Littles (raleigh) on 9/29/18 at 11:18 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

#ifndef CHAPTER_4_CHORE_H
#define CHAPTER_4_CHORE_H

class ChoreManager
{
public:
    ChoreManager(std::string chores_filename);

    void add_chore(std::string new_chore);

    std::size_t count_chores();

    void print_chores();

    void delete_chore(std::string chore_to_delete);

    void exit_program();

private:
    std::vector<std::string> chores;
    std::string chores_filename;
};

#endif //CHAPTER_4_CHORE_H
