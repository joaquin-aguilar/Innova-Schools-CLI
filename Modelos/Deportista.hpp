#ifndef DEPORTISTA_HPP
#define DEPORTISTA_HPP


#include <string>
#include <functional>
#include "../Datasets/Deportes.hpp"
#include "../Datasets/Nombres.hpp"
using namespace std; 
using namespace Datasets;


class Deportista 
{
	string nombre; 
	int grado; 
	bool genero; 
	string deporte;
public:
	Deportista()
	{
		nombre += nombresArr[rand() % NOMBRES_LEN];
		nombre += " ";
		nombre += nombresArr[rand() % NOMBRES_LEN];
		nombre += " ";
		nombre += apellidosArr[rand() % APELLIDOS_LEN];
		nombre += " ";
		nombre += apellidosArr[rand() % APELLIDOS_LEN];
		grado = 1 + rand() % 11;
		genero = rand() % 2;
		deporte = deportesArr[rand() % DEPORTES_LEN];
	}
	Deportista(string _name, int _grade, bool gender) 
	{
		auto rng = [](int a, int b) {return a + rand() % b; };
		this->nombre += _name;
        this->grado = _grade;
        this->deporte = deportesArr[rng(0, DEPORTES_LEN)];
		this->genero = gender;
	}

	std::string mostrar() 
	{
		std::string str;
		str += "Nombre: ";
		str += nombre;
		str += ", Grado: ";
		str += to_string(grado);
		str += ", Genero: ";
		str += (genero ? "Hombre" : "Mujer");
        str += " ,Deporte: ";
		str += deporte;
		str += "\n";
		return str;
	}
};

#endif //!DEPORTISTAS_HPP