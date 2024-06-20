#ifndef DOCENTES_HPP
#define DOCENTES_HPP

#include <iostream>
#include <string>
#include <functional>
#include "./Datasets/Nombres.hpp"
#include "./Datasets/Materias.hpp"
using namespace std; 
using namespace Datasets;


class Docentes {
	string nombre, curso; int edad, calificacion;
public:

    //Big O #4
	Docentes() {
        auto rng = [](int a, int b) {return a + rand() % b; };
        auto verd = [](int n) {return rand() % n; };
        this->nombre += nombresArr[rng(0, NOMBRES_LEN)];
        this->nombre += apellidosArr[rng(0,NOMBRES_LEN)];
        this->edad = rng(30, 75);
        this->calificacion = rng(3,20); 
	}

    std::string mostrar() 
    {
        std::string str;
        str += "Nombre del docente: ";
        str += nombre;
        str += ", Curso: ";
        str += curso;
        str += ", Edad: ";
        str += to_string(edad);
        return str;
    }
};

#endif // !DOCENTES_HPP