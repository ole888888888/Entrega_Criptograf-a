# Práctica de Criptografía con Precisión Arbitraria (GMP)

**Asignatura:** Álgebra Lineal y Estructuras Matemáticas  
**Institución:** Universidad de Granada (UGR)  

Este repositorio contiene la implementación en C++ de algoritmos criptográficos haciendo uso de la librería **GMP** (*GNU Multiple Precision Arithmetic Library*), la cual permite trabajar con enteros de tamaño arbitrario evitando los límites de precisión de los tipos primitivos del lenguaje.

---

## Estructura del Proyecto

El repositorio consta de los siguientes archivos principales:

* **`def.cpp`**: Contiene la lógica necesaria para cifrar y descifrar **mensajes de texto codificados en ASCII**, convirtiendo el flujo de texto a formato numérico compatible con la precisión de GMP.
* **`num.cpp`**: Implementa el cifrado y descifrado orientado únicamente al procesamiento de **enteros de precisión arbitraria**.

---

## Requisitos e Instalación

Para compilar y ejecutar los programas es necesario contar con un compilador de C++ (como `g++`) y tener instalada la librería **GMP**.

### Descarga e Instalación de GMP

* **Página oficial:** [gmplib.org](https://gmplib.org/)
* **Instalación en entornos basados en Linux (Ubuntu/Debian):**
  ```bash
  sudo apt-get update
  sudo apt-get install libgmp-dev libgmpxx-dev
