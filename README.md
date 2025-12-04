# TC1033 Proyecto Vivero

Este proyecto fue desarrollado para la materia de **Pensamiento Orientado a Objetos (TC1033)**.

---

## Descripción del Proyecto

El proyecto simula el sistema de gestión de un pequeño **Vivero** . El sistema debe ser capaz de administrar su inventario de productos (plantas y macetas) y la lista de clientes, permitiendo la simulación de transacciones de venta.

Para organizar la información, se utilizó una estructura de clases que sigue estos principios:

* **Herencia:** Las clases `Planta` y `Maceta` heredan las propiedades básicas de la clase padre `Producto` (nombre y precio).
* **Composición:** La clase `Vivero` **contiene** los arreglos fijos de objetos `Planta`, `Maceta` y `Cliente`.

---

## Funcionalidad y Alcance del Sistema

### ¿Para qué sirve?

El programa corre sobre consola y ofrece las siguientes capacidades principales:

* **Administrar Inventario:** Permite dar de alta y listar el stock de **Plantas** y **Macetas** (objetos distintos con atributos únicos).
* **Gestionar Clientes:** Permite registrar clientes y llevar un control básico de su presupuesto disponible.
* **Simular Transacciones:** Realiza la simulación de ventas, verificando el **Stock Disponible** y el **Presupuesto del Cliente** antes de completar la operación y actualizar los saldos e inventario.

---

### ¿Para qué no sirve?

 El programa tiene algunas limitaciones:
* **No Maneja Persistencia:** Los datos ingresados se pierden al cerrar la aplicación (no guarda en archivos ni bases de datos).
* **Sin Interfaz Gráfica (GUI):** Toda la interacción es a través de la **consola de comandos**.
* **Capacidad Limitada:** El tamaño de todos los inventarios y listas está limitado a **50 elementos**.

---

## Guía de Uso Rápido

### ¿Cómo se usa?

Una vez compilado y ejecutado, el programa presenta un menú interactivo.

* **Registrar Entidades (Opciones 1, 2, 3):** Comienza registrando al menos un cliente y algunas plantas o macetas para llenar el inventario.
* **Reporte (Opción 4):** Utiliza esta opción para ver los **índices numéricos** asignados a cada cliente y producto. Necesitarás estos índices para realizar una venta.
* **Venta (Opciones 5, 6):** Ingresa el **índice del cliente** que compra y el **índice del producto** que desea comprar. El sistema verificará el saldo y el stock automáticamente.
* **Salir (Opción 0):** Cierra el programa.

---

### Casos en los que no funciona:

* **Inventario Lleno:** Se intenta agregar más de 50 Plantas, Macetas o Clientes.
* **Venta sin Stock:** Se intenta comprar una Planta cuyo `StockDisponible` es 0.
* **Venta sin Fondos:** El `PresupuestoCliente` es insuficiente para cubrir el `PrecioProducto`.
* **Índice Inválido:** El usuario ingresa un número de índice que no corresponde a un Cliente o Producto existente en la lista.
* **Entrada de Datos:** Si se introduce texto donde se espera un número, la entrada fallará, reiniciando el menú.

---

## Consideraciones

El proyecto está diseñado para compilarse uniendo todos los archivos de encabezado:

```bash
g++ main.cpp -o gestor_vivero
