#pragma once
#include "sensor.h"

Vehicle_signals initial_signals();
Vehicle_signals update_simulation_values(const Vehicle_signals& current_data, int cycle);