#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <iostream>
#include <functional>
#include "../Datasets/Nombres.hpp"

using namespace std; 
using namespace Datasets;

class Alumno {
	string nombre;
	int grado;
	bool genero;
public:
	Alumno() 
	{
		auto rng = [](int a, int b) {return a + rand() % b; };
		this->nombre += nombresArr[rng(0, NOMBRES_LEN)] + " "  + nombresArr[rng(0, NOMBRES_LEN)]; 
		this->nombre += " "; 
		this->nombre += apellidosArr[rng(0, APELLIDOS_LEN)] + " " + apellidosArr[rng(0, APELLIDOS_LEN)];

		this->grado = rng(1, 6);

		if (rng(0, 2) == 1) {
			this->genero = true;
		}
		else {
			this->genero = false;
		}
	}

	string getName(){
		return this->nombre;
	}

	int getGrade(){
		return this->grado;
	}

	bool getGender(){
		return this->genero;
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
		str += "\n";
		return str;
	}

	void mostrarnombre(){
		cout << endl << nombre;
	}
};

#endif // !ALUMNO_HPP