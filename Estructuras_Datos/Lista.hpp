#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>
#include "Nodo.hpp"
#include <functional>
#include <vector>
#include <string>

using namespace std;

template<class T>
class Lista 
{
private:
	Nodo<T>* ini;
	int tamano;
public:
	Lista() 
	{
		ini = nullptr;
		tamano = 0;
	}

	~Lista()
	{
		Nodo<T>* aux = ini;
		while (aux != nullptr) {
			Nodo<T>* temporal = aux;
			aux = aux->siguiente;
			delete temporal;
		}
	}

	// Big O #1
	void AnadirIni(T dato) {
	Nodo<T>* nuevo = new Nodo<T>(dato, ini); //O(1): Asignación a la memoria
		if (nuevo != nullptr) { //O(1): Verificación de condición
			ini = nuevo; //O(1): Asignación de puntero ini a nuevo
			tamano++; //O(1): Incremento por 1 de variable longit
		}
	}

//Big O #7
void AgregarMultiple(T data, int veces) {
    if (veces == 0) {                      // O(1): Se verifica la condicional, la cual es ver si el int veces es igual a 0
	//A clockwork Orange
    }
    else {
        Nodo<T>* nuevo = new Nodo<T>(data, ini); // O(1):Inicialización de nodo y asignación de memoria
        ini = nuevo;                          // O(1): Asignación de valor del puntero ini
        tamano++;                             // O(1): Incremento de la variable tamano por 1 unidad
        AgregarMultiple(data, veces - 1);     // O(m): Revursividad de la funcion AgregarMultiple, la cual resta a la variable veces por 1
    }
}


	void AnadirFin(T dato) 
	{
		Nodo<T>* nuevo = new Nodo<T>(dato);

		if (ini == nullptr)
		{
			ini = nuevo;
			tamano++;
			return;
		}
		Nodo<T>* actual = ini;
		while (actual->siguiente != nullptr)
		{
			actual = actual->siguiente;
		}
		actual->siguiente = nuevo;
		actual = nullptr;
		tamano++;
	}

	int longitud() {
		return tamano;
	}

	// Big O #2
	std::vector<std::string> Mostrar() 
	{
		std::vector<std::string> texto;
		Nodo<T>* current = ini; // O(1): Se inicializa el puntero current
		int contador = 0;

		texto.push_back(std::string("Lista de Alumnos:\n"));
		while (current != nullptr) 
		{  // O(n): Bucle que se repite hasta que ya no haya una siguiente direccion en el puntero (nullptr)
			char buffer[150];
			sprintf(buffer, "%4i -> %s", contador, current->dato->mostrar().c_str());
			texto.push_back(std::string(buffer));
			current = current->siguiente; // O(1): Se avanza a la siguiente direccion con datos 
			contador++;
		}
		return texto;
	}

	void mostrardato(){
		Nodo<T>* current = ini;
		
		while (current != nullptr){
			current->dato->mostrarnombre();
			current = current->siguiente;
		}
	}

	int getGradoAlumno(string dato){
		Nodo<T>* current = ini;

		while (current != nullptr){
			if (dato == current->dato->getName()){
				return current->dato->getGrade();
			}
		}
		return 0;
	}

	bool getGenderAlumno(string dato){
		Nodo<T>* current = ini;
		while (current != nullptr){
			if (dato == current->dato->getName()){
				return current->dato->getGender();
			}
		}
		return false;
	}

	bool existe(string dato){
		Nodo<T>* current = ini;
		while (current != nullptr){
			if (dato == current->dato->getName()){
				return true;
			}
		}
		return false;
	
	}
	Nodo<T>* raiz()
	{
		return ini;
	}
};
#endif // !LISTA_HPP
