#ifndef VIVERO_H
#define VIVERO_H

#include <iostream>
#include "Productos.h"
#include "Cliente.h"

using namespace std;

#define MAX 50

class Vivero {
private:
    // Arreglos fijos para la gestión de inventario
    Planta inventarioPlantas[MAX];
    Maceta inventarioMacetas[MAX];
    Cliente listaClientes[MAX];

    int contadorPlantas;
    int contadorMacetas;
    int contadorClientes;

public:
    Vivero();
    
    // COMPOSICIÓN (El Vivero crea los objetos)
    void crearPlanta(string nombre, double precio, int stock);
    void crearMaceta(string nombre, string material, string color, double precio, bool esColgante);

    // AGREGACIÓN (El Vivero registra el Cliente creado externamente)
    void registrarCliente(Cliente c);

    void mostrarInventario();
    void realizarVenta(int indiceCliente, int indicePlanta);
    void realizarVentaMaceta(int indiceCliente, int indiceMaceta);
};


// === IMPLEMENTACIÓN DE MÉTODOS ===

Vivero::Vivero() {
    contadorPlantas = 0;
    contadorMacetas = 0;
    contadorClientes = 0;
}

// COMPOSICIÓN
void Vivero::crearPlanta(string nombre, double precio, int stock) {
    if (contadorPlantas < MAX) {
        inventarioPlantas[contadorPlantas] = Planta(nombre, precio, stock);
        contadorPlantas++;
        cout << ">> Planta creada y agregada exitosamente." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

// COMPOSICIÓN
void Vivero::crearMaceta(string nombre, string material, string color, double precio, bool esColgante) {
    if (contadorMacetas < MAX) {
        inventarioMacetas[contadorMacetas] = Maceta(nombre, material, color, precio, esColgante);
        contadorMacetas++;
        cout << ">> Maceta creada y agregada exitosamente." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

// AGREGACIÓN
void Vivero::registrarCliente(Cliente c) {
    if (contadorClientes < MAX) {
        listaClientes[contadorClientes] = c;
        contadorClientes++;
        cout << ">> Cliente registrado exitosamente." << endl;
    } else {
        cout << "Error: Lista de clientes llena." << endl;
    }
}

void Vivero::mostrarInventario() {
    cout << "\n===== REPORTE VIVERO =====" << endl;
    
    cout << "--- Plantas (" << contadorPlantas << ") ---" << endl;
    for (int i = 0; i < contadorPlantas; i++) {
        cout << i << ". "; 
        inventarioPlantas[i].mostrar();
    }

    cout << "--- Macetas (" << contadorMacetas << ") ---" << endl;
    for (int i = 0; i < contadorMacetas; i++) {
        cout << i << ". ";
        inventarioMacetas[i].mostrar();
    }

    cout << "--- Clientes (" << contadorClientes << ") ---" << endl;
    for (int i = 0; i < contadorClientes; i++) {
        cout << i << ". ";
        listaClientes[i].mostrar();
    }
    cout << "==========================" << endl;
}

// VENTA DE PLANTAS
void Vivero::realizarVenta(int indiceCliente, int indicePlanta) {
    if (indiceCliente >= 0 && indiceCliente < contadorClientes && 
        indicePlanta >= 0 && indicePlanta < contadorPlantas) {
        
        Cliente elCliente = listaClientes[indiceCliente];
        Planta laPlanta = inventarioPlantas[indicePlanta];

        cout << "\nIntento de venta: " << elCliente.getNombre() << " quiere " << laPlanta.getNombre() << endl;

        if (laPlanta.getStock() > 0) {
            if (elCliente.comprar(laPlanta.getPrecio())) {
                laPlanta.actualizarStock(-1);
                cout << ">> Venta Exitosa!" << endl;

                // Guardar objetos modificados de vuelta
                listaClientes[indiceCliente] = elCliente;
                inventarioPlantas[indicePlanta] = laPlanta;
            } else {
                cout << ">> Saldo insuficiente." << endl;
            }
        } else {
            cout << ">> No hay stock." << endl;
        }
    } else {
        cout << ">> Error: Indices no validos." << endl;
    }
}

// VENTA DE MACETAS
void Vivero::realizarVentaMaceta(int indiceCliente, int indiceMaceta) {
    if (indiceCliente >= 0 && indiceCliente < contadorClientes && 
        indiceMaceta >= 0 && indiceMaceta < contadorMacetas) {
        
        Cliente elCliente = listaClientes[indiceCliente];
        Maceta laMaceta = inventarioMacetas[indiceMaceta];

        cout << "\nIntento de venta: " << elCliente.getNombre() << " quiere " << laMaceta.getNombre() << endl;

        if (elCliente.comprar(laMaceta.getPrecio())) {
            cout << ">> Venta Exitosa!" << endl;
            
            listaClientes[indiceCliente] = elCliente;
            
            // ELIMINAR MACETA DEL INVENTARIO (Desplazamiento)
            for (int i = indiceMaceta; i < contadorMacetas - 1; i++) {
                inventarioMacetas[i] = inventarioMacetas[i + 1];
            }
            contadorMacetas--;
        } else {
            cout << ">> Saldo insuficiente." << endl;
        }
    } else {
        cout << ">> Error: Indices no validos." << endl;
    }
}

#endif
