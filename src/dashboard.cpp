#include "dashboard.h"

#include <iostream>  // Se usa para impresión básica
#include <iomanip>  // Se usa para comandos de escape o fix para formato
#include <string>  // Se usa para manejar strings
#include <sstream>  // Nos permite hacer operaciones complejas con string
#include <cstdlib>  // Nos permite hacer operaciones referentes al sistema y su terminal


void show_dashboard(const Vehicle_signals& data, ECUstate ecu_state, int cycle){
     system("clear");
     std::cout << "=============================================================\n";

    std::cout << "                    ECU DASHBOARD\n";

    std::cout << "=============================================================\n";

    std::cout << "ECU Status        : " << ecu_state_text(ecu_state) << "\n\n";

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "SIGNAL              VALUE        STATUS     UPDATED CYCLE" <<"\n";

    std::cout << "Velocity          : " << data.velocity.current_value << " km/h   -  " << ((data.velocity.status) ? "Valid" : "Invalid") << "   -   " << data.velocity.update_cycle <<"\n";

    std::cout << "RPM               : " << data.rpm.current_value << " rpm  -  " << ((data.rpm.status) ? "Valid" : "Invalid") << "   -   " << data.velocity.update_cycle << "\n";
    
    std::cout << "Temperature       : " << data.temperature.current_value << " C     -  " << ((data.temperature.status) ? "Valid" : "Invalid") << "   -   " << data.velocity.update_cycle << "\n";

    std::cout << "Battery Voltage   : " << data.voltage.current_value << " V     -  " << ((data.voltage.status) ? "Valid" : "Invalid") << "   -   " << data.velocity.update_cycle << "\n";

    std::cout << "Oil Pressure      : " << data.pressure.current_value << " psi    -  " << ((data.pressure.status) ? "Valid" : "Invalid") << "   -   " << data.velocity.update_cycle << "\n";

    std::cout << "\n";

    std::cout << "Cycle             : " << cycle << "\n";

    std::cout << "=============================================================\n";

}