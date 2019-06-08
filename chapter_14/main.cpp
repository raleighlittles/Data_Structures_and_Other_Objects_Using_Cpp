#include "Person.hpp"
#include "Female.hpp"
#include "Male.hpp"
#include "MembershipRoster.hpp"

#include <iostream>

int main() {
    Female first("Jane", "Roe", date::year(2000) / date::month(1) / date::day(1), 72, 150);

    Male second("John", "Doe", date::year(1999) / date::month(1) / date::day(1), 80, 200);

    const std::vector<Person> v = {first, second};

    MembershipRoster m(v);

    assert(m.compute_average_weight(Gender::MALE) == second.get_weight());

}
