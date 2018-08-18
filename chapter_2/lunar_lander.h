//
// Created by Raleigh Littles (raleigh) on 8/17/18 at 7:06 PM.
// Copyright (c) 2018 Raleigh Littles (raleigh). All rights reserved.
//

#ifndef CHAPTER_2_LUNAR_LANDER_H
#define CHAPTER_2_LUNAR_LANDER_H

class LunarLander {
    public:
        LunarLander() : fuel_flow_rate(0.0),
                        vertical_speed(0.0),
                        altitude(1000),
                        current_fuel_mass(1700),
                        lander_mass(900),
                        max_fuel_consumption_rate(10),
                        max_engine_thrust(5000)
        {

        }


        float get_fuel_flow_rate() const {return this->fuel_flow_rate;}

        float get_vertical_speed() const { return this->vertical_speed; }

        float get_altitude() const { return this->altitude; }

        float get_current_fuel_mass() const { return this->current_fuel_mass; }

        float get_lander_mass() const { return this->lander_mass; }

        float get_max_fuel_consumption_rate() const { return this->max_fuel_consumption_rate; }

        float get_max_engine_thrust() const { return this->max_engine_thrust; }

        void set_fuel_flow_rate(float desired_fuel_flow_rate) { this->fuel_flow_rate = desired_fuel_flow_rate; }

        void recalculate_values(float time_seconds);

    private:
        static constexpr float MOON_GRAVITATIONAL_CONSTANT = 1.625;

        float compute_velocity_change(float time_seconds);

        float fuel_flow_rate; // (none), fraction
        float vertical_speed; // m/s
        float altitude; // meters
        float current_fuel_mass; // kg
        float lander_mass; // kg
        float max_fuel_consumption_rate; // kg/sec
        float max_engine_thrust; // Newtons

};

#endif //CHAPTER_2_LUNAR_LANDER_H
