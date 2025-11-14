#include <iostream>
#include "Planta.h"
#include "Maceta.h"
#include "Cliente.h"

int main() {
    cout << "--- Probando Vivero (Versión Final Simplificada) ---" << endl << endl;

    // 1. Probar Planta
    Planta miPlanta("Rosa", 50.0);
    miPlanta.mostrar();
    miPlanta.setPrecio(60.0);
    cout << "El nuevo precio de la planta es: $" << miPlanta.getPrecio() << endl;
    cout << "--------------------" << endl;

    // 2. Probar Maceta
    Maceta miMaceta("Barro", "Rojo");
    miMaceta.mostrar();
    miMaceta.setColor("Azul");
    cout << "El nuevo color de la maceta es: " << miMaceta.getColor() << endl;
    cout << "--------------------" << endl;
    
    // 3. Probar Cliente
    Cliente miCliente("Luis");
    miCliente.saludar();
    miCliente.setNombre("Luis Pérez");
    cout << "El nuevo nombre del cliente es: " << miCliente.getNombre() << endl;
    cout << "--------------------" << endl;
    
    cout << "--- Pruebas finalizadas ---" << endl;

    return 0;
}
