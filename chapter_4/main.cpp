//
// Created by Raleigh Littles (raleigh) on 10/6/18 at 10:41 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "ChoreManager.h"

int main()
{
    ChoreManager my_chores = ChoreManager("chores.txt");

    std::size_t chore_count = my_chores.count_chores();

    std::cout << "chore count: "  << chore_count << std::endl;

    std::cout<< "chore add..." << std::endl;

    my_chores.add_chore("go to the gym");
    chore_count = my_chores.count_chores();

    std::cout << "chore count: "  << chore_count << std::endl;

    my_chores.delete_chore("go to the gym");

    std::cout << "chore count: " << my_chores.count_chores() << std::endl;

    my_chores.delete_chore("eat pizza");

    my_chores.delete_chore("code");

    my_chores.print_chores();

    my_chores.exit_program();

}