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
    // Atributos protegidos
    string NombreProducto;
    double PrecioProducto;

public:
    // --- Declaraciones de Constructores ---
    Producto();
    Producto(string NombreIn, double PrecioIn);

    // --- Declaraciones de Métodos ---
    string GetNombre() const;
    double GetPrecio() const;
    void SetPrecio(double NuevoPrecio);
};

/*
 * Clase Planta: Clase hija de Producto.
 */
class Planta : public Producto {
private:
    int StockDisponible; // PascalCase

public:
    // --- Declaraciones de Constructores ---
    Planta();
    Planta(string NombreIn, double PrecioIn, int StockIn);

    // --- Declaraciones de Métodos ---
    int GetStock() const;
    void ActualizarStock(int Cantidad);
    void Mostrar();
};

/*
 * Clase Maceta: Clase hija de Producto.
 */
class Maceta : public Producto {
private:
    string MaterialMaceta; // PascalCase
    string ColorMaceta;    // PascalCase
    bool EsColgante;       // PascalCase

public:
    // --- Declaraciones de Constructores ---
    Maceta();
    Maceta(string NombreIn, string MaterialIn, string ColorIn, 
           double PrecioIn, bool ColganteIn);

    // --- Declaraciones de Métodos ---
    void Mostrar();
};

// ============================================================================
// IMPLEMENTACIÓN DE LA CLASE PRODUCTO
// ============================================================================

/**
 * Constructor por defecto de la clase Producto.
 * Inicializa nombre y precio a valores por defecto.
 *
 * @param Ninguno
 * @return Objeto Producto inicializado
 */
Producto::Producto() {
    NombreProducto = "Sin Nombre";
    PrecioProducto = 0.0;
}

/**
 * Constructor con parámetros de la clase Producto.
 *
 * @param string NombreIn: Nombre del producto.
 * @param double PrecioIn: Precio del producto.
 * @return Objeto Producto inicializado
 */
Producto::Producto(string NombreIn, double PrecioIn) {
    NombreProducto = NombreIn;
    PrecioProducto = PrecioIn;
}

/**
 * Método getter para obtener el nombre del producto.
 *
 * @param Ninguno
 * @return string: El nombre almacenado del producto.
 */
string Producto::GetNombre() const {
    return NombreProducto;
}

/**
 * Método getter para obtener el precio del producto.
 *
 * @param Ninguno
 * @return double: El precio almacenado del producto.
 */
double Producto::GetPrecio() const {
    return PrecioProducto;
}

/**
 * Método setter para actualizar el precio del producto.
 * Valida que el precio no sea negativo.
 *
 * @param double NuevoPrecio: El nuevo valor a asignar.
 * @return void
 */
void Producto::SetPrecio(double NuevoPrecio) {
    if (NuevoPrecio >= 0) {
        PrecioProducto = NuevoPrecio;
    }
}

// ============================================================================
// IMPLEMENTACIÓN DE LA CLASE PLANTA
// ============================================================================

/**
 * Constructor por defecto de Planta.
 * Llama al constructor base de Producto.
 *
 * @param Ninguno
 * @return Objeto Planta inicializado con stock 0
 */
Planta::Planta() : Producto() {
    StockDisponible = 0;
}

/**
 * Constructor con parámetros de Planta.
 *
 * @param string NombreIn: Nombre de la planta.
 * @param double PrecioIn: Precio de la planta.
 * @param int StockIn: Cantidad inicial en inventario.
 * @return Objeto Planta inicializado
 */
Planta::Planta(string NombreIn, double PrecioIn, int StockIn) 
    : Producto(NombreIn, PrecioIn) {
    StockDisponible = StockIn;
}

/**
 * Método getter para obtener el stock disponible.
 *
 * @param Ninguno
 * @return int: Cantidad de plantas en stock.
 */
int Planta::GetStock() const { 
    return StockDisponible; 
}

/**
 * Método para actualizar la cantidad de stock disponible.
 * Permite sumar (entrada) o restar (venta) stock.
 *
 * @param int Cantidad: Valor a sumar o restar.
 * @return void
 */
void Planta::ActualizarStock(int Cantidad) {
    if (StockDisponible + Cantidad >= 0) {
        StockDisponible = StockDisponible + Cantidad;
    } else {
        cout << "ERROR: No hay suficiente stock." << endl;
    }
}

/**
 * Muestra en consola los detalles de la Planta.
 *
 * @param Ninguno
 * @return void
 */
void Planta::Mostrar() {
    cout << "Planta: " << NombreProducto << " | Precio: $" << 
        PrecioProducto << " | Stock: " << StockDisponible << endl;
}

// ============================================================================
// IMPLEMENTACIÓN DE LA CLASE MACETA
// ============================================================================

/**
 * Constructor por defecto de Maceta.
 * Llama al constructor base de Producto.
 *
 * @param Ninguno
 * @return Objeto Maceta inicializado con valores N/A
 */
Maceta::Maceta() : Producto() {
    MaterialMaceta = "N/A";
    ColorMaceta = "N/A";
    EsColgante = false;
}

/**
 * Constructor con parámetros de Maceta.
 *
 * @param string NombreIn: Nombre de la maceta.
 * @param string MaterialIn: Material de fabricación.
 * @param string ColorIn: Color de la maceta.
 * @param double PrecioIn: Precio de venta.
 * @param bool ColganteIn: True si es colgante, False si es de piso.
 * @return Objeto Maceta inicializado
 */
Maceta::Maceta(string NombreIn, string MaterialIn, string ColorIn, 
               double PrecioIn, bool ColganteIn) 
    : Producto(NombreIn, PrecioIn) {
    MaterialMaceta = MaterialIn;
    ColorMaceta = ColorIn;
    EsColgante = ColganteIn;
}

/**
 * Muestra en consola los detalles de la Maceta.
 *
 * @param Ninguno
 * @return void
 */
void Maceta::Mostrar() {
    string Tipo = EsColgante ? "Si" : "No";
    cout << "Maceta: " << NombreProducto << " | Mat: " << MaterialMaceta << 
        " | Colgante: " << Tipo << " | Precio: $" << PrecioProducto << endl;
}

#endif // PRODUCTOS_H_
