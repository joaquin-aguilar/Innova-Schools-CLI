#pragma once
#include <iostream>
using namespace std;

template<class T>
class Nodo {
public:
	Nodo<T>* siguiente;
	T dato;

	Nodo(T data, Nodo<T>* _siguiente = nullptr) {
		this->dato = data;
		this->siguiente = _siguiente;
	}
};