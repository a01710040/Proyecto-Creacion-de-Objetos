#include <string>
#include <iostream>

class Planta {
private:
    string nombre;  // Usando 'string' directamente
    double precio;

public:
    // Declaraciones
    Planta(string p_nombre, double p_precio);
    string getNombre();
    double getPrecio();
    void setPrecio(double nuevoPrecio);
    void mostrar();
};

// --- Desarrollo de la Función (Definición) ---

Planta::Planta(string p_nombre, double p_precio) {
    nombre = p_nombre;
    precio = p_precio;
}

string Planta::getNombre() {
    return nombre;
}

double Planta::getPrecio() {
    return precio;
}

void Planta::setPrecio(double nuevoPrecio) {
    precio = nuevoPrecio;
}

void Planta::mostrar() {
    cout << "Soy la planta " << nombre << " y cuesto $" << precio << endl;
}
