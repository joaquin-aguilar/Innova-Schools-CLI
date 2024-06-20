#ifndef PILA_HPP
#define PILA_HPP

#include <string>
#include "Nodo.hpp"

template <class T>
class Pila
{
private:
    Nodo<T>* tope;
public:
    Pila() 
    {
        tope = nullptr;
    }
    ~Pila() {
        while (!estaVacia())
        {
            pop();
        }
    }

    int size() {
        Nodo<T>* actual = tope;
        int indice = 0;
        if (estaVacia())
            return indice;

        while (actual != nullptr)
        {
            indice++;
            actual = actual->siguiente;
        }

        return indice;
    }

    bool estaVacia() {
        return tope == nullptr;
    }

    void push(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);

        if (estaVacia())
            tope = nuevo;
        else
        {
            Nodo<T>* actual = tope;
            tope = nuevo;
            tope->siguiente = actual;
        }
    }

    T pop() {
        if (estaVacia())
            throw std::out_of_range("La pila est� vacia");

        T dato = tope->dato;
        Nodo<T>* actual = tope;
        tope = tope->siguiente;
        delete actual;

        return dato;
    }

    T& front()
    {
        Nodo<T>* actual = tope;
        while (actual->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }
        return actual->dato;
    }

    T& back()
    {
        return this->tope->dato;
    }
    Pila<T> copiarPila()
    {
        Pila<T> nuevaPila;
        Pila<T> pilaAux;
        Nodo<T>* actual = tope;
        
        while (actual != nullptr)
        {
            pilaAux.push(actual->dato);
            actual = actual->siguiente;
        }

        actual = nullptr;

        while (!pilaAux.estaVacia())
        {
            nuevaPila.push(pilaAux.pop());
        }

        return nuevaPila;
    }
};
#endif // !PILA_HPP