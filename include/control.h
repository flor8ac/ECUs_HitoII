#pragma once

#include <string>
#include "sensor.h"

enum class ECUstate{
    INIT,
    SELF_TEST,
    OPERATIONAL,
    DEGRADED,
    SAFE_STATE,
    SHUTDOWN
};

std::string ecu_state_text(ECUstate ecu_state);

ECUstate control_ecu(ECUstate ecu_state, Vehicle_signals& data, int cycle);