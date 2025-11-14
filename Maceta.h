#include <string>
#include <iostream>

class Maceta {
private:
    string material;
    string color;

public:
    // Declaraciones
    Maceta(string p_material, string p_color);
    string getMaterial();
    string getColor();
    void setColor(string nuevoColor);
    void mostrar();
};

// --- Desarrollo de la Función (Definición) ---

Maceta::Maceta(string p_material, string p_color) {
    material = p_material;
    color = p_color;
}

string Maceta::getMaterial() {
    return material;
}

string Maceta::getColor() {
    return color;
}

void Maceta::setColor(string nuevoColor) {
    color = nuevoColor;
}

void Maceta::mostrar() {
    cout << "Soy una maceta de " << material << " de color " << color << endl;
}
