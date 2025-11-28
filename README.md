# TC1033 Proyecto Vivero

Este proyecto fue desarrollado para la materia de **Pensamiento Orientado a Objetos (TC1033)**.

---

## Contexto

El proyecto simula el sistema de gestión de un pequeño **Vivero** . El sistema debe ser capaz de administrar su inventario de productos (plantas y macetas) y la lista de clientes, permitiendo la simulación de transacciones de venta.

Para organizar la información, se utilizó una estructura de clases que sigue estos principios:

* **Herencia:** Las clases `Planta` y `Maceta` heredan las propiedades básicas de la clase padre `Producto` (nombre y precio).
* **Composición:** La clase `Vivero` **contiene** los arreglos fijos de objetos `Planta`, `Maceta` y `Cliente`.

---

## Funcionalidad

El programa corre sobre consola y ofrece las siguientes capacidades principales:

* **Alta de Productos y Clientes:** Permite inicializar y agregar nuevos objetos (`Planta`, `Maceta`, `Cliente`) al sistema del `Vivero`.
* **Reporte de Inventario:** Muestra el estado actual del stock de plantas y el saldo disponible de los clientes.
* **Simulación de Venta:** Realiza una transacción verificando el **stock disponible** de la planta y el **presupuesto** del cliente. Si la venta es exitosa, actualiza el stock y el saldo del cliente.

**Nota:** La capacidad máxima de todos los arreglos internos (Inventario y Clientes) está limitada a **50 elementos**.

---

## Consideraciones

El proyecto está diseñado para compilarse uniendo todos los archivos de encabezado:

```bash
g++ main.cpp -o gestor_vivero
