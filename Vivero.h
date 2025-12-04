#ifndef VIVERO_H_
#define VIVERO_H_

#include <iostream>
#include "Productos.h"
#include "Cliente.h"

using namespace std;

// Constante para el tamaño máximo de los arreglos
#define MAX_INVENTARIO 50

/*
 * Clase Vivero: Clase Gestora
 */
class Vivero {
private:
    // Atributos colecciones
    Planta InventarioPlantas[MAX_INVENTARIO];
    Maceta InventarioMacetas[MAX_INVENTARIO];
    Cliente ListaClientes[MAX_INVENTARIO];

    // Contadores
    int ContadorPlantas;
    int ContadorMacetas;
    int ContadorClientes;

public:
    // --- Declaraciones de Constructores ---
    Vivero();
    Vivero(int ContP, int ContM, int ContC);
    
    // --- Declaraciones de Métodos ---
    void CrearPlanta(string Nombre, double Precio, int Stock);
    void CrearMaceta(string Nombre, string Material, string Color, 
                     double Precio, bool EsColgante);

    void RegistrarCliente(Cliente C);

    void MostrarInventario();
    void RealizarVenta(int IndiceCliente, int IndicePlanta);
    void RealizarVentaMaceta(int IndiceCliente, int IndiceMaceta);
};


/**
 * Constructor por Defecto: Inicializa el Vivero vacío.
 *
 * @param Ninguno
 * @return Objeto Vivero
 */
Vivero::Vivero() {
    cout << ">> Vivero creado (Vacio)." << endl;
    ContadorPlantas = 0;
    ContadorMacetas = 0;
    ContadorClientes = 0;
}

/**
 * Constructor con Parámetros: Inicializa los contadores.
 *
 * @param int ContP: Contador inicial de plantas.
 * @param int ContM: Contador inicial de macetas.
 * @param int ContC: Contador inicial de clientes.
 * @return Objeto Vivero
 */
Vivero::Vivero(int ContP, int ContM, int ContC) {
    cout << ">> Vivero creado con contadores iniciales." << endl;
    ContadorPlantas = ContP;
    ContadorMacetas = ContM;
    ContadorClientes = ContC;
}

/**
 * Método para crear y agregar una Planta al inventario.
 *
 * @param string Nombre: Nombre de la planta.
 * @param double Precio: Precio de la planta.
 * @param int Stock: Stock inicial.
 * @return void
 */
void Vivero::CrearPlanta(string Nombre, double Precio, int Stock) {
    if (ContadorPlantas < MAX_INVENTARIO) {
        InventarioPlantas[ContadorPlantas] = 
            Planta(Nombre, Precio, Stock);
        ContadorPlantas++;
        cout << ">> Planta creada y agregada exitosamente." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

/**
 * Método para crear y agregar una Maceta al inventario.
 *
 * @param string Nombre: Nombre de la maceta.
 * @param string Material: Material de la maceta.
 * @param string Color: Color de la maceta.
 * @param double Precio: Precio de la maceta.
 * @param bool EsColgante: Si la maceta es colgante.
 * @return void
 */
void Vivero::CrearMaceta(string Nombre, string Material, string Color, 
                         double Precio, bool EsColgante) {
    if (ContadorMacetas < MAX_INVENTARIO) {
        InventarioMacetas[ContadorMacetas] = 
            Maceta(Nombre, Material, Color, Precio, EsColgante);
        ContadorMacetas++;
        cout << ">> Maceta creada y agregada exitosamente." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

/**
 * Método para registrar un Cliente.
 *
 * @param Cliente C: Objeto Cliente a registrar.
 * @return void
 */
void Vivero::RegistrarCliente(Cliente C) {
    if (ContadorClientes < MAX_INVENTARIO) {
        ListaClientes[ContadorClientes] = C;
        ContadorClientes++;
        cout << ">> Cliente registrado exitosamente." << endl;
    } else {
        cout << "Error: Lista de clientes llena." << endl;
    }
}

/**
 * Método para mostrar el inventario completo y la lista de clientes.
 *
 * @param Ninguno
 * @return void
 */
void Vivero::MostrarInventario() {
    cout << "\n===== REPORTE VIVERO =====" << endl;
    
    cout << "--- Plantas (" << ContadorPlantas << ") ---" << endl;
    for (int I = 0; I < ContadorPlantas; I++) {
        cout << I << ". "; 
        InventarioPlantas[I].Mostrar();
    }

    cout << "--- Macetas (" << ContadorMacetas << ") ---" << endl;
    for (int I = 0; I < ContadorMacetas; I++) {
        cout << I << ". ";
        InventarioMacetas[I].Mostrar();
    }

    cout << "--- Clientes (" << ContadorClientes << ") ---" << endl;
    for (int I = 0; I < ContadorClientes; I++) {
        cout << I << ". ";
        ListaClientes[I].Mostrar();
    }
    cout << "==========================" << endl;
}

/**
 * Realiza la venta de una Planta y actualiza el stock/saldo.
 *
 * @param int IndiceCliente: Índice del cliente.
 * @param int IndicePlanta: Índice de la planta.
 * @return void
 */
void Vivero::RealizarVenta(int IndiceCliente, int IndicePlanta) {
    // Validación de índices...
    if (IndiceCliente >= 0 && IndiceCliente < ContadorClientes && 
        IndicePlanta >= 0 && IndicePlanta < ContadorPlantas) {
        
        Cliente ElCliente = ListaClientes[IndiceCliente];
        Planta LaPlanta = InventarioPlantas[IndicePlanta];

        cout << "\nIntento de venta: " << ElCliente.GetNombre() << 
            " quiere " << LaPlanta.GetNombre() << endl;

        if (LaPlanta.GetStock() > 0) {
            if (ElCliente.Comprar(LaPlanta.GetPrecio())) {
                LaPlanta.ActualizarStock(-1); 
                cout << ">> Venta Exitosa!" << endl;

                // Guardar los objetos modificados
                ListaClientes[IndiceCliente] = ElCliente;
                InventarioPlantas[IndicePlanta] = LaPlanta;
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

/**
 * Realiza la venta de una Maceta. Elimina la maceta del inventario.
 *
 * @param int IndiceCliente: Índice del cliente.
 * @param int IndiceMaceta: Índice de la maceta.
 * @return void
 */
void Vivero::RealizarVentaMaceta(int IndiceCliente, int IndiceMaceta) {
    // Validación de índices...
    if (IndiceCliente >= 0 && IndiceCliente < ContadorClientes && 
        IndiceMaceta >= 0 && IndiceMaceta < ContadorMacetas) {
        
        Cliente ElCliente = ListaClientes[IndiceCliente];
        Maceta LaMaceta = InventarioMacetas[IndiceMaceta];

        cout << "\nIntento de venta: " << ElCliente.GetNombre() << 
            " quiere " << LaMaceta.GetNombre() << endl;

        if (ElCliente.Comprar(LaMaceta.GetPrecio())) {
            cout << ">> Venta Exitosa! Maceta eliminada del inventario." << endl;
            
            ListaClientes[IndiceCliente] = ElCliente;
            
            // Eliminar Maceta (Desplazamiento de elementos)
            for (int I = IndiceMaceta; I < ContadorMacetas - 1; I++) {
                InventarioMacetas[I] = InventarioMacetas[I + 1];
            }
            ContadorMacetas--;
        } else {
            cout << ">> Saldo insuficiente." << endl;
        }
    } else {
        cout << ">> Error: Indices no validos." << endl;
    }
}

#endif // VIVERO_H_
