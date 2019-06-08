//
// Created by raleigh on 6/7/19.
//

#ifndef CHAPTER_14_PERSON_H

#include "date.h"

enum class Gender {
    MALE,
    FEMALE,
    OTHER
};

enum class ActivityLevel {
    SEDENTARY,
    LIGHTLY_ACTIVE,
    MODERATELY_ACTIVE,
    HIGHLY_ACTIVE
};

namespace ActivityLevels {
    double sedentary = 1.2;
    double lightly_active = 1.35;
    double moderately_active = 1.55;
    double highly_active = 1.725;
}

class Person {

public:

    Person(const std::string &first_name, const std::string &last_name, date::year_month_day birthday)
            : first_name(first_name), last_name(last_name), birthday(birthday) {

    }

    /**
     * Computes the Basal Metabolic Rate for a person
     *
     */
    virtual double compute_BMR() {
        return 0.0;
    }

    virtual void set_height(double height) {
        height_in_inches = height;
    }

    virtual double get_height() {
        return height_in_inches;
    }

    unsigned int get_age() {
        auto now = std::chrono::system_clock::now();

        auto today = date::year_month_day{date::floor<date::days>(now)};

        unsigned int age = (today.year() - birthday.year()).count();

        assert(age > 0);

        return age;
    }

    void set_weight(double weight) {
        this->weight_in_pounds = weight;
    }

    void set_activity_level(ActivityLevel activityLevel) {
        switch (activityLevel) {
            case (ActivityLevel::SEDENTARY): {
                activity_level = ActivityLevels::sedentary;
            }

            case (ActivityLevel::LIGHTLY_ACTIVE): {
                activity_level = ActivityLevels::lightly_active;
            }

            case (ActivityLevel::MODERATELY_ACTIVE): {
                activity_level = ActivityLevels::moderately_active;
            }

            case (ActivityLevel::HIGHLY_ACTIVE): {
                activity_level = ActivityLevels::highly_active;
            }
        }
    }

    double get_activity_level() {
        return activity_level;
    }

    double get_weight() {
        return weight_in_pounds;
    }

    Gender get_gender() {
        return gender;
    }

    void set_gender(char gender_letter) {
        if (toupper(gender_letter) == 'M') {
            this->gender = Gender::MALE;
        } else if (toupper(gender_letter) == 'L') {
            this->gender = Gender::FEMALE;
        } else {
            this->gender = Gender::OTHER;
        }

    }

    double compute_daily_caloric_intake() {
        return activity_level * compute_BMR();
    }

    friend std::ostream &operator<<(std::ostream &out, const Person &person) {
        out << person.last_name << ", " << person.first_name << std::endl;
        out << "DOB: " << person.birthday.year() << "/" << person.birthday.month() << "/" << person.birthday.day()
            << std::endl;
        out << "Ht: " << person.height_in_inches << "in.; Weight " << person.weight_in_pounds << " lbs." << std::endl;
        return out;
    }

protected:

    std::string first_name;
    std::string last_name;

    double height_in_inches = 0.0;

    date::year_month_day birthday;

    double weight_in_pounds = 0.0;

    double activity_level = 0.0;


    Gender gender = Gender::OTHER;


};

#define CHAPTER_14_PERSON_H

#endif //CHAPTER_14_PERSON_H
