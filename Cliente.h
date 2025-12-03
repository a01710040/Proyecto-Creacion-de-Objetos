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
    string nombre_cliente;
    double presupuesto_cliente;

public:
    // Constructores
    Cliente();
    Cliente(string nombre_in, double presupuesto_in);
    
    // Getters
    string getNombre() const;
    
    // Métodos de gestión
    bool comprar(double costo_compra);
    void mostrar();
};

/**
 * Constructor por defecto. Inicializa Cliente con valores base.
 *
 * @param Ninguno
 * @return Objeto Cliente
 */
Cliente::Cliente() {
    nombre_cliente = "Sin Nombre";
    presupuesto_cliente = 0.0;
}

/**
 * Constructor con parámetros.
 *
 * @param string nombre_in: Nombre del cliente.
 * @param double presupuesto_in: Dinero inicial del cliente.
 * @return Objeto Cliente
 */
Cliente::Cliente(string nombre_in, double presupuesto_in) {
    nombre_cliente = nombre_in;
    presupuesto_cliente = presupuesto_in;
}

// Implementación del getter para obtener el nombre
string Cliente::getNombre() const {
    return nombre_cliente;
}

/**
 * Simula la compra. Verifica si hay presupuesto suficiente.
 *
 * @param double costo_compra: Precio total de la compra.
 * @return bool: true si la compra fue exitosa, false si no.
 */
bool Cliente::comprar(double costo_compra) {
    if (presupuesto_cliente >= costo_compra) {
        presupuesto_cliente = presupuesto_cliente - costo_compra;
        return true;
    }
    return false;
}

// Método para mostrar el nombre y el saldo del cliente
void Cliente::mostrar() {
    cout << "Cliente: " << nombre_cliente << " | Saldo: $" << 
        presupuesto_cliente << endl;
}

#endif // CLIENTE_H_
