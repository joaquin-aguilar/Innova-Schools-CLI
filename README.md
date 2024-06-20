# Innova-Schools-CLI
Simulador de Administración de un colegio para demostrar la aplicación de estructuras de datos.

Este proyecto fue desarrollado y compilado en Linux, se utiliza el compilador g++ tambien compatible con Windows.
Se utiliza la Libreria ncurses basada en curses, en Windows pude emplearse pdcurses.


### Instrucciones para compilar y ejecutar el proyecto


1. **Instalacion de dependencias**

    En Fedora:

        $ dnf install ncurses-devel

    En Ubuntu:

        $ sudo apt-get install ncurses-dev

2. **Compilar el proyecto usando g++:**

    Compilar:

        $ g++ src.cpp -o innova.out -lncurses

    Compilar y revisar fugas de memoria Usando AddressSanitizer - ASan. Solo compatible en sistemas Linux/Unix:

        $ g++ --sanitize=address -g src.cpp -o innova.out -lncurses


3. **Ejecutar el binario del proyecto:**

        $ ./innova.out