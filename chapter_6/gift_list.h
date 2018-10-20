//
// Created by Raleigh Littles (raleigh) on 10/13/18 at 11:30 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include <list>
#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <set>
#include <algorithm>
#include <cassert>
#include <map>


#ifndef CHAPTER_6_GIFT_LIST_H
#define CHAPTER_6_GIFT_LIST_H

class GiftList {
public:
    GiftList() {};

    void add_gift(std::string user, std::string gift);

    void delete_gift(std::string user, std::string gift);

    void list_gifts(std::string user);

    void delete_user(std::string user);

    void list_users();

private:

    std::map<std::string, std::set<std::string>> gift_list;

};

#endif //CHAPTER_6_GIFT_LIST_H
