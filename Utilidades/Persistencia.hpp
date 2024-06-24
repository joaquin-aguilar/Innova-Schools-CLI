#ifndef PERSISTENCIA_HPP
#define PERSISTENCIA_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <curses.h>

bool guardarVectorEnArchivo(const std::vector<std::string>& datos) 
{
    auto ahora = std::chrono::system_clock::now();
    std::time_t tiempo_actual = std::chrono::system_clock::to_time_t(ahora);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&tiempo_actual), "%Y%m%d_%H%M%S");
    std::string fecha_hora_str = ss.str();

    std::string nombre_archivo = "datos_" + fecha_hora_str + ".txt";

    std::ofstream archivo(nombre_archivo);


    if (!archivo.is_open()) 
    {
        printw("Error: no se pudo abrir el archivo: %s", nombre_archivo.c_str());
        return false;
    }

    // Escribir cada línea del vector en el archivo
    for (const auto& linea : datos)
    {
        archivo << linea << std::endl;
    }

    // Cerrar el archivo
    archivo.close();

    printw("Se ha guardado La sesion en el archivo: %s", nombre_archivo.c_str());

    return true;
}

#endif // !PERSISTENCIA_HPP