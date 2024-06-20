#ifndef PARSERS_HPP
#define PARSERS_HPP


#include <curses.h>
#include <string>
#include <cstring>
#include "../Estructuras_Datos/Cola.hpp"
#include "../Estructuras_Datos/Pila.hpp"
#include "../Modelos/Alumno.hpp"
#include "../Modelos/Deportista.hpp"
#include "../Modelos/Destacado.hpp"

using namespace std;

auto mostrarColaAlumno = [] (Cola<Destacado*>& _cola)
{
	Cola<Destacado*> cola_cpy = _cola.copiarCola();
	int contador = 0;

	printw("Cola de Destacados:\n");
	refresh();
	while (!cola_cpy.estaVacia())
	{
		printw("%i -> %s", contador, cola_cpy.pop()->mostrar().c_str());
		refresh();
		contador++;
	}
};
auto colaToStrings = [] (Cola<Destacado*>& _cola)
{
	vector<string> texto;
	Cola<Destacado*> cola_cpy = _cola.copiarCola();
	int contador = 0;

	texto.push_back("Cola de Destacados:\n");
	while (!cola_cpy.estaVacia())
	{
		char buffer[150];
		sprintf(buffer,"%4i -> %s", contador, cola_cpy.pop()->mostrar().c_str());
		texto.push_back(string(buffer));
		contador++;
	}
	return texto;
};

auto mostrarPilaAlumno = [](Pila<Deportista*>& _pila)
{
	Pila<Deportista*> pila_cpy = _pila.copiarPila();
	int contador = 0;

	printw("Pila de Deportistas:\n");
	refresh();
	while (!pila_cpy.estaVacia())
	{
		printw("%i -> %s", contador, pila_cpy.pop()->mostrar().c_str());
		refresh();
		contador++;
	}
};

auto pilaToStrings = [](Pila<Deportista*>& _pila)
{
	vector<string> texto;
	Pila<Deportista*> pila_cpy = _pila.copiarPila();
	int contador = 0;

	texto.push_back(string("Pila de Deportistas:\n"));
	while (!pila_cpy.estaVacia())
	{
		char buffer[150];
		sprintf(buffer,"%4i -> %s", contador, pila_cpy.pop()->mostrar().c_str());
		texto.push_back(string(buffer));
		contador++;
	}
	return texto;
};

#endif // !PARSERS_HPP