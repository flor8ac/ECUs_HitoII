# ECUs_HitoII
Proyecto entregable para Hito II de C++ Automotriz

Objetivo del proyecto:
    Simulación de Gateway ECU y Control ECU.

Arquitectura:
    Simulador -> Gateway -> Control -> Dashboard

    Estados:
            - INIT
            - SELF_TEST
            - OPERATIONAL
            - DEGRADED
            - SAFE_STATE
            - SHUTDOWN


Señales utilizadas:
    - Velocidad
    - RPM
    - Temperatura
    - Voltaje Bateria
    - Presion de Aceite

Rangos utilizados:
    - Velocidad: 0 a 220 Km/H
    - RPM: 0 a 8000 rpm
    - Temperatura: -20 a 130 grados centigrados
    - Voltaje de la Bateria: 10 a 15.5 Volts 
    - Presion de Aceite: 0.5 a 6 bar

Responsabilidad del Gateway:
    - Recibir las señales simuladas.
    - Validar cada señal.
    - Determinar si cada señal es válida o inválida.
    - Mantener el último valor recibido.