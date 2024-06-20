### Instrucciones para compilar y ejecutar el proyecto

1. **Compilar el proyecto usando g++:**

        $ g++ src.cpp -o innova.out -lncurses


2. **Compilar y revisar fugas de memoria Usando AddressSanitizer - ASan. Solo compatible en sistemas Linux/Unix:**

        $ g++ --sanitize=address -g src.cpp -o innova.out -lncurses


3. **Ejecutar el binario del proyecto:**

        $ ./innova.out