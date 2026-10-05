#pragma once

#include <string>

enum class ECUstate{
    INIT,
    SELF_TEST,
    OPERATIONAL,
    DEGRADED,
    SAFE_STATE,
    SHUTDOWN
};

std::string ecu_state_text(ECUstate ecu_state);