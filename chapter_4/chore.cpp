//
// Created by Raleigh Littles (raleigh) on 9/29/18 at 11:22 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "chore.h"

chore::chore(std::string chores_filename) {

    std::ifstream chore_file_object;
    chore_file_object.open(chores_filename);


}

void chore::add_chore(std::string new_chore) {

    chores.push_back(new_chore);
}

std::size_t chore::count_chores() {

    return chores.size();
}

void chore::print_chores() {

}

void chore::delete_chore(std::string chore_to_delete) {

    auto  const chore_iterator = std::find(chores.begin(), chores.end(), chore_to_delete);

    assert(chore_iterator != chores.end());

    //auto index = std::distance(chores.begin(), chore_iterator);

    chores.erase(chore_iterator);
}

void chore::exit_program() {



}

