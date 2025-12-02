#include <iostream>
#include "Vivero.h"

using namespace std;

int main() {
    Vivero miVivero;
    
    // Inicializamos en -1 para que el ciclo 'while' pueda comenzar
    int opcion = -1; 

    // Variables temporales para el menú
    string nom, mat, col;
    double pre;
    int stk;
    bool colg;
    int idxCli, idxPlan, idxMace; // Indices para ventas

    // Precarga para tener datos de prueba
    Cliente c1("Ana Martinez", 500.0);
    miVivero.registrarCliente(c1);
    miVivero.crearPlanta("Rosa Roja", 150.0, 3);
    miVivero.crearMaceta("Barro", "Arcilla", "Café", 40.0, false);
    
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
        
        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Reiniciando menu." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue; 
        }

        if (opcion == 1) {
            // Crear Planta
            cout << "Nombre: "; cin >> nom;
            cout << "Precio: "; cin >> pre;
            cout << "Stock: "; cin >> stk;
            miVivero.crearPlanta(nom, pre, stk);
        }
        else if (opcion == 2) {
            // Crear Maceta
            cout << "Nombre: "; cin >> nom;
            cout << "Material: "; cin >> mat;
            cout << "Color: "; cin >> col;
            cout << "Precio: "; cin >> pre;
            cout << "Es colgante? (1=Si, 0=No): "; cin >> colg;
            miVivero.crearMaceta(nom, mat, col, pre, colg);
        }
        else if (opcion == 3) {
            // Registrar Cliente
            cout << "Nombre: "; cin >> nom;
            cout << "Presupuesto: "; cin >> pre;
            Cliente nuevoC(nom, pre);
            miVivero.registrarCliente(nuevoC);
        }
        else if (opcion == 4) {
            // Reporte
            miVivero.mostrarInventario();
        }
        else if (opcion == 5) {
            // Venta Planta
            miVivero.mostrarInventario();
            cout << "Indice del Cliente: "; cin >> idxCli;
            cout << "Indice de la Planta: "; cin >> idxPlan;
            miVivero.realizarVenta(idxCli, idxPlan);
        }
        else if (opcion == 6) {
            // Venta Maceta
            miVivero.mostrarInventario();
            cout << "Indice del Cliente: "; cin >> idxCli;
            cout << "Indice de la Maceta: "; cin >> idxMace; 
            miVivero.realizarVentaMaceta(idxCli, idxMace);
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
