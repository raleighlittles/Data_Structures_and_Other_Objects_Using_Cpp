//
// Created by Raleigh Littles (raleigh) on 9/29/18 at 11:22 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "ChoreManager.h"

ChoreManager::ChoreManager(std::string chores_filename) {

    this->chores_filename = chores_filename;

    std::ifstream chore_file_object;
    chore_file_object.open(chores_filename);

    if (!chore_file_object)
    {
        std::cout << "Unable to open file." << std::endl;
        exit(1);
    }

    std::string current_chore;
    while (std::getline(chore_file_object, current_chore))
    {
        chores.push_back(current_chore);
    }

    chore_file_object.close();

    std::cout << "Finished adding " << chores.size() << " chores, read from file." << std::endl;
}

void ChoreManager::add_chore(std::string new_chore) {

    chores.push_back(new_chore);
}

std::size_t ChoreManager::count_chores() {

    return chores.size();
}

void ChoreManager::print_chores() {

    std::sort(chores.begin(), chores.end());

    for (auto it = chores.begin(); it != chores.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

}

void ChoreManager::delete_chore(std::string chore_to_delete) {

    auto  const chore_iterator = std::find(chores.begin(), chores.end(), chore_to_delete);

    assert(chore_iterator != chores.end());

    //auto index = std::distance(chores.begin(), chore_iterator);

    chores.erase(chore_iterator);
}

void ChoreManager::exit_program() {

    std::ofstream chore_file_object;
    chore_file_object.open(chores_filename, std::ofstream::out | std::ofstream::trunc);

    for (auto it = chores.begin(); it != chores.end(); ++it)
    {
        chore_file_object << *it << std::endl;
    }

    chore_file_object.close();

}

