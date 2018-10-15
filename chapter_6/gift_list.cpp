//
// Created by Raleigh Littles (raleigh) on 10/13/18 at 11:41 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "gift_list.h"

std::ostream &operator<<(std::ostream &os, const GiftList &list) {


}


std::set<std::string> GiftList::get_users_gift_list(std::string username) const
{
    auto users_list_pair = std::find_if(gift_list.begin(), gift_list.end(),
                                        [username](std::pair<std::string, std::set<std::string>> const &pairs) {
                                            return pairs.first == username;
                                        });

    return users_list_pair->second;
}

void GiftList::add_gift(std::string user, std::string gift) {

    std::set<std::string> users_gift_set = get_users_gift_list(user);

    auto ret = users_gift_set.insert(gift);

}

void GiftList::delete_gift(std::string user, std::string gift) {

    std::set<std::string> users_gift_set = get_users_gift_list(user);

    auto ret = users_gift_set.erase(gift);

}

void GiftList::list_gifts(std::string user) {

    std::set<std::string> users_gift_set = get_users_gift_list(user);

    std::cout << "User " << user << "has the following gifts: { ";

    for (auto it = users_gift_set.begin(); it != users_gift_set.end(); ++ it)
    {
        std::cout << *it << " | ";
    }

    std::cout << "}" << std::endl;
}

void GiftList::add_user(std::string user) {

    auto user_pair = std::find_if(gift_list.begin(), gift_list.end(),
                                  [user](std::pair<std::string, std::set<std::string>> const &pairs) {
                                      return pairs.first == user;
                                  });

    if (user_pair != gift_list.end())
    {
        auto new_user_pair = std::make_pair(user, std::set<std::string>());
        gift_list.insert(new_user_pair);
    }
}

void GiftList::delete_user(std::string user) {

    auto user_pair = std::find_if(gift_list.begin(), gift_list.end(),
                                  [user](std::pair<std::string, std::set<std::string>> const &pairs) {
                                      return pairs.first == user;
                                  });

    if (user_pair != gift_list.end())
    {
        gift_list.erase(user_pair);
    }

}

void GiftList::list_users(std::string user) {

    for (auto user_it = gift_list.begin(); user_it != gift_list.end(); user_it++)
    {
        std::cout << "Current user: " << user_it->first << "( " << user_it->second.size() << " gifts)" << std::endl;


        std::cout << "{ ";
        for (auto gifts_it = user_it->second.begin(); gifts_it != user_it->second.end(); ++gifts_it)
        {
            std::cout << *gifts_it << " | ";
        }

        std::cout << "}" << std::endl;

    }

}
