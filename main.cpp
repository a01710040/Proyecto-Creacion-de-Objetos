#include <iostream>
#include "Vivero.h"

using namespace std;

int main() {
    Vivero miVivero;
    int opcion = 0;

    string nom, mat, col;
    double pre;
    int stk;
    bool colg;
    int idxCli, idxPlan;

    Cliente c1("Cliente Prueba", 500.0);
    miVivero.registrarCliente(c1);

    do {
        cout << "\n=== MENU PRINCIPAL VIVERO ===" << endl;
        cout << "1. Crear nueva Planta" << endl;
        cout << "2. Crear nueva Maceta" << endl;
        cout << "3. Registrar Cliente" << endl;
        cout << "4. Mostrar Reporte" << endl;
        cout << "5. Realizar Venta" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Nombre: "; cin >> nom;
            cout << "Precio: "; cin >> pre;
            cout << "Stock: "; cin >> stk;
            miVivero.crearPlanta(nom, pre, stk);
        }
        else if (opcion == 2) {
            cout << "Nombre: "; cin >> nom;
            cout << "Material: "; cin >> mat;
            cout << "Color: "; cin >> col;
            cout << "Precio: "; cin >> pre;
            cout << "Es colgante? (1=Si, 0=No): "; cin >> colg;
            miVivero.crearMaceta(nom, mat, col, pre, colg);
        }
        else if (opcion == 3) {
            cout << "Nombre: "; cin >> nom;
            cout << "Presupuesto: "; cin >> pre;
            Cliente nuevoC(nom, pre);
            miVivero.registrarCliente(nuevoC);
        }
        else if (opcion == 4) {
            miVivero.mostrarInventario();
        }
        else if (opcion == 5) {
            miVivero.mostrarInventario();
            cout << "Indice del Cliente: "; cin >> idxCli;
            cout << "Indice de la Planta: "; cin >> idxPlan;
            miVivero.realizarVenta(idxCli, idxPlan);
        }
        else if (opcion == 0) {
            cout << "Saliendo del sistema..." << endl;
        }
        else {
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }

    } while (opcion != 0);

    return 0;
}
