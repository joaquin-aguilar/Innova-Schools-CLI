#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <iostream>
#include <string>
#include "HashEntity.hpp"
#include "../Utilidades/Nombres.hpp"

using namespace std;

class HashTable {

	HashEntity** entity;
	int _cantidadElementos;
	int _tamanoTabla;

public:

	HashTable(int tamanoTablad = 120) 
	{ //experimentar con el tamano
		this->_tamanoTabla = tamanoTablad;
		entity = new HashEntity * [_tamanoTabla];
		for (int i = 0; i < tamanoTablad; i++) {
			entity[i] = nullptr;
		}
		_cantidadElementos = 0;
	}

	~HashTable() {
		for (int i = 0; i < _tamanoTabla; ++i) {
			if (entity[i] != nullptr) {
				delete entity[i];
			}
		}
		delete[] entity;
	}

	//Big O #5
	void insertar(int key, string valor) {
		// Hash prima
		int base = 0, step = 0, hash = 0;  // O(1): Se declaran e inicializan variables de tipo enteras

		if (_cantidadElementos == _tamanoTabla) { // O(1): Se verifica si hay espacio disponible en la tabla
			return; // O(1): Retorna nada si no hay espacio disponible.
		}

		base = key % _tamanoTabla; // O(1): Se calcula base
		hash = base; // O(1): Se le da el valor de vase a Hash


		while (entity[hash] != nullptr) {  // O(n): Bucle que recorre tabla de Hash
			hash = (base + step) % _tamanoTabla; // O(1): Recalculo del valor de hash
			step++; // O(1): Step incrementa por 1
		}

		// Almacenar en la tabla
		entity[hash] = new HashEntity(key, valor);   // O(1): Asignación de memoria en HashEntity con las llabes y el valor
		_cantidadElementos++;  // O(1): Incrementa cantidadElementos por 1
	}

	int tamanoTabla() {
		return _tamanoTabla;
	}

	int tamanoActual() {
		return _cantidadElementos;
	}

	//Big O #6
	string buscar(int key) {
		int step = 0, i = 0, base = 0; // O(1): Inicialización y declaración de variables de tipo int
		 
		i = base = key % _tamanoTabla; // O(1): Calculo del valor de las variables i y base
		while (true) {// O(n): Bucle infinito 
			if (entity[i] == nullptr) return "-1"; //O(2): Verificación de condicional y retorno de -1 en caso de no encontrar un valor key
			else if (entity[i]->getKey() == key) { // O(1): Comparación entre llave registrada y llave insertada
				return entity[i]->getValue();  // O(1): Se retorna el valor que este asociado con el valor de la llave
			}
			else step++; //O(1): Incremento de step por 1
			i = (base + step) % _tamanoTabla; // O(1): Recalculo de la variable i
		}
	}

	//Big O #7
	std::string Imprimir(int* keys) 
	{
		std::string str;
		str += "\nCantidad de administradores: ";
		str += to_string(tamanoActual()); // O(1): Llamada a función y operación de salida
		str+= "\n"; 
		for (int i = 0; i < tamanoActual(); i++) // O(n): Bucle que itera `n` veces, donde `n` es el tamaño actual
		{ 	//O(1) + O(buscar): Llamada a función de búsqueda y operación de salida
			str += "Nombre:  "; 
			str += buscar(keys[i]);
			str += ", Llave:  ";
			str +=  to_string(keys[i]);
			str += "\n"; 
		}
		return str;
	}

};

#endif // !HASH_TABLE_HPP