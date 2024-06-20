# Innova-Schools-CLI
Simulador de Administración de un colegio para demostrar la aplicación de estructuras de datos.

Este proyecto fue desarrollado y compilado en Linux, se utiliza el compilador g++ tambien compatible con Windows.
Se utiliza la Libreria ncurses basada en curses, en Windows pude emplearse pdcurses.


### Instrucciones para compilar y ejecutar el proyecto


1. **Instalacion de dependencias**

    ## Linux
    En Fedora:

        $ dnf install ncurses-devel

    En Ubuntu:

        $ sudo apt-get install ncurses-dev
    ## Windows

    Revisar la documentacion en [la pagina oficial de pdcurses](https://pdcurses.org/).

2. **Compilar el proyecto usando g++:**

    ## Linux:

    Compilar:
        $ g++ src.cpp -o innova.out -lncurses

    Compilar y revisar fugas de memoria Usando AddressSanitizer - ASan. Solo compatible en sistemas Linux/Unix:

        $ g++ --sanitize=address -g src.cpp -o innova.out -lncurses
    
    ## Windows

    Compilar:

        $ g++ src.cpp -o innova.exe -lpdcurses

3. **Ejecutar el binario del proyecto:**

    ## Linux

        $ ./innova.out
    ## Windows

        $ innova.exe