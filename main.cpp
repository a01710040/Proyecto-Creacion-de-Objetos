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
        cout << "1. Crear nueva Planta (Composicion)" << endl;
        cout << "2. Crear nueva Maceta (Composicion)" << endl;
        cout << "3. Registrar Cliente (Agregacion)" << endl;
        cout << "4. Mostrar Reporte" << endl;
        cout << "5. Realizar Venta" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Nombre: "; cin >> nom;
                cout << "Precio: "; cin >> pre;
                cout << "Stock: "; cin >> stk;
                miVivero.crearPlanta(nom, pre, stk);
                break;

            case 2:
                cout << "Nombre: "; cin >> nom;
                cout << "Material: "; cin >> mat;
                cout << "Color: "; cin >> col;
                cout << "Precio: "; cin >> pre;
                cout << "Es colgante? (1=Si, 0=No): "; cin >> colg;
                miVivero.crearMaceta(nom, mat, col, pre, colg);
                break;

            case 3: 
                cout << "Nombre: "; cin >> nom;
                cout << "Presupuesto: "; cin >> pre;
                {
                    Cliente nuevoC(nom, pre);
                    miVivero.registrarCliente(nuevoC);
                }
                break;

            case 4:
                miVivero.mostrarInventario();
                break;

            case 5:
                miVivero.mostrarInventario();
                cout << "Indice del Cliente: "; cin >> idxCli;
                cout << "Indice de la Planta: "; cin >> idxPlan;
                miVivero.realizarVenta(idxCli, idxPlan);
                break;

            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 0);

    return 0;
}
