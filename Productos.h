#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <iostream>
#include <string>

using namespace std;

// === CLASE PADRE: PRODUCTO ===
class Producto {
protected:
    string nombre;
    double precio;

public:
    Producto() {
        nombre = "Sin Nombre";
        precio = 0.0;
    }

    Producto(string p_nombre, double p_precio) {
        nombre = p_nombre;
        precio = p_precio;
    }

    string getNombre() { return nombre; }
    double getPrecio() { return precio; }
};

// === CLASE HIJA: PLANTA ===
class Planta : public Producto {
private:
    int stock;

public:
    Planta() : Producto() {
        stock = 0;
    }

    Planta(string p_nombre, double p_precio, int p_stock) : Producto(p_nombre, p_precio) {
        stock = p_stock;
    }

    int getStock() { return stock; }
    
    void actualizarStock(int cantidad) {
        if (stock + cantidad >= 0) {
            stock = stock + cantidad;
        } else {
            cout << "No hay suficiente stock." << endl;
        }
    }

    void mostrar() {
        cout << "Planta: " << nombre << " | Precio: $" << precio << " | Stock: " << stock << endl;
    }
};

// === CLASE HIJA: MACETA ===
class Maceta : public Producto {
private:
    string material;
    string color;
    bool esColgante;

public:
    Maceta() : Producto() {
        material = "N/A";
        color = "N/A";
        esColgante = false;
    }

    Maceta(string p_nombre, string p_material, string p_color, double p_precio, bool p_colgante) : Producto(p_nombre, p_precio) {
        material = p_material;
        color = p_color;
        esColgante = p_colgante;
    }

    void mostrar() {
        cout << "Maceta: " << nombre << " (" << material << ") | Precio: $" << precio << endl;
    }
};

#endif
