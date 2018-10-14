//
// Created by Raleigh Littles (raleigh) on 10/13/18 at 11:41 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "gift_list.h"

std::ostream &operator<<(std::ostream &os, const GiftList &list) {
    os << "gift_list: " << list.gift_list;
    return os;
}
