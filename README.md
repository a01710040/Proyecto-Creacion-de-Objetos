# PROYECTO: Gestor Básico de Vivero

Este proyecto es un sistema básico de **modelado de productos y clientes** para un vivero, usando Programación Orientada a Objetos en C++.

---

## Contexto

El programa simula digitalmente los elementos esenciales de un vivero para futuras operaciones de gestión. Los elementos modelados son:

1.  **Plantas:** Los artículos principales que se venden.
2.  **Macetas:** Los contenedores donde se venden las plantas.
3.  **Clientes:** Las personas que compran.

El diseño se enfoca en tener clases aisladas y funcionales, pero muy simples, para facilitar los cambios en los siguientes avances.

---

## Funcionalidad

El programa solo permite crear y manipular las instancias de las clases en la función principal (`main`). No hay interacción con el usuario (sin menú en consola).

El programa demuestra:
* **Crear** objetos de tipo `Planta`, `Maceta` y `Cliente`.
* **Comprobar** el estado inicial de los objetos al llamar a sus métodos de información (`mostrar()`).
* **Modificar** los atributos encapsulados (privados) usando los *setters*.
* **Recuperar** los atributos usando los *getters* y mostrar la información actualizada.

---

## Consideraciones

* **Compilar con:** `g++ main.cpp -o vivero`
* **Correr en Linux/Mac:** `./vivero`
* **Correr en Windows:** `vivero.exe`

---

## Clases del Proyecto

| Clase | Atributos Principales | Métodos Clave |
| :--- | :--- | :--- |
| **Planta** | nombre, precio | constructor, getters, setters (`setPrecio`), mostrar() |
| **Maceta** | material, color | constructor, getters, setters (`setColor`), mostrar() |
| **Cliente** | nombre | constructor, getters, setters (`setNombre`), saludar() |
