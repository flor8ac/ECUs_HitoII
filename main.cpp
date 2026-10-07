#include <iostream>
#include <chrono>
#include <thread>
#include "include/control.h"
#include "include/simulator.h"
#include "include/dashboard.h"
#include "include/gateway.h"

int main(){

    /* Car engine ignition ON initial values */
    int cycle = 0;
    ECUstate estado = ECUstate::INIT;
    Vehicle_signals mycar = initial_signals();
    show_dashboard(mycar, estado, cycle);
    
    /* INIT -> SELF_TEST -> OPERATIONAL */
    for(cycle=1;cycle<2;cycle++){
        estado = control_ecu(estado, mycar,cycle);
        show_dashboard(mycar, estado, cycle);
    }

    while (cycle < 10){

        /* Simulator data entry */
        mycar = update_simulation_values(mycar);

        /* Gateway validation */
        mycar.velocity.status = validate_velocity(mycar.velocity.current_value);
        mycar.rpm.status = validate_rpm(mycar.rpm.current_value);
        mycar.temperature.status = validate_temperature(mycar.temperature.current_value);
        mycar.voltage.status = validate_voltage(mycar.voltage.current_value);
        mycar.pressure.status = validate_pressure(mycar.pressure.current_value);
        
        estado = control_ecu(estado, mycar,cycle);
        show_dashboard(mycar, estado, cycle);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cycle++;
    }
    
    return 0;
}
