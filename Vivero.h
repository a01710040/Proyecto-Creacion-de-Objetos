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
 * Implementa las relaciones de Composición y Agregación.
 * Contiene el inventario de Plantas, Macetas y la lista de Clientes.
 */
class Vivero {
private:
    // Atributos que representan las colecciones (Composición/Agregación)
    Planta inventario_plantas[MAX_INVENTARIO];
    Maceta inventario_macetas[MAX_INVENTARIO];
    Cliente lista_clientes[MAX_INVENTARIO];

    // Contadores para llevar el registro del inventario
    int contador_plantas;
    int contador_macetas;
    int contador_clientes;

public:
    // Constructores (Sobrecargados)
    Vivero(); // Constructor por defecto
    Vivero(int cont_p, int cont_m, int cont_c); // Constructor con parámetros
    
    // Métodos de Composición (Crean objetos internos)
    void crearPlanta(string nombre, double precio, int stock);
    void crearMaceta(string nombre, string material, string color, 
                     double precio, bool esColgante);

    // Método de Agregación (Recibe objeto creado externamente)
    void registrarCliente(Cliente c);

    // Métodos de Gestión
    void mostrarInventario();
    void realizarVenta(int indice_cliente, int indice_planta);
    void realizarVentaMaceta(int indice_cliente, int indice_maceta);
};


/**
 * Constructor por Defecto: Inicializa el Vivero vacío.
 *
 * @param Ninguno
 * @return Objeto Vivero
 */
Vivero::Vivero() {
    cout << ">> Vivero creado (Vacio)." << endl;
    contador_plantas = 0;
    contador_macetas = 0;
    contador_clientes = 0;
}

/**
 * Constructor con Parámetros: Inicializa los contadores a valores 
 * específicos.
 *
 * @param int cont_p: Contador inicial de plantas.
 * @param int cont_m: Contador inicial de macetas.
 * @param int cont_c: Contador inicial de clientes.
 * @return Objeto Vivero
 */
Vivero::Vivero(int cont_p, int cont_m, int cont_c) {
    cout << ">> Vivero creado con contadores iniciales." << endl;
    contador_plantas = cont_p;
    contador_macetas = cont_m;
    contador_clientes = cont_c;
}

// Composición: Creación de Planta
void Vivero::crearPlanta(string nombre, double precio, int stock) {
    if (contador_plantas < MAX_INVENTARIO) {
        inventario_plantas[contador_plantas] = 
            Planta(nombre, precio, stock);
        contador_plantas++;
        cout << ">> Planta creada y agregada exitosamente." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

// Composición: Creación de Maceta
void Vivero::crearMaceta(string nombre, string material, string color, 
                         double precio, bool esColgante) {
    if (contador_macetas < MAX_INVENTARIO) {
        inventario_macetas[contador_macetas] = 
            Maceta(nombre, material, color, precio, esColgante);
        contador_macetas++;
        cout << ">> Maceta creada y agregada exitosamente." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

// Agregación: Registro de Cliente
void Vivero::registrarCliente(Cliente c) {
    if (contador_clientes < MAX_INVENTARIO) {
        lista_clientes[contador_clientes] = c;
        contador_clientes++;
        cout << ">> Cliente registrado exitosamente." << endl;
    } else {
        cout << "Error: Lista de clientes llena." << endl;
    }
}

// Método para mostrar todo el inventario y la lista de clientes
void Vivero::mostrarInventario() {
    cout << "\n===== REPORTE VIVERO =====" << endl;
    
    cout << "--- Plantas (" << contador_plantas << ") ---" << endl;
    for (int i = 0; i < contador_plantas; i++) {
        cout << i << ". "; 
        inventario_plantas[i].mostrar();
    }

    cout << "--- Macetas (" << contador_macetas << ") ---" << endl;
    for (int i = 0; i < contador_macetas; i++) {
        cout << i << ". ";
        inventario_macetas[i].mostrar();
    }

    cout << "--- Clientes (" << contador_clientes << ") ---" << endl;
    for (int i = 0; i < contador_clientes; i++) {
        cout << i << ". ";
        lista_clientes[i].mostrar();
    }
    cout << "==========================" << endl;
}

/**
 * Realiza la venta de una Planta y actualiza el stock/saldo.
 *
 * @param int indice_cliente: Índice del cliente en la lista.
 * @param int indice_planta: Índice de la planta en el inventario.
 * @return void
 */
void Vivero::realizarVenta(int indice_cliente, int indice_planta) {
    // Validación de índices...
    if (indice_cliente >= 0 && indice_cliente < contador_clientes && 
        indice_planta >= 0 && indice_planta < contador_plantas) {
        
        Cliente el_cliente = lista_clientes[indice_cliente];
        Planta la_planta = inventario_plantas[indice_planta];

        cout << "\nIntento de venta: " << el_cliente.getNombre() << 
            " quiere " << la_planta.getNombre() << endl;

        if (la_planta.getStock() > 0) {
            if (el_cliente.comprar(la_planta.getPrecio())) {
                la_planta.actualizarStock(-1); // Disminuye el stock
                cout << ">> Venta Exitosa!" << endl;

                // Guardar los objetos modificados
                lista_clientes[indice_cliente] = el_cliente;
                inventario_plantas[indice_planta] = la_planta;
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
 * @param int indice_cliente: Índice del cliente en la lista.
 * @param int indice_maceta: Índice de la maceta en el inventario.
 * @return void
 */
void Vivero::realizarVentaMaceta(int indice_cliente, int indice_maceta) {
    // Validación de índices...
    if (indice_cliente >= 0 && indice_cliente < contador_clientes && 
        indice_maceta >= 0 && indice_maceta < contador_macetas) {
        
        Cliente el_cliente = lista_clientes[indice_cliente];
        Maceta la_maceta = inventario_macetas[indice_maceta];

        cout << "\nIntento de venta: " << el_cliente.getNombre() << 
            " quiere " << la_maceta.getNombre() << endl;

        if (el_cliente.comprar(la_maceta.getPrecio())) {
            cout << ">> Venta Exitosa! Maceta eliminada de inventario" << endl;
            
            lista_clientes[indice_cliente] = el_cliente;
            
            // Eliminar Maceta (Desplazamiento de elementos)
            for (int i = indice_maceta; i < contador_macetas - 1; i++) {
                inventario_macetas[i] = inventario_macetas[i + 1];
            }
            contador_macetas--;
        } else {
            cout << ">> Saldo insuficiente." << endl;
        }
    } else {
        cout << ">> Error: Indices no validos." << endl;
    }
}

#endif // VIVERO_H_
