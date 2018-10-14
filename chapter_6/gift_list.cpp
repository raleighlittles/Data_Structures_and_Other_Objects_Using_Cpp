//
// Created by Raleigh Littles (raleigh) on 10/13/18 at 11:41 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "gift_list.h"

std::ostream &operator<<(std::ostream &os, const GiftList &list) {
    os << "gift_list: " << list.gift_list;
    return os;
}

void GiftList::add_gift(std::string user, std::string gift) {

}

void GiftList::delete_gift(std::string user, std::string gift) {

}

void GiftList::list_gifts(std::string user) {

}

void GiftList::add_user(std::string user) {

}

void GiftList::delete_user(std::string user) {

}

void GiftList::list_users(std::string user) {

}
