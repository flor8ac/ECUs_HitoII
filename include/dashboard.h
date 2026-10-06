#pragma once

#include "sensor.h"
#include "control.h"

void show_dashboard(const Vehicle_signals& data, ECUstate ecu_state, int cycle);