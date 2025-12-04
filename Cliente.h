#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <iostream>
#include <string>

using namespace std;

/*
 * Clase Cliente: Representa a los clientes del vivero.
 * Contiene sus datos personales y su presupuesto actual.
 */
class Cliente {
private:
    string NombreCliente;
    double PresupuestoCliente;

public:
    // --- Declaraciones ---
    Cliente();
    Cliente(string NombreIn, double PresupuestoIn);
    
    string GetNombre() const;
    
    bool Comprar(double CostoCompra); // PascalCase
    void Mostrar();
};

/**
 * Constructor por defecto. Inicializa Cliente con valores base.
 *
 * @param Ninguno
 * @return Objeto Cliente
 */
Cliente::Cliente() {
    NombreCliente = "Sin Nombre";
    PresupuestoCliente = 0.0;
}

/**
 * Constructor con parámetros.
 *
 * @param string NombreIn: Nombre del cliente.
 * @param double PresupuestoIn: Dinero inicial del cliente.
 * @return Objeto Cliente
 */
Cliente::Cliente(string NombreIn, double PresupuestoIn) {
    NombreCliente = NombreIn;
    PresupuestoCliente = PresupuestoIn;
}

/**
 * Método getter para obtener el nombre del cliente.
 *
 * @param Ninguno
 * @return string: Nombre del cliente.
 */
string Cliente::GetNombre() const {
    return NombreCliente;
}

/**
 * Simula la compra. Verifica si hay presupuesto suficiente.
 *
 * @param double CostoCompra: Precio total de la compra.
 * @return bool: true si la compra fue exitosa, false si no.
 */
bool Cliente::Comprar(double CostoCompra) {
    if (PresupuestoCliente >= CostoCompra) {
        PresupuestoCliente = PresupuestoCliente - CostoCompra;
        return true;
    }
    return false;
}

/**
 * Método para mostrar el nombre y el saldo del cliente.
 *
 * @param Ninguno
 * @return void
 */
void Cliente::Mostrar() {
    cout << "Cliente: " << NombreCliente << " | Saldo: $" << 
        PresupuestoCliente << endl;
}

#endif // CLIENTE_H_
