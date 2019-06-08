//
// Created by raleigh on 6/7/19.
//

#ifndef CHAPTER_14_MALE_H

#include "Person.hpp"

class Male : public Person {

public:

    Male(const std::string &first_name, const std::string &last_name, date::year_month_day birthday,
         unsigned int height, double weight)
            : Person(first_name, last_name, birthday) {
        set_gender('M');
        set_height(height);
        set_weight(weight);
    }

    double compute_BMR() override {
        return 66 + (30.14 * weight_in_pounds) + (1.97 * height_in_inches) - (6.8 * get_age());
    }

    void set_height(double height) override {
        height_in_inches = height;
    }

    double get_height() override {
        return height_in_inches;
    }

};

#define CHAPTER_14_MALE_H

#endif //CHAPTER_14_MALE_H
