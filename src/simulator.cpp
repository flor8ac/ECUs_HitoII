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