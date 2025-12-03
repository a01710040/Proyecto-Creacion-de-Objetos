#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_

#include <iostream>
#include <string>

using namespace std;

/*
 * Clase Producto: Clase base que contiene los atributos genéricos 
 * de todo artículo vendible en el vivero. 
 * Las clases Planta y Maceta heredan de esta clase.
 */
class Producto {
protected:
    // Atributos protegidos para permitir el acceso a las clases hijas
    string nombre_producto;
    double precio_producto;

public:
    // Constructores
    Producto();
    Producto(string nombre_in, double precio_in);

    // Getters
    string getNombre() const;
    double getPrecio() const;

    // Setter (método mutador)
    void setPrecio(double nuevo_precio);
};

/**
 * Constructor por defecto de la clase Producto.
 * Inicializa nombre y precio a valores por defecto.
 *
 * @param Ninguno
 * @return Objeto Producto inicializado
 */
Producto::Producto() {
    nombre_producto = "Sin Nombre";
    precio_producto = 0.0;
}

/**
 * Constructor con parámetros de la clase Producto.
 *
 * @param string nombre_in: Nombre del producto.
 * @param double precio_in: Precio del producto.
 * @return Objeto Producto inicializado
 */
Producto::Producto(string nombre_in, double precio_in) {
    nombre_producto = nombre_in;
    precio_producto = precio_in;
}

// Implementación del getter para obtener el nombre
string Producto::getNombre() const {
    return nombre_producto;
}

// Implementación del getter para obtener el precio
double Producto::getPrecio() const {
    return precio_producto;
}

/**
 * Setter para actualizar el precio del producto.
 *
 * @param double nuevo_precio: El nuevo precio a asignar.
 * @return void
 */
void Producto::setPrecio(double nuevo_precio) {
    if (nuevo_precio >= 0) {
        precio_producto = nuevo_precio;
    }
}


/*
 * Clase Planta: Clase hija de Producto.
 * Contiene el atributo 'stock' específico para plantas.
 */
class Planta : public Producto {
private:
    int stock_disponible;

public:
    // Constructores
    Planta() : Producto() {
        stock_disponible = 0;
    }

    Planta(string nombre_in, double precio_in, int stock_in) : 
        Producto(nombre_in, precio_in) {
        stock_disponible = stock_in;
    }

    // Getters y Métodos de gestión
    int getStock() const { return stock_disponible; }
    void actualizarStock(int cantidad);
    void mostrar();
};

/**
 * Método para actualizar la cantidad de stock disponible.
 *
 * @param int cantidad: Cantidad a añadir (positivo) o restar (negativo).
 * @return void
 */
void Planta::actualizarStock(int cantidad) {
    if (stock_disponible + cantidad >= 0) {
        stock_disponible = stock_disponible + cantidad;
    } else {
        cout << "ERROR: No hay suficiente stock." << endl;
    }
}

// Método para mostrar la información completa de la planta
void Planta::mostrar() {
    cout << "Planta: " << nombre_producto << " | Precio: $" << 
        precio_producto << " | Stock: " << stock_disponible << endl;
}


/*
 * Clase Maceta: Clase hija de Producto.
 * Contiene atributos específicos como material y si es colgante.
 */
class Maceta : public Producto {
private:
    string material_maceta;
    string color_maceta;
    bool es_colgante;

public:
    // Constructores
    Maceta() : Producto() {
        material_maceta = "N/A";
        color_maceta = "N/A";
        es_colgante = false;
    }

    Maceta(string nombre_in, string material_in, string color_in, 
           double precio_in, bool colgante_in) 
    : Producto(nombre_in, precio_in) {
        material_maceta = material_in;
        color_maceta = color_in;
        es_colgante = colgante_in;
    }

    // Método para mostrar la información completa de la maceta
    void mostrar() {
        cout << "Maceta: " << nombre_producto << " (" << material_maceta << 
            ") | Precio: $" << precio_producto << endl;
    }
};

#endif // PRODUCTOS_H_
