#include "include/control.h"

std::string ecu_state_text(ECUstate ecu_state){
    switch(ecu_state){
        case ECUstate::INIT:
            return "INIT";

        case ECUstate::SELF_TEST:
            return "SELF_TEST";

        case ECUstate::OPERATIONAL:
            return "OPERATIONAL";

        case ECUstate::DEGRADED:
            return "DEGRADED";

        case ECUstate::SAFE_STATE:
            return "SAFE_STATE";

        case ECUstate::SHUTDOWN:
            return "SHUTDOWN";
    }
    return "DESCONOCIDO";
}
