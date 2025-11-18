#include <string>
#include <iostream>
using namespace std;

class Cliente {
private:
    string nombre;

public:
    // Declaraciones
    Cliente(string p_nombre);
    string getNombre();
    void setNombre(string nuevoNombre);
    void saludar();
};

// --- Desarrollo de la Función ---

Cliente::Cliente(string p_nombre) {
    nombre = p_nombre;
}

string Cliente::getNombre() {
    return nombre;
}

void Cliente::setNombre(string nuevoNombre) {
    nombre = nuevoNombre;
}

void Cliente::saludar() {
    cout << "Hola, me llamo " << nombre << "." << endl;
}
