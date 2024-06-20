#include <iostream>
#include <functional>
using namespace std;

template <typename T>
class Nodo{
    Nodo*der, izq;
    T elem;

	//Nodo(T dato) : elem:(dato),  izquierda(nullptr), derecha(nullptr) {}
};


template <typename T>
class ArbolBinario{
    Nodo<T>* raiz; void(*pointer)(T);
    private:
    bool _insertar(Nodo<T>* nodo, T elem){
        if (nodo == nullptr){
           nodo = new Nodo<T>();
           nodo->elem = e; 
        }

        else if(elem < nodo->elem) return _insertar(nodo->izq,elem);
        else if(elem > nodo->elem) return _insertar(nodo->der,elem);
    }

    void enOrden(Nodo<T>* raiz){
        if (raiz == nullptr) return;
        _enOrden(raiz->izq);
        procesar(raiz->elem);
        _enOrden(raiz->der);
    }

    void _postOrden(Nodo<T>* raiz){
        if (raiz == nullptr) return;
        procesar(raiz->elem);
        _postOrden(raiz->izq);
        _postOrden(raiz->der);
    }

    void _preOrden(Nodo<T>* raiz){
        if (raiz == nullptr) return;
        _preOrden(raiz->izq);
        _preOrden(raiz->der);
        procesar(raiz->elem);
    }

    bool vacio(){
        return raiz == nullptr;
    }

	int _cantidad(Nodo<T>* nodo) {
		//La cantidad de nodos del árbol es:
		//	0 si es vacío
		//	1 + la cantidad de nodos por la izquierda + la cantidad de nodos por la derecha

		if (nodo==nullptr)
			return 0;
		else
		{
			int ci, cd;
			ci = _cantidad(nodo->izq);
			cd = _cantidad(nodo->der);
			return 1 + ci + cd;
		}

	}
	int _altura(Nodo<T>* nodo) {
		//La altura del árbol es:
		//	0 si es vacío
		//	la mayor de las alturas por la izquierda y por la derecha, las cuáles son 0 si son vacías ó 1 + la altura por la izq(o der) en caso contrario

		if (nodo==nullptr)
			return 0;
		else
		{
			int ai, ad;
			ai = 1 + _altura(nodo->izq);
			ad = 1 + _altura(nodo->der);
			return ai > ad ? ai : ad;			
		}
	}
public:

ArbolBinario(void(*puntero)(T)){
    this->pointer = puntero;
    this->raiz = nullptr;
}

	bool insertar(T e) {
		return _insertar(raiz, e);
	}

	void enOrden() {
		_enOrden(raiz);
	}

	void preOrden() {
		_preOrden(raiz);
	}

	void postOrden() {
		_postOrden(raiz);
	}

	int cantidad() {
		return _cantidad(raiz);
	}

	int altura() {
		return _altura(raiz);
	}
    
};
