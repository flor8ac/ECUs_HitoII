#include <random>
#include "simulator.h"

Vehicle_signals initial_signals(){
    Vehicle_signals init_data;

    init_data.velocity.current_value = 0.0;
    init_data.velocity.status = 1;
    init_data.velocity.update_cycle = 0;
    init_data.velocity.previous_value = 0.0;

    init_data.rpm.current_value = 800;
    init_data.rpm.status = 1;
    init_data.rpm.update_cycle = 0;
    init_data.rpm.previous_value = 0;

    init_data.temperature.current_value = 25.0;
    init_data.temperature.status = 1;
    init_data.temperature.update_cycle = 0;
    init_data.temperature.previous_value = 0;

    init_data.voltage.current_value = 12.5;
    init_data.voltage.status = 1;
    init_data.voltage.update_cycle = 0;
    init_data.voltage.previous_value = 0;

    init_data.pressure.current_value = 2.5;
    init_data.pressure.status = 1;
    init_data.pressure.update_cycle = 0;
    init_data.pressure.previous_value = 0;

    return init_data;
}

static std::mt19937 generator(42);

double generate_random_number(double minimum, double maximum){
    std::uniform_real_distribution<double> distribution(minimum, maximum);

    return distribution(generator);
}

Vehicle_signals update_simulation_values(const Vehicle_signals& current_data, int cycle){
    Vehicle_signals new_data = current_data;

    new_data.velocity.previous_value = current_data.velocity.current_value;
    new_data.velocity.current_value += generate_random_number(-2.0, 4.0);
    new_data.velocity.update_cycle = cycle;

    /*
    if (new_data.velocity.current_value < 0){
        new_data.velocity.current_value = 0;
    }

    if (new_data.velocity.current_value > 180.0){
        new_data.velocity.current_value = 180.0;
    }
    */

    new_data.rpm.previous_value = current_data.rpm.current_value;
    new_data.rpm.current_value = 800 + static_cast<int>(new_data.velocity.current_value * 30.0) + static_cast<int>(generate_random_number(-150, 150));
    new_data.rpm.update_cycle = cycle;

    /*
    if (new_data.rpm.current_value < 750){
        new_data.rpm.current_value = 750;
    }

    if (new_data.rpm.current_value > 6500){
        new_data.rpm.current_value = 6500;
    }
    */

    new_data.temperature.previous_value = current_data.temperature.current_value;
    if(new_data.temperature.current_value < 90.0){
        new_data.temperature.current_value += generate_random_number(0.1, 0.6);
    }

    else
    {
        new_data.temperature.current_value += generate_random_number(-0.2, 0.2);
    }
    new_data.temperature.update_cycle = cycle;

    new_data.voltage.previous_value = current_data.voltage.current_value;
    new_data.voltage.current_value = 13.8 + generate_random_number(-2, 2);
    new_data.voltage.update_cycle = cycle;

    new_data.pressure.previous_value = current_data.pressure.current_value;
    new_data.pressure.current_value = 1.5 + new_data.rpm.current_value/2000.0 + generate_random_number(-0.15, 0.15);
    new_data.pressure.update_cycle = cycle;

    return new_data;
}