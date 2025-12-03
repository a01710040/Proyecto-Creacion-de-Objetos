#include <iostream>
#include "Vivero.h"

using namespace std;

int main() {
    // Creamos el objeto principal usando el constructor por defecto
    Vivero mi_vivero;
    
    // Variable para la opción del menú
    int opcion = -1; 

    // Variables temporales para la entrada del usuario
    string nombre_temp, material_temp, color_temp;
    double precio_temp, presupuesto_temp;
    int stock_temp;
    bool es_colgante_temp;
    int indice_cliente, indice_planta, indice_maceta; // Indices para ventas

    // Precarga para tener datos de prueba
    Cliente cliente_inicial("Ana Martinez", 500.0);
    mi_vivero.registrarCliente(cliente_inicial);
    mi_vivero.crearPlanta("Rosa Roja", 150.0, 3);
    mi_vivero.crearMaceta("Barro", "Arcilla", "Cafe", 40.0, false);
    
    // Bucle principal del menú
    while (opcion != 0) {
        cout << "\n=== MENU PRINCIPAL VIVERO ===" << endl;
        cout << "1. Crear nueva Planta" << endl;
        cout << "2. Crear nueva Maceta" << endl;
        cout << "3. Registrar Cliente" << endl;
        cout << "4. Mostrar Reporte" << endl;
        cout << "5. Realizar Venta Planta" << endl;
        cout << "6. Realizar Venta Maceta" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        
        // Manejo de error de entrada
        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Reiniciando menu." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue; 
        }

        if (opcion == 1) {
            // Crear Planta
            cout << "Nombre: "; cin >> nombre_temp;
            cout << "Precio: "; cin >> precio_temp;
            cout << "Stock: "; cin >> stock_temp;
            mi_vivero.crearPlanta(nombre_temp, precio_temp, stock_temp);
        }
        else if (opcion == 2) {
            // Crear Maceta
            cout << "Nombre: "; cin >> nombre_temp;
            cout << "Material: "; cin >> material_temp;
            cout << "Color: "; cin >> color_temp;
            cout << "Precio: "; cin >> precio_temp;
            cout << "Es colgante? (1=Si, 0=No): "; cin >> es_colgante_temp;
            mi_vivero.crearMaceta(nombre_temp, material_temp, color_temp, 
                                 precio_temp, es_colgante_temp);
        }
        else if (opcion == 3) {
            // Registrar Cliente
            cout << "Nombre: "; cin >> nombre_temp;
            cout << "Presupuesto: "; cin >> presupuesto_temp;
            Cliente nuevo_cliente(nombre_temp, presupuesto_temp);
            mi_vivero.registrarCliente(nuevo_cliente);
        }
        else if (opcion == 4) {
            // Reporte
            mi_vivero.mostrarInventario();
        }
        else if (opcion == 5) {
            // Venta Planta
            mi_vivero.mostrarInventario();
            cout << "Indice del Cliente: "; cin >> indice_cliente;
            cout << "Indice de la Planta: "; cin >> indice_planta;
            mi_vivero.realizarVenta(indice_cliente, indice_planta);
        }
        else if (opcion == 6) {
            // Venta Maceta
            mi_vivero.mostrarInventario();
            cout << "Indice del Cliente: "; cin >> indice_cliente;
            cout << "Indice de la Maceta: "; cin >> indice_maceta; 
            mi_vivero.realizarVentaMaceta(indice_cliente, indice_maceta);
        }
        else if (opcion == 0) {
            cout << "Saliendo del sistema..." << endl;
        }
        else {
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } 

    return 0;
}
