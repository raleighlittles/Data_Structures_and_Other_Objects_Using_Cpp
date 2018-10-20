//
// Created by Raleigh Littles (raleigh) on 10/13/18 at 11:41 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "gift_list.h"

void GiftList::add_gift(std::string user, std::string gift) {


    auto user_iterator = gift_list.find(user);

    if (user_iterator == gift_list.end()) {
        std::cout << "User (" << user << ") not found." << std::endl;
        // user not found
        std::set<std::string> new_user_gift_list = {gift};
        auto new_user_pair = std::make_pair(user, new_user_gift_list);

        gift_list.insert(new_user_pair);
    } else {
        // user already exists
        std::cout << "User (" << user << ") already exists" << std::endl;

        auto current_user_gift_element = gift_list.find(user);

        current_user_gift_element->second.insert(gift);
    }

}

void GiftList::delete_gift(std::string user, std::string gift) {


    auto existing_users_gift_list = gift_list.find(user);

    if (existing_users_gift_list != gift_list.end()) {

        auto it = existing_users_gift_list->second.erase(gift);

    }

}

void GiftList::list_gifts(std::string user) {

    auto user_it = gift_list.find(user);

    if (user_it != gift_list.end()) {
        std::cout << "Listing gifts for user: " << user << std::endl;

        auto users_gift_list = user_it->second;

        for (auto gift_it = users_gift_list.begin(); gift_it != users_gift_list.end(); gift_it++) {
            std::cout << *gift_it << std::endl;
        }
    } else {
        std::cout << "User " << user << " does not exist." << std::endl;
    }
}


void GiftList::delete_user(std::string user) {

    gift_list.erase(user);

}

void GiftList::list_users() {


    for (auto user_it = gift_list.begin(); user_it != gift_list.end(); user_it++) {
        std::cout << user_it->first << std::endl;
    }

}
