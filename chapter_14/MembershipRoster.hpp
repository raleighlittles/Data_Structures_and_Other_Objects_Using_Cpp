//
// Created by raleigh on 6/8/19.
//

#ifndef CHAPTER_14_MEMBERSHIPROSTER_H

#include <vector>
#include <numeric>
#include "Person.hpp"

class MembershipRoster {
public:

    explicit MembershipRoster(const std::vector<Person> &members)
            : members(members) {

    }

    double compute_average_weight(Gender gender) {
        return std::accumulate(members.begin(), members.end(), 0.0, [&](double current_sum, Person &p) {
            return current_sum + ((p.get_gender() == gender) ? p.get_weight() : 0.0);
        })
               / count_members_with_gender(gender);

    }

    long compute_average_age(Gender gender) {
        return std::accumulate(members.begin(), members.end(), 0, [&](double current_sum, Person &p) {
            return current_sum + ((p.get_gender() == gender) ? p.get_age() : 0);
        }) / count_members_with_gender(gender);

    }


    double compute_average_activity_level(Gender gender) {
        return std::accumulate(members.begin(), members.end(), 0.0, [&](double current_sum, Person &p) {
            return current_sum + ((p.get_gender() == gender) ? p.get_activity_level() : 0.0);
        }) / count_members_with_gender(gender);
    }

protected:

    std::vector<Person> members;


private:

    long count_members_with_gender(Gender gender) {
        return std::count_if(members.begin(), members.end(), [&](Person &p) { return p.get_gender() == gender; });
    }


};

#define CHAPTER_14_MEMBERSHIPROSTER_H

#endif //CHAPTER_14_MEMBERSHIPROSTER_H
