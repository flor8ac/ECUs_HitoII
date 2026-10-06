# ECUs_HitoII
Automotive C++ course

Goal of the project:
    Simulation of the Gateway ECU and Control ECU.

Arquitecture:
    Simulator -> Gateway -> Control -> Dashboard

    Machine States:
            - INIT
            - SELF_TEST
            - OPERATIONAL
            - DEGRADED
            - SAFE_STATE
            - SHUTDOWN


Vehicle Signals:
    - Velocity
    - RPM
    - Temperature
    - Battery Voltage
    - Oil Pressure

Ranges:
    - Velocity: 0 to 220 Km/H
    - RPM: 0 to 8000 rpm
    - Temperature: -20 to 130 centigrades
    - Battery Voltage: 10 to 15.5 Volts 
    - Oil Pressure: 0.5 a 6 bar

Gateway Funcionality:
    - Validate each signal.
    - Hold last value.

How to compile:
g++ -Wall -Wextra -pedantic -std=c++17 main.cpp src/*.cpp -Iinclude -o ecu_sim
./ecu_sim