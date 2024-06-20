#ifndef INTELIGENTE_HPP
#define INTELIGENTE_HPP

#include <functional>
#include <string>
#include "../Utilidades/Materias.hpp"
#include "../Utilidades/Nombres.hpp"

using namespace Lib;

class Destacado
{
private:
    std::string nombre, materia; 
    int grado; 
    bool genero;
public:
    Destacado()
    {
        nombre += nombresArr[rand() % NOMBRES_LEN];
		nombre += " ";
		nombre += nombresArr[rand() % NOMBRES_LEN];
		nombre += " ";
		nombre += apellidosArr[rand() % APELLIDOS_LEN];
		nombre += " ";
		nombre += apellidosArr[rand() % APELLIDOS_LEN];
        materia = materiasArr[rand() % MATERIAS_LEN];
		grado = 1 + rand() % 11;
		genero = rand() % 2;
    }
    Destacado(std::string name, int grade, bool gender)
    {
        auto rng = [](int a, int b) {return a + rand() % b; };
        this->nombre = name;
        this->grado = grade;
        this->genero = gender;
        this->materia = materiasArr[rng(0,MATERIAS_LEN)];
    }

    std::string mostrar() 
    {
        std::string str;
		str += "Nombre: " ;
        str += nombre;
		str += ", Grado: " ;
        str+= to_string(grado);
		str += ", Genero: ";
        str+= (genero ? "Hombre" : "Mujer");
        str += ", Materia: " ;
        str+= materia;
        str += "\n";
        return str;
	}
};

#endif // !INTELIGENTE_HPP