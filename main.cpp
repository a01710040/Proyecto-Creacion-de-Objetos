#include <iostream>
#include "Vivero.h"

using namespace std;

int main() {
    // Creamos el objeto principal usando el constructor por defecto
    Vivero MiVivero;
    
    // Variable para la opción del menú
    int Opcion = -1; // PascalCase

    // Variables temporales para la entrada del usuario
    string NombreTemp, MaterialTemp, ColorTemp;
    double PrecioTemp, PresupuestoTemp;
    int StockTemp;
    bool EsColganteTemp;
    int IndiceCliente, IndicePlanta, IndiceMaceta; // Indices para ventas

    // Precarga para tener datos de prueba
    Cliente ClienteInicial("Ana Martinez", 500.0);
    MiVivero.RegistrarCliente(ClienteInicial);
    MiVivero.CrearPlanta("Rosa Roja", 150.0, 3);
    MiVivero.CrearMaceta("Barro", "Arcilla", "Cafe", 40.0, false);
    
    // Bucle principal del menú
    while (Opcion != 0) {
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
        if (!(cin >> Opcion)) {
            cout << "Entrada invalida. Reiniciando menu." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue; 
        }

        if (Opcion == 1) {
            // Crear Planta
            cout << "Nombre: "; cin >> NombreTemp;
            cout << "Precio: "; cin >> PrecioTemp;
            cout << "Stock: "; cin >> StockTemp;
            MiVivero.CrearPlanta(NombreTemp, PrecioTemp, StockTemp);
        }
        else if (Opcion == 2) {
            // Crear Maceta
            cout << "Nombre: "; cin >> NombreTemp;
            cout << "Material: "; cin >> MaterialTemp;
            cout << "Color: "; cin >> ColorTemp;
            cout << "Precio: "; cin >> PrecioTemp;
            cout << "Es colgante? (1=Si, 0=No): "; cin >> EsColganteTemp;
            MiVivero.CrearMaceta(NombreTemp, MaterialTemp, ColorTemp, 
                                 PrecioTemp, EsColganteTemp);
        }
        else if (Opcion == 3) {
            // Registrar Cliente
            cout << "Nombre: "; cin >> NombreTemp;
            cout << "Presupuesto: "; cin >> PresupuestoTemp;
            Cliente NuevoCliente(NombreTemp, PresupuestoTemp);
            MiVivero.RegistrarCliente(NuevoCliente);
        }
        else if (Opcion == 4) {
            // Reporte
            MiVivero.MostrarInventario();
        }
        else if (Opcion == 5) {
            // Venta Planta
            MiVivero.MostrarInventario();
            cout << "Indice del Cliente: "; cin >> IndiceCliente;
            cout << "Indice de la Planta: "; cin >> IndicePlanta;
            MiVivero.RealizarVenta(IndiceCliente, IndicePlanta);
        }
        else if (Opcion == 6) {
            // Venta Maceta
            MiVivero.MostrarInventario();
            cout << "Indice del Cliente: "; cin >> IndiceCliente;
            cout << "Indice de la Maceta: "; cin >> IndiceMaceta; 
            MiVivero.RealizarVentaMaceta(IndiceCliente, IndiceMaceta);
        }
        else if (Opcion == 0) {
            cout << "Saliendo del sistema..." << endl;
        }
        else {
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } 

    return 0;
}
