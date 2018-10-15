//
// Created by Raleigh Littles (raleigh) on 10/13/18 at 11:30 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#ifndef CHAPTER_6_GIFT_LIST_H
#define CHAPTER_6_GIFT_LIST_H

#include <list>
#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <set>
#include <algorithm>
#include <cassert>

class GiftList {
public:
    GiftList() = default;

    void add_gift(std::string user, std::string gift);

    void delete_gift(std::string user, std::string gift);

    void list_gifts(std::string user);

    friend std::ostream &operator<<(std::ostream &os, const GiftList &list);

    void add_user(std::string user);

    void delete_user(std::string user);

    void list_users(std::string user);


private:
    // sets are better since they enforce

    std::set<std::string> get_users_gift_list(std::string username) const;

    std::set<std::pair<std::string, std::set<std::string>>> gift_list;

};

#endif //CHAPTER_6_GIFT_LIST_H
