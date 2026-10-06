#pragma once

struct Velocity {
    double current_value;
    bool status;
    int update_cycle;
    double previous_value;
};

struct RPM {
    double current_value;
    bool status;
    int update_cycle;
    double previous_value;
};

struct Temperature {
    double current_value;
    bool status;
    int update_cycle;
    double previous_value;
};

struct Voltage {
    double current_value;
    bool status;
    int update_cycle;
    double previous_value;
};

struct Pressure {
    double current_value;
    bool status;
    int update_cycle;
    double previous_value;
};

struct Vehicle_signals{
    Velocity velocity;
    RPM rpm;
    Temperature temperature;
    Voltage voltage;
    Pressure pressure;
};