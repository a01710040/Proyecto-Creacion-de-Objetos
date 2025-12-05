# TC1033 Proyecto: Sistema de Gestión de Vivero

Este proyecto implementa un sistema básico de gestión de inventario y clientes para un vivero utilizando C++, desarrollado para la materia de **Pensamiento Orientado a Objetos (TC1033)**.

***

## 1. Contexto y Diseño POO

El sistema tiene como objetivo principal administrar el inventario de productos (Plantas y Macetas) y la lista de clientes, permitiendo simular las transacciones de venta de forma controlada.

Para lograr esto, la estructura de clases implementa los siguientes pilares de POO 


* **Herencia:** Las clases **`Planta`** y **`Maceta`** heredan las propiedades básicas (`NombreProducto`, `PrecioProducto`) de la clase base **`Producto`**.
* **Composición / Agregación:** La clase **`Vivero`** actúa como la clase gestora central, **conteniendo** los arreglos fijos de **`Planta`** (Composición) y **`Cliente`** (Agregación) para realizar todas las operaciones de negocio.
* **Encapsulamiento:** Se utilizan atributos privados (`private`) o protegidos (`protected`) y métodos públicos (`Getters`/`Setters`) para controlar el acceso y la modificación de datos.

---

## 2. Estructura y Estándares

### A. Archivos del Proyecto

| Archivo | Contenido Principal |
| :--- | :--- |
| **`Vivero.h`** | Clase Gestora. Implementa Composición y Agregación. |
| **`Productos.h`** | Clases `Producto`, `Planta`, `Maceta`. Implementa Herencia. |
| **`Cliente.h`** | Clase `Cliente`. Objeto agregado por `Vivero`. |
| **`main.cpp`** | Contiene el menú de consola y la lógica de inicialización. |

### B. Convenciones de Estilo

* **Estilo:** Se utiliza **`PascalCase`** para *todos* los elementos del código (Clases, Métodos, Atributos y Variables locales).
* **Legibilidad:** Se aplica una restricción estricta de **máximo 80 caracteres por línea**.
* **Documentación:** Uso de comentarios estilo Javadoc con `@param` y `@return` en las implementaciones.

---

## 3. Funcionalidad y Alcance del Sistema

### ¿Para qué sirve?

* **Administrar Inventario:** Permite dar de alta y listar el stock de **`Planta`** y **`Maceta`**.
* **Gestionar Clientes:** Permite registrar clientes y llevar un control básico de su **`PresupuestoCliente`**.
* **Simular Transacciones:** Realiza la simulación de ventas, verificando el **`StockDisponible`** y el **`PresupuestoCliente`** antes de completar la operación.

### ¿Para qué no sirve?

* **No Maneja Persistencia:** Los datos se **pierden** al cerrar la aplicación.
* **Sin Interfaz Gráfica (GUI):** Toda la interacción es a través de la **consola de comandos**.
* **Capacidad Limitada:** El tamaño de todos los inventarios y listas está limitado a **50 elementos**.

---

## 4. Guía de Uso Rápido 🧭

### ¿Cómo se usa?

Una vez compilado y ejecutado, el programa presenta un menú interactivo.

1.  **Registrar Entidades (Opciones 1, 2, 3):** Comienza registrando Clientes y Productos.
2.  **Reporte (Opción 4):** Utiliza esta opción para ver los **índices numéricos** (posiciones) asignados a cada Cliente y Producto.
3.  **Venta (Opciones 5, 6):** Ingresa el **índice del cliente** que compra y el **índice del producto** que desea comprar para procesar la transacción.
4.  **Salir (Opción 0):** Cierra el programa.

### Casos en los que no funciona

El programa incluye mensajes de error y rechaza la acción si:

* **Inventario Lleno:** Se intenta agregar más de 50 elementos.
* **Venta sin Stock:** Se intenta comprar una Planta cuyo **`StockDisponible`** es 0.
* **Venta sin Fondos:** El **`PresupuestoCliente`** es insuficiente para cubrir el **`PrecioProducto`**.
* **Índice Inválido:** El índice ingresado para una venta no existe en la lista.

---

## 5. Diagrama de clases
 [Diagrama de clases](./diagramadeClases.png)

 ---

## 6. Compilación y Ejecución

Para compilar y ejecutar el programa desde la terminal, siga estos pasos:

1.  **Compilación:** Ejecute el siguiente comando para generar el ejecutable `gestor_vivero`:
    ```bash
    g++ main.cpp -o gestor_vivero
    ```
2.  **Ejecución:** Ejecute el siguiente comando:
    ```bash
    ./gestor_vivero
    ```
---

## 7. Consideraciones

Dentro del código uso `const`, algo que no hemos visto en clase y decidí investigarlo por mi cuenta.

### ¿Para qué se utiliza?

Se utiliza al final de los Getters para así proporcionar una garantía de inmutabilidad. 

### ¿Por qué se usa en este proyecto?

Lo utilizo porque así me puedo asegurar que algunos métodos de acceso como `getNombre()` o `getStock()` no modifiquen el estado interno de los atributos de las clases y así reforzar el encapsulamiento.

---

## 8. Correciones

1.  **Implementa SICT0303A:** Añadí using namespace std; porque no compilaba, se encuentra en los archivos.
2.  **Toma de decisiones SICT0302A:** Hice mi diseño del diagrama de clases más claro para que se comprendiera más el concepto de herencia, se encuentra en el diagrama de clases.
3.  **Implementa SICT0303A:** Agregué un menú interactivo para que el programa fuera más amigable con el usuario, se encuentra en el código.
4.  **Implementa SICT0303A:** Modifiqué mi composición ya que no estaba bien implementada, se encuentra en el código.
5.  **Estándares   SICT0401A:** Agregué comentarios al código para ir explicando que va haciendo y cómo se va comportando el pograma, se encuentra en el código.
