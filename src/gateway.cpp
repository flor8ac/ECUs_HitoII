#include "gateway.h"

bool validate_velocity(double velocity){
    return velocity >= 0.0 && velocity <= 220.0;
}

bool validate_rpm(int rpm){
    return rpm >= 0 && rpm <= 8000;
}

bool validate_temperature(double temperature){
    return temperature >= -20.0 && temperature <= 130.0;
}

bool validate_voltage(double voltage){
    return voltage >= 10.0 && voltage <= 15.5;
}

bool validate_pressure(double pressure){
    return pressure >= 0.5 && pressure <= 6.0;
}