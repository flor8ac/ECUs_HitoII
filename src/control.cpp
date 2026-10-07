#include <chrono>
#include <thread>
#include "control.h"


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

ECUstate control_ecu(ECUstate ecu_state, Vehicle_signals& data, int cycle){
    switch(ecu_state){
        case ECUstate::INIT:
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            return ECUstate::SELF_TEST;

        case ECUstate::SELF_TEST:
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            return ECUstate::OPERATIONAL;

        case ECUstate::OPERATIONAL:
            if(!data.voltage.status){
                return ECUstate::SAFE_STATE;
            }else if(!data.temperature.status){
                return ECUstate::DEGRADED;
            }else{
                return ECUstate::OPERATIONAL;
            }
            break;
        case ECUstate::DEGRADED:
            return ECUstate::SAFE_STATE;

        case ECUstate::SAFE_STATE:
            return ECUstate::SHUTDOWN;

        case ECUstate::SHUTDOWN:
            return ECUstate::SHUTDOWN;
    }
    return ECUstate::SHUTDOWN;
}
