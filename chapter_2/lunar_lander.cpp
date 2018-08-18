//
// Created by Raleigh Littles (raleigh) on 8/17/18 at 10:50 PM.
// Copyright (c) 2018 ${ORGANIZATION_NAME} Raleigh Littles (raleigh). All rights reserved.
//

#include "lunar_lander.h"
#include <iostream>

void LunarLander::recalculate_values(float time_seconds)
{
    if ((this->fuel_flow_rate > 0) && (this->current_fuel_mass == 0))
    {
        // gas tank empty, no fuel left to even flow
        this->fuel_flow_rate = 0;
    }

    // recompute vertical velocity
    float vertical_speed_delta = compute_velocity_change(time_seconds);

    float new_vertical_speed = this->vertical_speed + vertical_speed_delta;
    this->vertical_speed = new_vertical_speed;

    // recompute altitude
    this->altitude = (time_seconds * this->vertical_speed);

    // recompute fuel available
    this->current_fuel_mass = time_seconds * this->fuel_flow_rate * this->max_fuel_consumption_rate;

    // check if lander has landed
    if (this->altitude <= 0)
    {
        std::cout << "Eagle has landed!" << std::endl;
        this->altitude = 0;
        this->vertical_speed = 0;
    }

    // check if lander ran out of fuel
    if (this->current_fuel_mass <= 0)
    {
        std::cout << "Oh no, ran out of fuel!" << std::endl;
        this->current_fuel_mass = 0;
    }

}

float LunarLander::compute_velocity_change(float time_seconds)
{
    float velocity_change = (time_seconds) * ((this->max_engine_thrust / (this->lander_mass + this->current_fuel_mass)) - this->MOON_GRAVITATIONAL_CONSTANT);
    return velocity_change;
}